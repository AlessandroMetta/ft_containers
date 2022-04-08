#ifndef __SET_HPP__
# define __SET_HPP__

#include "RBTree.hpp"

namespace ft {

template < class Key,
			class Compare = std::less< Key >,
			class Alloc = std::allocator< Key >
			> class set
{
	public:

	typedef Key key_type;
	typedef Key value_type;
	typedef Compare key_compare;

	class value_compare : std::binary_function<key_type, value_type, bool>
	{
		friend class set;
	protected:
		key_compare comp;

		value_compare(key_compare c) : comp(c) {};
	public:
		bool operator()(const value_type& x, const value_type& y) const
		{
			return comp(x, y);
		}
	};

	typedef ft::RBTree<key_type, value_type, value_compare> tree_t;
	typedef typename tree_t::iterator iterator;

	explicit set( const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : tree(tree_t(value_compare(key_comp()))), comp(comp), alloc(alloc) {};


	iterator begin()
	{
		return tree.begin();
	}

	iterator end()
	{
		return tree.end();
	}

	ft::pair<iterator, bool> insert(Key value)
	{
		return tree.insertion(value);
	}

	void erase(Key value)
	{
		return tree.deletion(value);
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
		tree_t tree;
		key_compare comp;
		Alloc alloc;
};

}
#endif