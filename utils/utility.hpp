#ifndef __FT_ALGORITHM_HPP__
# define __FT_ALGORITHM_HPP__

#include "iterator.hpp"

namespace ft
{
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
		return ((lhs.first == rhs.second) && (lhs.second == rhs.second));
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
}

#endif
