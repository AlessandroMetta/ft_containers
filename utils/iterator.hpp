#ifndef __ITERATOR_HPP__
# define __ITERATOR_HPP__

#include <cstddef>

namespace ft
{
	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class Category, class T, class Distance = ptrdiff_t,
			 class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
						typename iterator_traits<Iterator>::difference_type,
						typename iterator_traits<Iterator>::pointer,
						typename iterator_traits<Iterator>::reference>
	{
	protected:
		Iterator current;
	public:
		typedef Iterator                                            iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::reference       reference;
		typedef typename iterator_traits<Iterator>::pointer         pointer;

		reverse_iterator() : current() {};
		~reverse_iterator() {};
		explicit reverse_iterator(Iterator x) : current(x) {};
		reverse_iterator(const reverse_iterator& u) : current(u.current) {};
		template <typename U>
		reverse_iterator& operator=(const reverse_iterator<U>& u) { current = u.current; };
		Iterator base() const { return current; };
		reference operator*() const { Iterator tmp = current; return *--tmp; };
		pointer   operator->() const { return &(operator*()); };
		reverse_iterator& operator++() { current--; return *this;};
		reverse_iterator  operator++(int) { Iterator tmp = *this; current--; return *tmp;};
		reverse_iterator& operator--() { current++; return *this;};
		reverse_iterator  operator--(int) { Iterator tmp = *this; current++; return *tmp;};
		reverse_iterator  operator+ (difference_type n) const { return reverse_iterator(current - n); };
		reverse_iterator& operator+=(difference_type n) { current -= n; return *this; };
		reverse_iterator  operator- (difference_type n) const { return reverse_iterator(current + n); };
		reverse_iterator& operator-=(difference_type n) { current += n; return *this; };
		reference         operator[](difference_type n) const { return *(*this + n); };
	};

	template <class Iterator1, class Iterator2>
		bool operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
		{
			return x.base() == y.base();
		}

	template <class Iterator1, class Iterator2>
		bool operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
		{
			return x.base() != y.base();
		}

	template <class Iterator1, class Iterator2>
		bool operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
		{
			return x.base() > y.base();
		}

	template <class Iterator1, class Iterator2>
		bool operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
		{
			return x.base() >= y.base();
		}

	template <class Iterator1, class Iterator2>
		bool operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
		{  
			return x.base() < y.base();
		}

	template <class Iterator1, class Iterator2>
		bool operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
		{
			return x.base() <= y.base();
		}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, 
		  const reverse_iterator<Iterator>& x) { return reverse_iterator<Iterator>(x.base() - n); }

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y) { return x.base() + y.base(); }

}

#endif
