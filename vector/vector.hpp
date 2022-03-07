#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include <memory>
#include <iostream>

namespace ft
{
    template< class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef Allocator   allocator_type;
            typedef std::size_t   size_type;
            typedef std::ptrdiff_t   difference_type;
            typedef T   value_type;
            typedef T*   pointer;
            typedef const T*   const_pointer;
            typedef T&   reference;
            typedef const T&   const_reference;
            // typedef T*   iterator;
            // typedef const T*   const_iterator;
            // typedef std::reverse_iterator<iterator>   reverse_iterator;
            // typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;
        private:
            pointer _data;
            allocator_type _alloc;
            size_type _capacity;
            size_type _size;
        public:
            // Constructs an empty container with the given allocator alloc
            explicit vector( const allocator_type& alloc = allocator_type() )
            : _data(0), _alloc(alloc), _capacity(0), _size(0)
            {
                _data = _alloc.allocate( 0 );
            };

            // Constructs the container with count copies of elements with value value
            explicit vector( size_type count,
                const value_type& value = value_type(),
                const allocator_type& alloc = allocator_type())
                : _data(0), _alloc(alloc), _capacity(0), _size(0)
            {
                _data = _alloc.allocate( 0 );
                while (count--)
                {
                    if (_size + 1 > _capacity)
                        reserve(_capacity == 0 ? 1 : _capacity * 2);
                    _data[_size] = value;
                    _size++;
                }
            };

            // Constructs the container with the contents of the range [first, last).
            // template< class InputIt >
            // vector( InputIt first, InputIt last,
            //     const Allocator& alloc = Allocator() )
            // {
            //     _data = alloc.allocate( _sizeof(T) ) ;
            // };

            // Copy constructor
            vector( const vector& other )
            : _data(0), _alloc(other._alloc), _capacity(0), _size(0)
            {
                this->operator=(other);
            };

            // Destructor
            ~vector() { _alloc.deallocate(_data, _capacity); };

            vector & operator=(const vector& x)
            {
                if (_data != 0) _alloc.deallocate(_data, _size);
                _alloc = x._alloc;
                _capacity = x._capacity;
                _size = x._size;
                _data = _alloc.allocate( _capacity );
                for (size_t i = 0; i < x._size; i++)
                    _data[i] = x[i];
                return *this;
            };

            //  CAPACITY
            size_type size () const { return _size; };
            size_type max_size () const { return std::numeric_limits<size_type>::max() / sizeof(value_type); };
            void resize (size_type n, value_type val = value_type())
            {
                pointer tmp;
                if (n > _size)
                {
                    tmp = _alloc.allocate( n );
                    for (size_type i = 0; i < _size; i++)
                        tmp[i] = _data[i];
                    for (size_type i = _size; i < n; i++)
                        tmp[i] = val;
                }
                else
                {
                    tmp = _alloc.allocate( _capacity );
                    for (size_type i = 0; i < n; i++)
                        tmp[i] = _data[i];
                }
                _alloc.deallocate(_data, _capacity);
                _size = n;
                _data = tmp;
            };
            size_type capacity () const { return _capacity; };
            bool empty() const { return _size == 0;};
            void reserve (size_type n)
            {
                if (n > _capacity)
                {
                    pointer tmp = _alloc.allocate( n );
                    for (size_type i = 0; i < _capacity; i++)
                        tmp[i] = _data[i];
                    _alloc.deallocate(_data, _capacity);
                    _capacity = n;
                    _data = tmp;
                }
            };

            // ELEMENT ACCESS
            reference operator[](size_type n){ return _data[n]; };
            const_reference operator[](size_type n) const { return _data[n]; };
            reference at(size_type n){ return _data[n]; };
            const_reference at(size_type n) const { return _data[n]; };
            reference front(){ return _data[0]; };
            const_reference front() const { return _data[0]; };
            reference back(){ return _data[_size - 1]; };
            const_reference back() const { return _data[_size - 1]; };


            // ALLOCATOR
            allocator_type get_allocator () const { return _alloc; };

            // MODIFIERS
            void push_back(value_type value)
            {
                if (_size + 1 > _capacity)
                    reserve(_capacity == 0 ? 1 : _capacity * 2);
                _data[_size] = value;
                _size++;
            };
            /*
            template <class InputIterator>
                void assign (InputIterator first, InputIterator last);
            */

            void assign (size_type n, const value_type& val)
            {
                if (n <= _capacity)
                {
                    for (size_type i = 0; i < _size; i++)
                        _alloc.destroy(_data + i);
                    for (size_type i = 0; i < n; i++)
                        _data[i] = val;
                }
                else
                {
                    _alloc.deallocate(_data, _size);
                    _capacity = n;
                    _size = n;
                    _data = _alloc.allocate( _capacity );
                    for (size_t i = 0; i < _capacity; i++)
                        _data[i] = val;
                }
            };

            void pop_back()
            {
                if (!this->empty())
                   _alloc.destroy(_data + _size--); 
            };

            void swap (vector& x)
            {
                vector tmp = x;
                x = *this;
                *this = tmp;
            };

            void clear()
            {
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(_data + i);
                _size = 0;
            };
    };

    // NON-MEMBER FUNCTION

    template< class T, class Alloc >
    bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

    template< class T, class Alloc >
    void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs ) { lhs.swap(rhs); }
}

#endif
