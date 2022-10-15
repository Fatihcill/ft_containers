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
	typedef value_type&						 							reference;
	typedef const value_type&											const_reference;
	typedef typename allocator_type::pointer							pointer;
	typedef typename allocator_type::const_pointer						const_pointer;
	typedef ft::RBTree< key_type, value_type, value_compare >			tree_t;
	typedef typename tree_t::const_iterator								iterator;
	typedef typename tree_t::const_iterator								const_iterator;
	typedef	ft::reverse_iterator<iterator>								reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>						const_reverse_iterator;
	typedef typename tree_t::size_type									size_type;
	typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
	typedef Key*														Key_pt;


	explicit set( const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
	: tree(tree_t(value_compare(key_comp()))), comp(comp), alloc(alloc) {
	};

	template <class InputIterator>
  	set (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type())
	   : tree(comp, alloc)
	{
		insert(first, last);
	};

	set( const set& other ): tree(other.tree){
        *this = other;
    }

	~set() {};

	set& operator=( const set& other )
    {
        tree = other.tree;
        comp = other.comp;
        alloc = other.get_allocator();
        return *this;
    };

    allocator_type get_allocator() const
	{
		return alloc;
	}

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
		return (!tree.size() ? 1 : 0);
	}
	
	size_type size() const{
		return tree.size();
	}

	size_type max_size(){
		return tree.max_size();
	}

	//-------------MODIFIERS---------------//
	ft::pair<iterator, bool> insert(const value_type& value)
	{
		ft::pair<iterator, bool> b;
		Key_pt a = alloc.allocate(1);
		alloc.construct(a, value);
		b = tree.insertion(*a);
		alloc.destroy(a);
		alloc.deallocate(a, 1);
		return b;
	}

	iterator insert (iterator position, const value_type& val){
		(void)position;
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
		return tree.deletion(val);
	};

	void erase(iterator first, iterator last){
		// while (first != last)
		// {
		// 	erase(*first);
		// 	first++;
		// }
		iterator next = first;
		while (first != last)
		{
			next = first;
			first++;
			tree.deletion(*next);
		}
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
		swapContent(alloc, x.alloc);
		swapContent(comp, x.comp);
	}

	void clear()
    {
        tree.clear();
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
	iterator find (const value_type& val) {
		return (tree.search(val));
	}

	const_iterator find (const value_type& val) const{
		return (tree.search(val));
	}

	size_type count (const value_type& val) const{
		if (tree.count(val))
			return 1;
		return 0;
	}

	iterator lower_bound(const value_type& val) {
		return tree.lower_bound(val);
	}

	const_iterator lower_bound(const value_type& val) const{
		return tree.lower_bound(val);
	}

	iterator upper_bound(const value_type& val) {
		return tree.upper_bound(val);
	}

	const_iterator upper_bound(const value_type& val) const{
		return tree.upper_bound(val);
	}

	pair<iterator, iterator> equal_range(const value_type& val) {
		return tree.equal_range(val);
	}

	pair<const_iterator, const_iterator> equal_range(const value_type& val) const{
		return tree.equal_range(val);
	}

	//--------------SUPPORT--------------// da cancellare in pre-push

	void print()
	{
		tree.print();	
	}

	private:
		tree_t			tree;
		key_compare		comp;
		allocator_type	alloc;
		Key_pt 			a;

};

template< class Key, class Compare, class Alloc >
bool operator==( const ft::set<Key,Compare,Alloc>& lhs,
                 const ft::set<Key,Compare,Alloc>& rhs )
{
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};

template< class Key, class Compare, class Alloc >
bool operator!=( const ft::set<Key,Compare,Alloc>& lhs,
                 const ft::set<Key,Compare,Alloc>& rhs )
{
	return !(lhs == rhs);
};

template< class Key, class Compare, class Alloc >
bool operator<( const ft::set<Key,Compare,Alloc>& lhs,
                const ft::set<Key,Compare,Alloc>& rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(),rhs.begin(), rhs.end());
};

template< class Key, class Compare, class Alloc >
bool operator<=( const ft::set<Key,Compare,Alloc>& lhs,
                 const ft::set<Key,Compare,Alloc>& rhs )
{
	return !(rhs < lhs);
};

template< class Key, class Compare, class Alloc >
bool operator>( const ft::set<Key,Compare,Alloc>& lhs,
                const ft::set<Key,Compare,Alloc>& rhs )
{
	return rhs < lhs;
};

template< class Key, class Compare, class Alloc >
bool operator>=( const ft::set<Key,Compare,Alloc>& lhs,
                 const ft::set<Key,Compare,Alloc>& rhs )
{
	return !(lhs < rhs);
};

}

namespace std
{
	template< class Key, class Compare, class Alloc >
	void swap( ft::set<Key,Compare,Alloc>& lhs,
			ft::set<Key,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	};
}
#endif