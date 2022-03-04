#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include <memory>

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
            pointer Data;
            allocator_type _alloc;
            size_type Capacity;
            size_type Size;
        public:
            // Constructs an empty container with the given allocator alloc
            explicit vector( const allocator_type& alloc = allocator_type() ) 
            : Data(0), _alloc(alloc), Capacity(0), Size(0)
            {
                Data = _alloc.allocate( 0 );
            };

            // Constructs the container with count copies of elements with value value
            explicit vector( size_type count,
                 const value_type& value = value_type(),
                 const allocator_type& alloc = allocator_type())
                 : Data(0), _alloc(alloc), Capacity(0), Size(0)
            {
                Data = _alloc.allocate( 0 );
                while (count--)
                {
                    if (Size + 1 > Capacity)
                        reserve(Capacity == 0 ? 1 : Capacity * 2);
                    Data[Size] = value;
                    Size++;
                }
            };

            // Constructs the container with the contents of the range [first, last).
            // template< class InputIt >
            // vector( InputIt first, InputIt last,
            //     const Allocator& alloc = Allocator() )
            // {
            //     Data = alloc.allocate( sizeof(T) ) ;
            // };

            // Copy constructor
            vector( const vector& other )
            : Data(0), Capacity(0), Size(0)
            {
                this->operator=(other);
            };

            // Destructor
            ~vector() { _alloc.deallocate(Data, Capacity); };

            vector & operator=(const vector& other)
            {
                _alloc = other._alloc;
                Data = _alloc.allocate( 0 );
                for (size_t i = 0; i < other.Size; i++)
                {
                    if (Size + 1 > Capacity)
                        reserve(Capacity == 0 ? 1 : Capacity * 2);
                    Data[i] = other[i];
                    Size++;
                }
                return *this;
            }

            reference operator[](size_type i){ return Data[i]; }
            const_reference operator[](size_type i) const { return Data[i]; }
            size_type size () const { return Size; }

            void reserve (size_type new_Capacity)
            {
                std::cout << "--- old capacity = " << Capacity << ", new capacity = " << new_Capacity << std::endl;
                if (new_Capacity > Capacity)
                {
                    pointer tmp = _alloc.allocate( new_Capacity );
                    for (size_type i = 0; i < Capacity; i++)
                        tmp[i] = Data[i];
                    _alloc.deallocate(Data, Capacity);
                    Capacity = new_Capacity;
                    Data = tmp;
                }
            }

            void push_back(value_type value)
            {
                if (Size + 1 > Capacity)
                    reserve(Capacity == 0 ? 1 : Capacity * 2);
                Data[Size] = value;
                Size++;
            }
    };
}

#endif
