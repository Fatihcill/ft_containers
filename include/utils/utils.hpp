/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:01:19 by fcil              #+#    #+#             */
/*   Updated: 2022/10/26 16:27:58 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft
{
	template <typename T>
		std::string to_string(T n)
		{
			std::ostringstream ss;
			ss << n;
			return (ss.str());
		}
	//Doc = http://www.cplusplus.com/reference/functional/binary_function/?kw=binary_function)
	template <class Arg1, class Arg2, class Result>
		struct binary_function
		{
			typedef Arg1 first_argument_type;
			typedef Arg2 second_argument_type;
			typedef Result result_type;
		};
		//finds less..
	template <class T>
	struct less : binary_function<T, T, bool>
	{
		bool operator() (const T& x, const T& y) const
		{
			return (x < y);
		}
	};

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
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first <= rhs.first && lhs.second <= rhs.second));
	}

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first > rhs.first && lhs.second > rhs.second));
	}

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first >= rhs.first && lhs.second >= rhs.second));
	}

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
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

	// //doc http://www.cplusplus.com/reference/iterator/RandomAccessIterator/
    // class random_access_iterator_tag { };

	// //doc
    // class bidirectional_iterator_tag { };

	// //doc http://www.cplusplus.com/reference/iterator/ForwardIterator/
    // class forward_iterator_tag { };

	// //doc http://www.cplusplus.com/reference/iterator/InputIterator/
    // class input_iterator_tag { };

	// //doc http://www.cplusplus.com/reference/iterator/OutputIterator/
	// class output_iterator_tag { };

    // template <>
    //     struct is_input_iterator_tagged<ft::random_access_iterator_tag>
    //         : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

    // template <>
    //     struct is_input_iterator_tagged<ft::bidirectional_iterator_tag>
    //         : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

    // template <>
    //     struct is_input_iterator_tagged<ft::forward_iterator_tag>
    //         : public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };
    // template <>
    //     struct is_input_iterator_tagged<ft::input_iterator_tag>
    //         : public valid_iterator_tag_res<true, ft::input_iterator_tag> { };


    template <class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&>
        class iterator
        {
            public:
                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;
                typedef Category    iterator_category;
        };