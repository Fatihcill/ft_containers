#ifndef __MAP_HPP__
# define __MAP_HPP__

#include "RBTree.hpp"

namespace ft {
template < class Key,
			class T, 
			class Compare = std::less< Key >, 
			class Alloc = std::allocator< ft::pair<const Key, T > >
			> class map
{
	public:

	typedef	Key													key_type;
	typedef	T													mapped_type;
	typedef typename Alloc::value_type							value_type;
	typedef std::size_t											size_type;
	typedef std::ptrdiff_t										difference_type;
	typedef	Compare												key_compare;
	typedef	Alloc												allocator_type;
	typedef	value_type&											reference;
	typedef	const value_type&									const_reference;
	typedef	typename allocator_type::pointer					pointer;
	typedef	typename allocator_type::const_pointer				const_pointer;

	class value_compare : std::binary_function<value_type, value_type, bool>
	{
		friend class map;
	protected:
		key_compare comp;

		value_compare(key_compare c): comp(c){};
	public:
		bool operator()(const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

	typedef ft::RBTree< key_type, value_type, value_compare >	tree_t;
	typedef typename tree_t::iterator							iterator;
	typedef typename tree_t::const_iterator						const_iterator;
	typedef	ft::reverse_iterator<iterator>						reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef ft::pair<const Key, T>*								Pair_pointer;

	//--------------CONSTRUCTORS----------------//

	explicit map( const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
	: tree(tree_t(value_compare(key_comp()))), comp(comp), alloc(alloc) {};
	template< class InputIt >
	map( InputIt first, InputIt last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type() )
		: tree(comp, alloc)
	{
		insert(first, last);
	};

	map( const map& other ): tree(other.tree){
        *this = other;
    }
	
	~map() {};

	map& operator=( const map& other )
    {
        tree = other.tree;
        comp = other.comp;
        alloc = other.get_allocator();
        return *this;
    };

	allocator_type get_allocator() const
	{
		return alloc;
	};

	//--------------ELEMENT ACCESS----------------//

	T& at( const Key& key )
	{
		iterator found = tree.search(ft::make_pair(key, mapped_type()));
		if (found == end())
			throw std::out_of_range("Error: at: key not found");
		return found->second;
	};
	const T& at( const Key& key ) const
	{
		iterator found = tree.search(ft::make_pair(key, mapped_type()));
		if (found == end())
			throw std::out_of_range("Error: at: key not found");
		return found->second;
	};

	T& operator[]( const Key& key )
    {
		Pair_pointer a = alloc.allocate(1);
		alloc.construct(a, ft::make_pair(key, mapped_type()));
        iterator found = tree.search(ft::make_pair(key, mapped_type()));
        if (found == end())
			found = tree.insertion(*a).first;
		alloc.deallocate(a, 1);
        return found->second;
    };
	
	//--------------ITERATORS----------------//
	iterator begin()
	{
		return tree.begin();
	};

	iterator end()
	{
		return tree.end();
	};

	const_iterator begin() const
	{
		return tree.begin();
	};

	const_iterator end() const
	{
		return tree.end();
	};

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	};

	const_reverse_iterator rbegin() const
	{
		return reverse_iterator(end());
	};

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	};

	const_reverse_iterator rend() const
	{
		return reverse_iterator(begin());
	};

	//-------------CAPACITY---------------//
	bool empty() const
	{
		return (!tree.size() ? 1 : 0);
	};

	size_type size() const
	{
		return tree.size();
	};

	size_type max_size() const
	{
		return tree.max_size();
	};

	//-------------MODIFIERS---------------//

	void clear()
	{
		tree.clear();
	};

	ft::pair<iterator, bool> insert( const value_type& value )
	{
		Pair_pointer a = alloc.allocate(1);
		ft::pair<iterator, bool> b;
		alloc.construct(a, value);
		b = tree.insertion(*a);
		alloc.destroy(a);
		alloc.deallocate(a, 1);
		return b;
	};

	iterator insert( iterator hint, const value_type& value )
	{
		(void)hint;
		return tree.insertion(value).first;
	};

	template< class InputIt >
	void insert( InputIt first, InputIt last )
	{
		while (first != last)
		{
			insert(*first);
			first++;
		}
	};

	size_type erase (const key_type& value)
	{
		return tree.deletion(ft::make_pair(value, mapped_type()));
	};

	void erase (iterator position)
	{
		erase(position->first);
	};

	void erase (iterator first, iterator last)
	{
		iterator next = first;
		while (first != last)
		{
			next = first;
			first++;
			tree.deletion(*next);
		}
	};

	template<class Type> //Di supporto per swap
	void swapContent(Type &a, Type &b) 
	{
		Type tmp(a);
		a = b;
		b = tmp;
	}

	void swap(map& x)
	{
		swapContent(tree, x.tree);
		swapContent(alloc, x.alloc);
		swapContent(comp, x.comp);
	}

	//-------------LOOKUP---------------//

	size_type count( const Key& key ) const
	{
		if (tree.count(ft::make_pair(key, mapped_type())))
			return 1;
		return 0;
	};

	iterator find( const Key& key )
	{
		return tree.search(ft::make_pair(key, mapped_type()));
	};

	const_iterator find( const Key& key ) const
	{
		return tree.search(ft::make_pair(key, mapped_type()));
	};

	pair<iterator, iterator> equal_range( const Key& key ) {
		return tree.equal_range(ft::make_pair(key, mapped_type()));
	}

	pair<const_iterator, const_iterator> equal_range( const Key& key ) const{
		return tree.equal_range(ft::make_pair(key, mapped_type()));
	}

	iterator lower_bound( const Key& key ) {
		return tree.lower_bound(ft::make_pair(key, mapped_type()));
	}

	const_iterator lower_bound( const Key& key ) const{
		return tree.lower_bound(ft::make_pair(key, mapped_type()));
	}

	iterator upper_bound( const Key& key ) {
		return tree.upper_bound(ft::make_pair(key, mapped_type()));
	}

	const_iterator upper_bound( const Key& key ) const{
		return tree.upper_bound(ft::make_pair(key, mapped_type()));
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

	// useful
	void print()
	{
		tree.print();
	};

	private:
		tree_t		tree;
		Compare		comp;
		Alloc		alloc;
		Pair_pointer p;
};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return rhs < lhs;
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	};
}

namespace std
{
	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs,
			ft::map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	};
} // namespace std


#endif
