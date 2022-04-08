#ifndef __MAP_HPP__
# define __MAP_HPP__

#include "RBTree.hpp"

namespace ft {

template < class Key,
			class T,
			class Compare = std::less< Key >,
			class Alloc = std::allocator< ft::pair< const Key, T > >
			> class map
{
	public:

	typedef	Key								key_type;
	typedef	T								mapped_type;
	typedef typename Alloc::value_type		value_type;
	typedef	Compare							key_compare;
	
	class value_compare : std::binary_function<value_type, value_type, bool>
	{
		friend class map;
	protected:
		key_compare comp;

		value_compare(key_compare c): comp(c){};
	public:
		bool operator()(const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};
	
	typedef ft::RBTree< key_type, value_type, value_compare > tree_t;
	typedef typename tree_t::iterator iterator;

	explicit map( const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : tree(tree_t(value_compare(key_comp()))), comp(comp), alloc(alloc) {};

	void print()
	{
		tree.print();
	}

	iterator begin()
	{
		return tree.begin();
	}

	iterator end()
	{
		return tree.end();
	}

	ft::pair<iterator, bool> insert(value_type pair)
	{
		return tree.insertion(pair);
	}

	void erase(key_type value)
	{
		return tree.deletion(ft::make_pair(value, mapped_type()));
	}

	key_compare key_comp() const
	{
		return Compare();
	};

	value_compare value_comp() const
	{
		return key_comp();
	};

	private:
		tree_t	tree;
		Compare	comp;
		Alloc	alloc;
};

}

#endif