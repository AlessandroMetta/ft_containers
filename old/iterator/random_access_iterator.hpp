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
		typedef	random_access_iterator< const T >	const_iterator;
		typedef	T									value_type;

		//	it()
		random_access_iterator () : ptr( NULL ) {};

		//	it(ptr)
		explicit random_access_iterator ( pointer ptr ) : ptr( ptr ) {};

		//	it1(it2)
		random_access_iterator ( const random_access_iterator& x ) 
		{
			ptr = x.ptr;
		};

		~random_access_iterator(){};

		//	it1 = it2
		random_access_iterator& operator= ( const random_access_iterator& x )
		{
			ptr = x.ptr;
			return *this;
		};

		//	it1 == it2
		bool operator==(  const random_access_iterator& rhs ) const
		{
			return ptr == rhs.ptr;
		};

		//	it1 != it2
		bool operator!= ( const random_access_iterator& rhs ) const
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
		iterator& operator++ () 
		{
			ptr++;
			return *this;
		};

		//	++it
		iterator operator++ ( int ) 
		{
			iterator tmp = *this;
			ptr++;
			return tmp;
		};

		//	it += n
		iterator& operator+= ( difference_type n )
		{
			ptr += n;
			return *this;
		};

		//	it--
		iterator& operator-- ()
		{
			ptr--;
			return *this;
		};

		//	--it
		iterator operator-- ( int )
		{
			iterator tmp = *this;
			ptr--;
			return tmp;
		};

		//	it -= n
		iterator& operator-= ( difference_type n )
		{
			ptr -= n;
			return *this;
		};
		
		//	n + it
		iterator operator+ ( const int n ) const
		{
			return iterator(ptr + n);
		};

		// it + n
		friend iterator operator+ ( int n, iterator it )
		{
			return iterator(it.ptr + n);
		};

		//	it - n
		iterator operator- ( const difference_type& n ) const
		{
			return iterator(ptr - n);
		};

		//	it1 - it2
		difference_type operator- ( const iterator& rhs ) const
		{
			return ptr - rhs.ptr;
		};

		// comparison operator
		bool operator> ( const iterator& rhs ) const
		{
			return ptr > rhs.ptr;
		};

		bool operator< ( const iterator& rhs ) const
		{
			return ptr < rhs.ptr;
		};

		bool operator>= ( const iterator& rhs ) const
		{
			return ptr >= rhs.ptr;
		};

		bool operator<= ( const iterator& rhs ) const
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
	
} // namespace ft


#endif