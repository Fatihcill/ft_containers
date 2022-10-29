/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:01:19 by fcil              #+#    #+#             */
/*   Updated: 2022/10/29 18:00:16 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft
{
	//doc https://en.cppreference.com/w/cpp/utility/pair
	template <class T1, class T2>
	struct pair
	{
		public :
			typedef T1  first_type;
			typedef T2  second_type;
			first_type  first;
			second_type second;

			pair() : first(), second()
			{}

			template<class U, class V>
			pair (const pair<U, V>& pr) : first(pr.first), second(pr.second)
			{}

			pair (const first_type& a, const second_type& b) : first(a), second(b)
			{}
			pair& operator= (const pair& pr)
			{
				if (*this == pr)
					return (*this);
				this->first = pr.first;
				this->second = pr.second;
				return (*this);
			}
	};
	template <class T1, class T2>
	bool operator == (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return (lhs.first < rhs.first && lhs.second < rhs.second); }

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return (lhs.first <= rhs.first && lhs.second <= rhs.second); }

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return (lhs.first > rhs.first && lhs.second > rhs.second); }

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return (lhs.first >= rhs.first && lhs.second >= rhs.second); }

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y)
	{ return (ft::pair<T1, T2>(x, y)); }
	//end of pair struct----------------------

	//doc https://en.cppreference.com/w/cpp/types/enable_if
	template<bool B, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type;};

	//doc https://en.cppreference.com/w/cpp/types/is_integral
	template <class T>	struct	is_integral								{ static const bool value = false; };
	template <> 		struct	is_integral<bool> 						{ static const bool value = true; };
	template <> 		struct	is_integral<char>						{ static const bool value = true; };
	template <> 		struct	is_integral<char16_t>					{ static const bool value = true; };
	template <> 		struct	is_integral<char32_t>					{ static const bool value = true; };
	template <> 		struct	is_integral<wchar_t>					{ static const bool value = true; };
	template <> 		struct	is_integral<signed char>				{ static const bool value = true; };
	template <> 		struct	is_integral<short int>					{ static const bool value = true; };
	template <> 		struct	is_integral<int>						{ static const bool value = true; };
	template <> 		struct	is_integral<long int>					{ static const bool value = true; };
	template <> 		struct	is_integral<long long int>				{ static const bool value = true; };
	template <> 		struct	is_integral<unsigned char>				{ static const bool value = true; };
	template <> 		struct	is_integral<unsigned short int>			{ static const bool value = true; };
	template <> 		struct	is_integral<unsigned int>				{ static const bool value = true; };
	template <> 		struct	is_integral<unsigned long int>			{ static const bool value = true; };
	template <> 		struct	is_integral<unsigned long long int>		{ static const bool value = true; };

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	};
 /* Lexicographical comparison */

    /*
    ** @brief Return true if the range [first1, last2) compare
    ** lexicographically lest than the range [first2, last2).
    **
    ** @param first1, last1 the start and the end of the first range.
    ** @param first2, last2 the start and the end of the second range.
    ** @return true if the first range compares lexicographically less
    ** than the second, false otherwise.
    */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	//binary search tree nodes...
	template <typename T>
	struct BST_Node
	{
		public:
			typedef T	value_type;
			value_type value;
			BST_Node* parent;
			BST_Node* left;
			BST_Node* right;
			
			BST_Node () : value(), parent(nullptr), left(nullptr), right(nullptr)
			{}

			BST_Node (BST_Node* parent = nullptr, BST_Node* left = nullptr, BST_Node* right = nullptr)
			: value(), parent(parent), left(left), right(right)
			{}

			BST_Node (const value_type& val, BST_Node* parent = nullptr,
					BST_Node* left = nullptr, BST_Node* right = nullptr)
			: value(val), parent(parent), left(left), right(right)
			{}

			BST_Node (const BST_Node& nd) : value(nd.value), parent(nd.parent), left(nd.left), right(nd.right)
			{}
			
			virtual ~BST_Node() {}

			BST_Node &operator=(const BST_Node& nd)
			{
				if (nd == *this)
					return (*this);
				
				this->value = nd.value;
				this->parent = nd.parent;
				this->left = nd.left;
				this->right = nd.right;
				
				return (*this);
			}

			bool operator==(const BST_Node& nd)
			{
				if (value == nd.value)
					return (true);
				return (false);
			}
	};
}