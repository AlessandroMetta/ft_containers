#ifndef __ITERATOR_HPP__
# define __ITERATOR_HPP__

#include "iterator_traits.hpp"

namespace ft
{
    template< class Iter >
    class reverse_iterator
    {
    public:
        typedef Iter iterator_type;
        typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iter>::value_type value_type;
        typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iter>::pointer pointer;
        typedef typename ft::iterator_traits<Iter>::reference reference;

        reverse_iterator() : base_iterator() {};
        explicit reverse_iterator( iterator_type x ) : base_iterator( x ) {};
        template< class U > 
            reverse_iterator( const reverse_iterator<U>& other )
            : base_iterator( x.base() ) {};

        iterator_type base() const { return base_iterator; };

        reference operator*() const { Iter tmp = current; return (*(--tmp)); };
        pointer operator->() const { return std::addressof(operator*()); };

    private:
        iterator_type base_iterator;
    };
}

#endif