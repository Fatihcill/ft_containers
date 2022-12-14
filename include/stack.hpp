/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:03:47 by fcil              #+#    #+#             */
/*   Updated: 2022/11/01 16:12:03 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"

namespace ft
{
	//doc https://en.cppreference.com/w/cpp/container/stack
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	T											value_type;
			typedef Container									container_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;

		protected:
			container_type c;

		public:
			explicit stack (const container_type& ctnr = container_type()): c(ctnr) {};

		public:
			bool empty()			const		{ return (!this->c.size()); };
			size_type size()		const		{ return (this->c.size()); };
			value_type& top()					{ return (this->c.back()); };
			const value_type& top() const		{ return (this->c.back()); };
			void push (const value_type& val)	{ this->c.push_back(val); };
			void pop()							{ this->c.pop_back(); };

		protected:
			template <class _T, class _C>
				friend bool operator== (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator!= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator<  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator<= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator>  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator>= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
	};

	template <class _T, class _C>
		bool operator== (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c == rhs.c); };
	template <class _T, class _C>
		bool operator!= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c != rhs.c); };
	template <class _T, class _C>
		bool operator<  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c < rhs.c); };
	template <class _T, class _C>
		bool operator<= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c <= rhs.c); };
	template <class _T, class _C>
		bool operator>  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c > rhs.c); };
	template <class _T, class _C>
		bool operator>= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c >= rhs.c); };
}
