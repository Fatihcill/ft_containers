/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:14:11 by rchallie          #+#    #+#             */
/*   Updated: 2022/10/30 16:59:48 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "./utils/utils.hpp"
#include "./utils/binary_search_tree.hpp"

namespace ft
{
	//doc https://en.cppreference.com/w/cpp/container/map
	template < class Key, class T, class Compare = std::less<Key>,
				class Alloc = std::allocator<ft::pair<const Key, T > > >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<key_type, mapped_type>				value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

		//doc https://en.cppreference.com/w/cpp/container/map/value_compare
			class value_compare
			{
				friend class map;

				protected:
					Compare _comp;
					value_compare(Compare c) : _comp(c) {}

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type &x, const value_type &y) const
					{
						return _comp(x.first, y.first);
					};
			};

			typedef typename ft::Binary_search_tree<value_type, key_compare>::iterator			iterator;
			typedef typename ft::Binary_search_tree<value_type, key_compare>::const_iterator	const_iterator;
			typedef typename ft::reverse_iterator<iterator>										reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type						difference_type;
			typedef size_t size_type;

			//custom variables
			private:
				allocator_type                          _alloc;
				Compare                                 _comp;
				Binary_search_tree<value_type, Compare>  _bst;

			public:

				//constructors....
				explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _bst() {}

				template <class InputIterator>
					map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type(),
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
				:	_alloc(alloc), _comp(comp), _bst()
				{ this->insert(first, last); }

				map(const map& x)
				: _alloc(x._alloc), _comp(x._comp), _bst()
				{ this->insert(x.begin(), x.end()); }

				~map()
				{ this->clear(); }

				map& operator= (const map& x)
				{
					if (&x == this)
						return (*this);
					this->clear();
					this->insert(x.begin(), x.end());
					return (*this);
				}

				iterator begin()
				{ return (iterator(_bst._last_node->left, _bst._last_node)); }

				const_iterator begin() const
				{ return (const_iterator(_bst._last_node->left, _bst._last_node)); }

				iterator end()
				{ return (iterator(_bst._last_node, _bst._last_node)); }

				const_iterator end() const
				{ return (const_iterator(_bst._last_node, _bst._last_node)); }

				reverse_iterator rbegin()
				{ return (reverse_iterator(this->end())); }

				const_reverse_iterator rbegin() const
				{ return (const_reverse_iterator(this->end())); }

				reverse_iterator rend()
				{ return (reverse_iterator(this->begin())); }

				const_reverse_iterator rend() const
				{ return (const_reverse_iterator(this->begin())); }

				bool empty() const
				{ return (_bst._last_node->parent == _bst._last_node); }

				size_type size() const
				{ return (_bst._last_node->value.first); }

				size_type max_size() const
				{ return (_bst.max_size()); }

				mapped_type& operator[] (const key_type& k)
				{
					iterator tmp = this->find(k);

					if (tmp == this->end())
						this->insert(ft::make_pair(k, mapped_type()));
					tmp = this->find(k);
					return ((*tmp).second);
				} 

				pair<iterator,bool> insert (const value_type& val)
				{ return (_bst.insertPair(val)); }

				iterator insert (iterator position, const value_type& val)
				{
					(void)position;
					return (_bst.insertPair(val).first);
				}

				template <class InputIterator>
					void insert (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
				{
					difference_type n = std::distance(first, last);
					while (n--)
						this->insert(*(first++));
				}

				void erase (iterator position)
				{ this->erase((*position).first); }

				size_type erase (const key_type& k)
				{
					if (this->find(k) == this->end())
						return (0);
					_bst.removeByKey(ft::make_pair(k, mapped_type()));
					return (1);
				}

				void erase (iterator first, iterator last)
				{
					while (first != last)
						this->erase((*(first++)).first);
				}

				void swap (map& x)
				{ _bst.swap(x._bst); }

				void clear()
				{ this->erase(this->begin(), this->end()); }

				key_compare key_comp() const
				{ return (key_compare()); }

				value_compare value_comp() const
				{ return (value_compare(key_compare())); }

				iterator find (const key_type& k)
				{ return (iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node)); }

				const_iterator find (const key_type& k) const
				{ return (const_iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node)); }

				size_type count (const key_type& k) const
				{
					const_iterator beg = this->begin();
					const_iterator end = this->end();

					while (beg != end)
						if ((*(beg++)).first == k)
							return (1);
					return (0);
				}

				iterator lower_bound (const key_type& k)
				{
					iterator beg = this->begin();
					iterator end = this->end();

					while (beg != end)
					{
						if (_comp((*beg).first, k) == false)
							break;
						beg++;
					}
					return (beg);
				}

				const_iterator lower_bound (const key_type& k) const
				{ return (const_iterator(this->lower_bound(k))); }

				iterator upper_bound (const key_type& k)
				{
					iterator beg = this->begin();
					iterator end = this->end();

					while (beg != end)
					{
						if (_comp(k, (*beg).first))
							break;
						beg++;
					}
					return (beg);
				}

				const_iterator upper_bound (const key_type& k) const
				{ return (const_iterator(this->upper_bound(k))); }

				ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
				{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

				ft::pair<iterator, iterator> equal_range (const key_type& k)
				{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }
			
				allocator_type get_allocator() const { return (this->_alloc); };
	};
}

#endif