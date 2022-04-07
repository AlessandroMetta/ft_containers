#ifndef __FT_ALGORITHM_HPP__
# define __FT_ALGORITHM_HPP__

#include "iterator/iterator.hpp"

namespace ft
{
	/****************************	UTILS	******************************/

	template <typename T>
	void swap(T& a, T& b)
	{
		T c = a;
		a = b;
		b = c;
	}

	template <typename T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}

	template <typename T>
	T min(T& a, T& b)
	{
		return a < b ? a : b;
	}

	/****************************	PAIR	******************************/

	template <class T1, class T2>
	struct pair
	{
		typedef T1 type_first;
		typedef T2 type_second;

		type_first first;
		type_second second;

		pair() : first(), second() {}
		pair( const T1& x, const T2& y ) : first(x), second(y) {}
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}
		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	};

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	};

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return ((lhs.first < rhs.first) || !((rhs.first < lhs.first) && lhs.second < rhs.second));
	};

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair ( T1 lhs, T2 rhs)
	{
		return pair<T1,T2>(lhs, rhs);
	};

	/****************************	ENABLE_IF	******************************/
	
	template< bool Cond, class T = void > struct enable_if {};
	template< class T > struct enable_if< true, T > { typedef T type; };

	/****************************	IS_INTEGRAL	******************************/
	
	template < class T > struct is_integral { static const bool value = false; };
	template <> struct is_integral < bool > { static const bool value = true; };
	template <> struct is_integral < char > { static const bool value = true; };
	template <> struct is_integral <wchar_t> { static const bool value = true; };
	template <> struct is_integral < signed char > { static const bool value = true; };
	template <> struct is_integral < unsigned char > { static const bool value = true; };
	template <> struct is_integral < short int > { static const bool value = true; };
	template <> struct is_integral < int > { static const bool value = true; };
	template <> struct is_integral < long int > { static const bool value = true; };
	template <> struct is_integral < long long int > { static const bool value = true; };
	template <> struct is_integral < unsigned int > { static const bool value = true; };
	template <> struct is_integral < unsigned short int > { static const bool value = true; };
	template <> struct is_integral < unsigned long int > { static const bool value = true; };
	template <> struct is_integral < unsigned long long int > { static const bool value = true; };

}

#endif