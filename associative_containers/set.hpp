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

	typedef Key key_type;
	typedef Key value_type;
	typedef Compare key_compare;

	class value_compare : std::binary_function<key_type, value_type, bool>
	{
		friend class set;
	protected:
		key_compare comp;

		value_compare(key_compare c) : comp(c) {};
	public:
		bool operator()(const value_type& x, const value_type& y) const
		{
			return comp(x, y);
		}
	};

	typedef ft::RBTree<key_type, value_type, value_compare> tree_t;
	typedef typename tree_t::iterator iterator;

	explicit set( const Compare& comp = Compare(), const Alloc& alloc = Alloc())
	: tree(tree_t(value_compare(key_comp()))), comp(comp), alloc(alloc) {
		_SETsize = 0;
	};

	//--------------ITERATORS----------------//
	iterator begin()
	{
		return tree.begin();
	}

	iterator end()
	{
		return tree.end();
	}

	//rbegin()
	//rend()

	//---------------CAPACITY---------------//
	typedef size_t	size_type;

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
	ft::pair<iterator, bool> insert(Key value)
	{
		ft::pair<iterator, bool> ret = tree.insertion(value);
		_SETsize = tree.size();
		return (ret);
	}

	iterator insert (iterator position, const value_type& val){
		if (position) ;
		return(insert(val).first);
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last){
		while(first != last)
			insert((*first)++);
	}

	void erase(iterator position){
		erase(*position);
	}

	void erase(Key value) // erase (2, in cppreference)
	{
		tree.deletion(value);
		_SETsize = tree.size();
	}

	void erase(InputIterator first, InputIterator last){
		while(first != last)
			erase((*first)++);
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

	//clear()
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

	//--------------SUPPORT--------------// da cancellare in pre-push

	void print()
	{
		tree.print();	
	}

	size_t SETgetsize(){	//x prova, da eliminare
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