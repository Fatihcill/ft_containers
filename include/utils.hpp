/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:01:19 by fcil              #+#    #+#             */
/*   Updated: 2022/11/01 15:38:28 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>

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

	template<class Type>
	void swapContent(Type &a, Type &b) 
	{
		Type tmp(a);
		a = b;
		b = tmp;
	}

	//doc: https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
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
}