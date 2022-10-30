/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:35:02 by fcil              #+#    #+#             */
/*   Updated: 2022/10/30 21:09:28 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <string>
#include <iterator>
#include <memory>

#include "reverse_iterator.hpp"
namespace ft
{
	template<class T>
	class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef T													iterator_type;
			typedef std::random_access_iterator_tag						iterator_category;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef	typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;

		private:
			iterator_type	_it;

		public:
			random_access_iterator(): _it(NULL) {};
			explicit	random_access_iterator( iterator_type x ): _it(x) {};
			template <class Iter>
			random_access_iterator ( const random_access_iterator<Iter>& vec_it ): _it(vec_it.base()) {};

			iterator_type	base() const							{ return (this->_it); };
			reference		operator*() const						{ return (*this->_it); };
			random_access_iterator			operator+( difference_type n ) const	{ return (random_access_iterator(this->_it + n)); };
			random_access_iterator			operator-( difference_type n ) const	{ return (random_access_iterator(this->_it - n)); };
			random_access_iterator&			operator++()							{++this->_it; return (*this); };					// pre-increment
			random_access_iterator			operator++(int)							{ random_access_iterator temp(*this); ++(*this); return (temp); }; // post-increment
			random_access_iterator&			operator--()							{--this->_it; return (*this); };					// pre-decrement
			random_access_iterator			operator--(int)							{ random_access_iterator temp(*this); --(*this); return (temp); };	// post-decrement
			random_access_iterator&			operator+=( difference_type n )			{ this->_it += n; return (*this); };
			random_access_iterator&			operator-=( difference_type n )			{ this->_it -= n; return (*this); };
			pointer			operator->()							{ return (&(operator*())); };
			reference		operator[]( difference_type n ) const	{ return (*(this->_it + n)); };
	};

	template <class Iterator1, class Iterator2>
	bool operator== (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator!= (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator<  (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator<= (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator>  (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator>=  (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); };

	template <class Iterator>
	random_access_iterator<Iterator> operator+ (typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator>& vec_it)
	{ return (random_access_iterator<Iterator>( vec_it + n)); };
	template <class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator- (const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };
};

