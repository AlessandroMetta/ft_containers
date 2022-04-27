#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include <memory>
#include <limits>
#include <stdexcept>
#include <iostream>

#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template< typename T >
	class vector_iterator
	{
	public:
		typedef	T															iterator_type;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef	typename iterator_traits<iterator_type>::pointer			pointer;
		typedef	typename iterator_traits<iterator_type>::reference			reference;
		typedef	typename iterator_traits<iterator_type>::difference_type	difference_type;

		//	it()
		vector_iterator () : ptr( NULL ) {};

		//	it(ptr)
		explicit vector_iterator ( pointer ptr ) : ptr( ptr ) {};

		//	it1(it2)
		template<class Other_Iter>
		vector_iterator ( const vector_iterator<Other_Iter>& other ) 
		{
			*this = other;
		};

		~vector_iterator(){};

		//	it1 = it2
		vector_iterator& operator= ( const vector_iterator& x )
		{
			ptr = x.ptr;
			return *this;
		};

		//	it1 == it2
		bool operator==(  const vector_iterator& rhs ) const
		{
			return ptr == rhs.ptr;
		};

		//	it1 != it2
		bool operator!= ( const vector_iterator& rhs ) const
		{
			return ptr != rhs.ptr;
		};

		//	it->
		pointer operator-> () const
		{
			return ptr;
		};

		//	*it
		reference operator* () const
		{
			return *ptr;
		};

		//	it++
		vector_iterator& operator++ () 
		{
			ptr++;
			return *this;
		};

		//	++it
		vector_iterator operator++ ( int ) 
		{
			vector_iterator tmp = *this;
			ptr++;
			return tmp;
		};

		//	it += n
		vector_iterator& operator+= ( difference_type n )
		{
			ptr += n;
			return *this;
		};

		//	it--
		vector_iterator& operator-- ()
		{
			ptr--;
			return *this;
		};

		//	--it
		vector_iterator operator-- ( int )
		{
			vector_iterator tmp = *this;
			ptr--;
			return tmp;
		};

		//	it -= n
		vector_iterator& operator-= ( difference_type n )
		{
			ptr -= n;
			return *this;
		};
		
		//	n + it
		vector_iterator operator+ ( const int n ) const
		{
			return vector_iterator(ptr + n);
		};

		// it + n
		friend vector_iterator operator+ ( int n, vector_iterator it )
		{
			return vector_iterator(it.ptr + n);
		};

		//	it - n
		vector_iterator operator- ( const difference_type& n ) const
		{
			return vector_iterator(ptr - n);
		};

		//	it1 - it2
		difference_type operator- ( const vector_iterator& rhs ) const
		{
			return ptr - rhs.ptr;
		};

		// comparison operator
		bool operator> ( const vector_iterator& rhs ) const
		{
			return ptr > rhs.ptr;
		};

		bool operator< ( const vector_iterator& rhs ) const
		{
			return ptr < rhs.ptr;
		};

		bool operator>= ( const vector_iterator& rhs ) const
		{
			return ptr >= rhs.ptr;
		};

		bool operator<= ( const vector_iterator& rhs ) const
		{
			return ptr <= rhs.ptr;
		};

		//	deference offset iterator
		reference operator[] ( const difference_type n ) const
		{
			return ptr[ n ];
		};

	private:
		pointer ptr;
	};

	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef	Allocator								allocator_type;
		typedef	std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;
		typedef	T										value_type;
		typedef	T*										pointer;
		typedef	const T*								const_pointer;
		typedef	T&										reference;
		typedef	const T&								const_reference;
		typedef	ft::vector_iterator<pointer>			iterator;
		typedef	ft::vector_iterator<const_pointer>		const_iterator;
		typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	public:
		// default constructor: vector()
		explicit vector (const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _capacity(0), _size(0), _data(NULL)
		{
			_data = _alloc.allocate( 0 );
		};

		// fill constructor: vector ( size , value )
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(n), _size(n), _data(_alloc.allocate(n))
		{
			size_type i = -1;
			while ( ++i < n )
				_alloc.construct( _data + i, val );
		};

		private:
		template <class InputIterator>
		size_type distance(InputIterator first, InputIterator last)
		{
			size_type len = 0;
			InputIterator it = first;
			while ( it++ != last )
				len++;
			return len;
		}

		public:
		// range (inizialized_ constructor: vactor ( first , last )
		template <class InputIterator>
        	vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				int>::type* = 0	)
				: _alloc(alloc), _capacity(distance(first, last)), _size(_capacity), _data(NULL)
		{
			if (_capacity)
				_data = _alloc.allocate(_capacity);
			size_type i = -1;
			while (++i < _size)
			{
				_alloc.construct(_data + i, *first);
				first++;
			}
		};

		// copy constructor: vector ( vector2 )
		vector( const vector& other )
		: _alloc(other._alloc), _capacity(other._capacity), _size(other._size), _data(NULL) {
			if (_capacity)
				_data = _alloc.allocate(_capacity);
			size_type i = -1;
			while (++i < _size)
				_alloc.construct(_data + i, *(other._data + i));
		};

		// Destructor
		~vector()
		{
			for (size_type i = 0; i < _capacity; i++)
				_alloc.destroy(_data + i);
			if (_capacity)
				_alloc.deallocate(_data, _capacity);
		};

		vector & operator=(const vector& x)
		{
			for (size_type i = 0; i < _capacity; i++)
				_alloc.destroy(_data + i);
			if (_capacity)
				_alloc.deallocate(_data, _capacity);
			_alloc = x._alloc;
			_size = x._size;
			_capacity = x._capacity;
			if (_capacity)
				_data = _alloc.allocate(_capacity);
			size_type i = -1;
			while (++i < _size)
				_alloc.construct(_data + i, *(x._data + i));
			return *this;
		};

		//  CAPACITY
		size_type size () const
		{
			return _size;
		};

		size_type max_size () const
		{
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		};
		
		void resize( size_type count, value_type value = value_type() )
		{
			if (_size > count)
				_size = count;
			else
			{
				for (size_type i = 0; i < _capacity; i++)
					_alloc.destroy(_data + i);
				if (_capacity)
					_alloc.deallocate(_data, _capacity);
				_size = count;
				_capacity = count;
				if (_capacity)
					_data = _alloc.allocate(_capacity);
				size_type i = -1;
				while (++i < _size)
					_alloc.construct(_data + i, value);
			}
		};

		size_type capacity () const
		{
			return _capacity;
		};

		bool empty() const
		{
			return _size == 0;
		};

		void reserve (size_type n)
		{
			if (n > _capacity)
			{
				pointer tmp = _alloc.allocate( n );
				for (size_type i = 0; i < _capacity; i++)
					tmp[i] = _data[i];
				for (size_type i = 0; i < _capacity; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _capacity);
				_capacity = n;
				_data = tmp;
			}
		};

		// ITERATORS FUNCTION
		iterator begin()
		{
			return iterator( &_data[0] );
		};

		const_iterator begin() const
		{
			return const_iterator( &_data[0] );
		};

		iterator end()
		{
			return iterator( &_data[size()] );
		};

		const_iterator end() const
		{
			return const_iterator( &_data[size()] );
		};

		reverse_iterator rbegin()
		{
			return reverse_iterator( end() );
		};

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator( end() );
		};

		reverse_iterator rend()
		{
			return reverse_iterator( begin() );
		};

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator( begin() );
		};

		// ELEMENT ACCESS
		reference operator[](size_type n)
		{
			return _data[n];
		};
		const_reference operator[](size_type n) const
		{
			return _data[n];
		};

		reference at(size_type n)
		{
			if ( n >= _size )
				throw std::out_of_range("vector");
			return _data[n];
		};

		const_reference at(size_type n) const
		{
			if ( n >= _size )
				throw std::out_of_range("vector");
			return _data[n];
		};

		reference front()
		{
			return _data[0];
		};

		const_reference front() const
		{
			return _data[0];
		};

		reference back()
		{
			return _data[_size - 1];
		};

		const_reference back() const
		{
			return _data[_size - 1];
		};

		// ALLOCATOR
		allocator_type get_allocator () const
		{
			return _alloc;
		};
		
		// MODIFIERS
		template <class InputIterator>
 		void assign (
			InputIterator first,
			InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
			int>::type* = 0	)
		{
			size_type i = 0;
			clear();
			for(InputIterator it = first; it != last; it++)
				i++;
			if ( _capacity < i )
			{
				for (size_type i = 0; i < _capacity; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _capacity);
				_data = _alloc.allocate( i );
				_capacity = i;
			}
			insert(begin(), first, last);
		};

		void assign (size_type n, const value_type& val)
		{
			if (n <= _capacity)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				for (size_type i = 0; i < n; i++)
					_alloc.construct( &_data[i] , val );
			}
			else
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _size);
				_capacity = n;
				_size = n;
				_data = _alloc.allocate( n );
				for (size_t i = 0; i < _capacity; i++)
					_alloc.construct( &_data[i] , val );
			}
		};

		void push_back(value_type value)
		{
			if (_size + 1 > _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			_alloc.construct( &_data[size()] , value );
			_size++;
		};

		void pop_back()
		{
			if (!this->empty())
				_alloc.destroy(_data + _size--); 
		};

		iterator	insert (iterator position, const value_type& val)
		{
			size_type pos_index = 0;

			if (position > end()) throw std::out_of_range("out of range");
			for (iterator it = begin(); it + pos_index != position && pos_index < _size; pos_index++) ;
			if (_size + 1 > _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			for (size_type i = _size; i > pos_index; i--)
				_data[i] = _data[i - 1];
			_alloc.construct( &_data[pos_index] , val );
			_size++;

			return iterator(&_data[pos_index]);                
		};

		void	insert (iterator position, size_type n, const value_type& val)
		{
			while (n--)
				position = insert(position, val);
		};

		template <class InputIterator>
    		void insert (
				iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				int>::type* = 0	)
		{
			for ( ; first != last; ++first)
				position = insert(position, *first) + 1;
		};

		iterator erase (iterator position)
		{
			for (iterator it = position; it + 1 != end(); ++it)
				*it = *(it + 1);
			_size--;
			return position;
		};

		iterator erase (iterator first, iterator last)
		{
			for ( ; first != last ; --last)
				erase (first);
			return first;
		};

		void swap (vector& other)
		{
			ft::swapContent(_data, other._data);
			ft::swapContent(_size, other._size);
			ft::swapContent(_capacity, other._capacity);
			ft::swapContent(_alloc, other._alloc);
		};

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_data + i);
			_size = 0;
		};

	private:
		allocator_type	_alloc;
		size_type		_capacity;
		size_type		_size;
		pointer			_data;
	};

	// NON-MEMBER FUNCTION

	template< class T, class Alloc >
	bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template< class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),rhs.begin(), rhs.end());
	}

	template< class T, class Alloc >
	bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}
 
	template< class T, class Alloc >
	bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return rhs < lhs;
	}

	template< class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
}

#endif
