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
	
	//da rivedere
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
	typedef typename ft::RBTree<key_type, value_type, key_compare >::iterator iterator;
    
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
        return tree.deletion(ft::pair< key_type, mapped_type >(value, mapped_type()));
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
        ft::RBTree<key_type, value_type, key_compare > tree;
};

}

#endif