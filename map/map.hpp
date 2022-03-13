#ifndef __MAP_HPP__
# define __MAP_HPP__


#include <memory>
#include <map>
#include <limits>
#include "../utils/utility.hpp"

namespace ft
{
	template <  class Key, class T, class Compare = std::less<Key>,
				class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		typedef Key	key_value;
		typedef T	mapped_value;
		typedef ft::pair<const key_value, mapped_value>	value_value;
		typedef std::size_t size_type
		typedef std::ptrdiff_t difference_type
		typedef Compare	key_compare;
		typedef Allocator	allocator_type;
		typedef value_type&	reference;
		typedef const value_type&	const_reference;
		typedef const Allocator::pointer	pointer;
		typedef const Allocator::const_pointer	const_pointer;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator

	};
} // namespace ft


#endif