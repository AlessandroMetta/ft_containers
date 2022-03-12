#ifndef __MAP_HPP__
# define __MAP_HPP__


#include <memory>
#include <map>
#include <limits>
#include "../utils/algorithm.hpp"

namespace ft
{
    template <  class Key,
                class T,
                class Compare = std::less<Key>,
                class Alloc = std::allocator<ft::pair<const Key, T> >
                > class map
    {

    };
} // namespace ft


#endif