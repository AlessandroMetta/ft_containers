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

    typedef Key value_type;
    typedef Compare key_compare;

    class value_compare(): std::binary_function<value_type, value_type, bool>
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

    key_compare key_comp() const
    {
        return Compare();
    };

    value_compare value_comp() const
    {
        return key_comp();
    };
   
    private:
        ft::RBTree<value_type, value_type, value_compare> tree;
};

}
#endif