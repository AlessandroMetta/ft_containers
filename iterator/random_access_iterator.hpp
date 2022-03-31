#ifndef __RANDOM_ACCESS_ITERATOR_HPP__
#  define __RANDOM_ACCESS_ITERATOR_HPP__

#include "iterator.hpp"

namespace ft
{
	template< typename T >
	class random_access_iterator
	{
	public:
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef	T*									pointer;
		typedef	T&									reference;
		typedef	std::ptrdiff_t						difference_type;
		typedef	random_access_iterator< T >			iterator;
		typedef	random_access_iterator< const T >	pointer;
		typedef	T									value_type;



		//	it()
		random_access_iterator() : ptr( NULL ) {};

		//	it(ptr)
		explicit random_access_iterator( pointer ptr ) : ptr( ptr ) {};

		//	it1(it2)
		random_access_iterator( const random_access_iterator& x ) 
		{
			ptr = x.ptr;
		};

		//	it1 = it2
		random_access_iterator& operator=( const random_access_iterator& x )
		{
			ptr = x.ptr;
			return *this;
		};

		//	it1 == it2
		bool operator==( const random_access_iterator& rhs ) const
		{
			return ptr == rhs.ptr;
		};

		//	it1 != it2
		bool operator!=( const random_access_iterator& rhs ) const
		{
			return ptr != rhs.ptr;
		};

		//	it->
		pointer operator->() const
		{
			return ptr;
		};

		//	*it
		reference operator*() const
		{
			return *ptr;
		};

		//	it++
		iterator& operator++() 
		{
			ptr++;
			return *this;
		};

		//	++it
		iterator operator++( int ) 
		{
			iterator tmp = *this;
			ptr++;
			return tmp;
		};

		//	it += n
		iterator& operator+=( difference_type n )
		{
			ptr += n;
			return *this;
		};

		//	it--
		iterator& operator--()
		{
			ptr--;
			return *this;
		};

		//	--it
		iterator operator--( int )
		{
			iterator tmp = *this;
			ptr++;
			return tmp;
		};

		//	it -= n
		iterator& operator-=( difference_type n )
		{
			ptr -= n;
			return *this;
		};
		
		//	n + it
		iterator operator+( const int n ) const
		{
			return iterator(ptr + n);
		};

		//	it - n
		iterator operator-( difference_type n )
		{
			return iterator(ptr - n);
		};

		//	it1 - it2
		difference_type operator-( const iterator& rhs ) const
		{
			return ptr - rhs.ptr;
		};

		//	it1 - it2
		difference_type operator-( const iterator& rhs ) const
		{
			return ptr - rhs.ptr;
		};


		~random_access_iterator(){};
	private:
		pointer ptr;
	};
	
} // namespace ft


#endif