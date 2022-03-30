#ifndef __ITERATOR_HPP__
# define __ITERATOR_HPP__

namespace ft {
    template< class Iter >
    struct iterator_traits
    {
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::value_type value_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    template< class T >
    struct iterator_traits< T* >
    {
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template< class T >
    struct iterator_traits< const T* >
    {
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

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