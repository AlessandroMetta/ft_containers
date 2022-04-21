#ifndef __SET_HPP__
# define __SET_HPP__

#include "RBTree.hpp"

namespace ft {

template < class Key,
			class Compare = std::less< Key >,
			class Alloc = std::allocator< Key >
			> class set
{
	public:

	typedef Key 														key_type;
	typedef Key 														value_type;
	typedef Compare 													key_compare;
	typedef key_compare													value_compare;
	typedef Alloc 														allocator_type;
	typedef typename allocator_type::reference 							reference;
	typedef typename allocator_type::const_reference					const_reference;
	typedef typename allocator_type::pointer							pointer;
	typedef typename allocator_type::const_pointer						const_pointer;
	typedef ft::RBTree< key_type, value_type, value_compare >			tree_t;
	typedef typename tree_t::const_iterator								iterator;
	typedef typename tree_t::const_iterator								const_iterator;
	typedef	ft::reverse_iterator<iterator>								reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>						const_reverse_iterator;
	typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
	typedef typename tree_t::size_type									size_type;


	explicit set( const key_compare& comp = key_compare(), const Alloc& alloc = Alloc())
	: tree(tree_t(value_compare(key_comp()))), comp(comp), alloc(alloc) {
		_SETsize = 0;
	};

	template <class InputIterator>
  	set (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const Alloc& alloc = Alloc())
	   : tree(comp, alloc)
	   {
		   insert(first, last);
	   };

	set (const set& x) : tree(x.tree)
	{
		insert(x.begin(), x.end());
	};

	set& operator=(const set & x)
	{
		tree = x.tree;
		return *this;
	};

	//--------------ITERATORS----------------//
	iterator begin()
	{
		return tree.begin();
	}

	const_iterator begin() const
	{
		return tree.begin();
	}

	iterator end()
	{
		return tree.end();
	}

	const_iterator end() const
	{
		return tree.end();
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}
	
	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}

	//---------------CAPACITY---------------//
	bool empty() const{
		return (!_SETsize ? 1 : 0);
	}
	
	size_type size() const{
		return (_SETsize);
	}

	size_type max_size(){
		return(tree.max_size());
	}

	//-------------MODIFIERS---------------//
	ft::pair<iterator, bool> insert(const value_type& value)
	{
		ft::pair<iterator, bool> ret = tree.insertion(value);
		_SETsize = tree.size();
		return (ret);
	}

	iterator insert (iterator position, const value_type& val){
		iterator it = position;
		++it;
		return(insert(val).first);
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last){
		while(first != last)
		{
			insert(*first);
			first++;
		}
	}

	void erase(iterator position){
		erase(*position);
	}

	size_type erase (const value_type& val)
	{
		size_type ret = tree.deletion(val);
		_SETsize = tree.size();
		return ret;
	};

	void erase(iterator first, iterator last){
		while (first != last)
		{
			erase(*first);
			first++;
		}
	}

	template<class Type> //Di supporto per swap
	void swapContent(Type *a, Type *b) 
	{
		Type *tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	void swap(set& x)
	{
		swapContent(&tree, &x.tree);
		swapContent(&_SETsize, &x._SETsize);
		swapContent(&alloc, &x.alloc);
		swapContent(&comp, &x.comp);
	}

	void clear()
    {
        tree.clear();
        _SETsize = 0;
    }

	//--------------OBSERVERS----------------//
	key_compare key_comp() const
	{
		return Compare();
	};

	value_compare value_comp() const
	{
		return key_comp();
	};

	//--------------OPERATIONS--------------//
	iterator find (const value_type& val) const{
		return (tree.search(val));
	}

	size_type count (const value_type& val) const{
		if (tree.count(val))
			return 1;
		return 0;
	}

	iterator lower_bound(const value_type& val) const{
		return tree.lower_bound(val);
	}

	iterator upper_bound(const value_type& val) const{
		return tree.upper_bound(val);
	}

	pair<iterator,iterator> equal_range(const value_type& val) const{
		return tree.equal_range(val);
	}


	//--------------SUPPORT--------------// da cancellare in pre-push

	void print()
	{
		tree.print();	
	}

	size_type SETgetsize(){	//x prova, da eliminare
		return (_SETsize);
	}

	private:
		tree_t tree;
		key_compare comp;
		Alloc alloc;
		size_type _SETsize;
};

}
#endif