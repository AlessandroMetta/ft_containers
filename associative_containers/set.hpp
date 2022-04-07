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

    class value_compare : std::binary_function<value_type, value_type, bool>
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
    typedef typename ft::RBTree<key_type, value_type, key_compare >::iterator iterator;

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
        ft::RBTree<key_type, value_type, key_compare > tree;
};

}
#endif