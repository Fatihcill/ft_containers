#ifndef __STACK_HPP__
#include "vector.hpp"

namespace ft
{
template <
	class T,
	class Container = ft::vector<T>
> class stack
{
	public:
	typedef Container							container_type;
	typedef	typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;

	private:
	container_type c;

	public:
	stack (const container_type& cont = container_type()) : c(cont)	{};

	stack (const stack& other)
	{
		*this = other;
	};

	~stack(){};

	stack& operator=(const stack& other)
	{
		c = other.c;
		return *this;
	}

	reference top()
	{
		return c.back();
	};

	const_reference top() const
	{
		return c.back();
	};

	bool empty() const 
	{
		return c.empty();
	};

	size_type size () const
	{
		return c.size();
	};

	void push(const value_type& x)
	{
		c.push_back(x);
	};

	void pop()
	{
		c.pop_back();
	};

	template <class T1, class _C1>
    friend
    bool
    operator==(const stack<T1, _C1>& lhs, const stack<T1, _C1>& rhs);

    template <class T1, class _C1>
    friend
    bool
    operator< (const stack<T1, _C1>& lhs, const stack<T1, _C1>& rhs);
};

template< class T, class Container >
bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return lhs.c == rhs.c;
};

template< class T, class Container >
bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return !(lhs == rhs);
};

template< class T, class Container >
bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return lhs.c < rhs.c;
};

template< class T, class Container >
bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return !(rhs < lhs);
};

template< class T, class Container >
bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return (rhs < lhs);
};

template< class T, class Container >
bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
{
	return !(lhs < rhs);
};
	
} // namespace ft

#endif