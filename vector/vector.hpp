#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include <memory>
#include <limits>
#include <stdexcept>
#include <iostream>

// #include "../iterator.hpp"

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
		typedef ft::vector_iterator<T>   iterator;
		typedef ft::const_vector_iterator<T>   const_iterator;
		typedef ft::reverse_vector_iterator<T>   reverse_iterator;
		typedef ft::const_reverse_vector_iterator<T>   const_reverse_iterator;
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
			assign(count, value);
		};

		// Constructs the container with the contents of the range [first, last).
		template< class InputIt >
		vector( InputIt first, InputIt last,
			const Allocator& alloc = Allocator() ) 
			: _data(0), _alloc(alloc), _capacity(0), _size(0)
		{
			_data = _alloc.allocate(0);
			assign(first, last);
		};

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
			_alloc = x._alloc;
			assign(x.begin(), x.end());
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

		// ITERATORS FUNCTION
		iterator begin() { return iterator(_data); };
		const_iterator begin() const { return const_iterator(_data); };
		iterator end(){ return iterator(_data + _size); };
		const_iterator end() const { return const_iterator(_data + _size); };
		reverse_iterator rbegin(){ return reverse_iterator(_data); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(_data); };
		reverse_iterator rend(){ return reverse_iterator(_data + _size); };
		const_reverse_iterator rend() const { return const_reverse_iterator(_data + _size); };

		// ELEMENT ACCESS
		reference operator[](size_type n){ return _data[n]; };
		const_reference operator[](size_type n) const { return _data[n]; };
		reference at(size_type n){
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
		reference front(){ return _data[0]; };
		const_reference front() const { return _data[0]; };
		reference back(){ return _data[_size - 1]; };
		const_reference back() const { return _data[_size - 1]; };


		// ALLOCATOR
		allocator_type get_allocator () const { return _alloc; };

		// MODIFIERS
		void assign (iterator first, iterator last)
		{
			size_type i = 0;
			clear();
			for(iterator it = first; it != last; it++)
				i++;
			if ( _capacity < i )
			{
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
					_data[i] = val;
			}
			else
			{
				_alloc.deallocate(_data, _size);
				_capacity = n;
				_size = n;
				_data = _alloc.allocate( n );
				for (size_t i = 0; i < _capacity; i++)
					_data[i] = val;
			}
		};

		void push_back(value_type value)
		{
			if (_size + 1 > _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			_data[_size] = value;
			_size++;
		};

		void pop_back()
		{
			if (!this->empty())
				_alloc.destroy(_data + _size--); 
		};

		iterator					insert (iterator position, const value_type& val)
		{
			size_type pos_index = 0;

			if (position > end()) throw std::length_error("out of range");
			for (iterator it = begin(); it + pos_index != position && pos_index < _size; pos_index++) ;
			if (_size + 1 > _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			for (size_type i = _size; i > pos_index; i--)
				_data[i] = _data[i - 1];
			_data[pos_index] = val;
			_size++;

			return iterator(&_data[pos_index]);                
		};

		void						insert (iterator position, size_type n, const value_type& val)
		{
			while (n--)
				position = insert(position, val);
		};

		void						insert (iterator position, iterator first, iterator last)
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

		void swap (vector& x)
		{
			ft::swap(_data, x._data);
			ft::swap(_size, x._size);
			ft::swap(_capacity, x._capacity);
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
	bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;

		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}

		return true;
	}

	template< class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		size_t size;

		if (lhs.size() > rhs.size())
			size = rhs.size();
		else
			size = lhs.size();

		for(size_t i = 0; i < size; i++)
		{
			if (lhs[i] != rhs[i])
				return(lhs[i] < rhs[i]);
		}

		return(lhs.size() < rhs.size()); 
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
