#ifndef __ITERATOR_HPP__
# define __ITERATOR_HPP__

#include "utils.hpp"

namespace ft 
{
	/****************************	ITERATOR_TRAITS	******************************/

	template< class Iter >
	struct iterator_traits
	{
		typedef	typename Iter::difference_type		difference_type;
		typedef	typename Iter::value_type			value_type;
		typedef	typename Iter::pointer				pointer;
		typedef	typename Iter::reference			reference;
		typedef	typename Iter::iterator_category	iterator_category;
	};

	template< class T >
	struct iterator_traits< T* >
	{
		typedef	std::ptrdiff_t						difference_type;
		typedef	T									value_type;
		typedef	T*									pointer;
		typedef	T& 									reference;
		typedef	std::random_access_iterator_tag		iterator_category;
	};

	template< class T >
	struct iterator_traits< const T* >
	{
		typedef std::ptrdiff_t  					difference_type;
		typedef T               					value_type;
		typedef const T*        					pointer;
		typedef const T&							reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	template< class Iter >
	class reverse_iterator
	{
	public:
		typedef	Iter														iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;

		reverse_iterator() : base_iterator() {};

		explicit reverse_iterator( iterator_type x ) : base_iterator( x ) {};

		template< class U >
			reverse_iterator( const reverse_iterator<U>& other )
			: base_iterator( other.base() ) {};

		iterator_type base() const
		{
			return base_iterator;
		};

		reference operator*() const
		{
			Iter tmp = base_iterator;
			return *--tmp;
		};

		pointer operator->() const
		{
			return &(operator*());
		};

		reference operator[] ( difference_type n ) const
		{
			return base()[ - n - 1 ];
		};

		reverse_iterator operator+ ( difference_type n ) const 
		{
			return reverse_iterator(base_iterator - n);
		};

		reverse_iterator& operator++()
		{
			base_iterator-- ;
			return *this;
		};

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			base_iterator--;
			return tmp;
		};

		reverse_iterator& operator+= (difference_type n)
		{
			base_iterator -= n;
			return *this;
		};

		reverse_iterator operator- (difference_type n) const 
		{
			return reverse_iterator(base_iterator + n);
		};

		reverse_iterator& operator--()
		{
			base_iterator++;
			return *this;
		};

		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp = *this;
			base_iterator++;
			return tmp;
		};

		reverse_iterator& operator-= (difference_type n)
		{
			base_iterator += n; return *this;
		};

	private:
		iterator_type base_iterator;
	};

	template <class Iterator>
	bool operator== (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() == rhs.base() );
	};

	template <class Iterator>
	bool operator!= (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() != rhs.base() );
	};

	template <class Iterator>
	bool operator<  (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() > rhs.base() );
	};

	template <class Iterator>
	bool operator<= (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() >= rhs.base() );
	};

	template <class Iterator>
	bool operator>  (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() < rhs.base() );
	};

	template <class Iterator>
	bool operator>= (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() <= rhs.base() );
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it + n);
	};

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	};

}

#endif