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

	typedef	struct Node< T >*	NodePtr;
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

	iterator begin()
	{
		return tree.begin();
	}

	iterator end()
	{
		return tree.end();
	}

	//-------------OBSERVERS---------------//
	key_compare key_comp() const
	{
		return Compare();
	};

	value_compare value_comp() const
	{
		return key_comp();
	};

	//--------------------------------------//
   
	void print()
	{
		tree.print();	
	}

	size_t SETgetsize(){	//x prova, da eliminare
		return (_SETsize);
	}

	//---------------LOOKUP----------------//

	size_type count( const Key& key ) const
	{
		NodePtr found = tree.find(key);
		if (!found)
			return 0;
		return 1;
	}

	iterator find( const Key& key )
	{
		NodePtr found = tree.find(key);
		if (!found)
			return end();
		return iterator(found);
	}
	
	const_iterator find( const Key& key ) const
	{

	}

	iterator lower_bound( const Key& key ) 
	{
		return iterator(tree.lower_bound(key));
	}

	const_iterator lower_bound( const Key& key ) const 
	{
		return iterator(tree.lower_bound(key));
	}

	iterator upper_bound( const Key& key ) 
	{
		return iterator(tree.upper_bound(key));
	}

	const_iterator upper_bound( const Key& key ) const 
	{
		return iterator(tree.upper_bound(key));
	}

	//-------------------------------------//

	//-------------MODIFIERS---------------//
	ft::pair<iterator, bool> insert(Key value)
	{
		ft::pair<iterator, bool> ret = tree.insertion(value);
		_SETsize = tree.size();
		return (ret);
	}

	void erase(Key value) // erase (3, in cppreference)
	{
		tree.deletion(value);
		_SETsize = tree.size();
	}

	template<class Type> //Di supporto per swap
	void swapContent(Type &a, Type &b)
	{
		Type tmp(a);
		a = b;
		b = tmp;
	}

	void swap(set& x)
	{
		swapContent(tree, x.tree);
		swapContent(_SETsize, x._SETsize);
		swapContent(alloc, x.alloc);
		swapContent(comp, x.comp);
		//swapContent(begin);
		//swapContent(end);
	}
	//----------------------------------//

	//-------------CAPACITY-------------//
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
	//----------------------------------//

	private:
		tree_t tree;
		key_compare comp;
		Alloc alloc;
		size_type _SETsize;
};

}
#endif