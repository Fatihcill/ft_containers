#ifndef __FT_ALGORITHM_HPP__
# define __FT_ALGORITHM_HPP__

#include "iterator.hpp"
#include <type_traits>

namespace ft
{
	/****************************	UTILS	******************************/

	template<class Type> //Di supporto per swap
	void swapContent(Type &a, Type &b) 
	{
		Type tmp(a);
		a = b;
		b = tmp;
	}

	template <typename T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}

	template <typename T>
	T min(T& a, T& b)
	{
		return a < b ? a : b;
	}

	/****************************	PAIR	******************************/

	template <class T1, class T2>
	struct pair
	{
		typedef T1 type_first;
		typedef T2 type_second;

		type_first first;
		type_second second;

		pair() : first(), second() {}
		pair( const T1& x, const T2& y ) : first(x), second(y) {}
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}
		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	};

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	};

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	};

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair ( T1 lhs, T2 rhs)
	{
		return pair<T1,T2>(lhs, rhs);
	};

	/****************************	ENABLE_IF	******************************/
	
	template< bool Cond, class T = void > struct enable_if {};
	template< class T > struct enable_if< true, T > { typedef T type; };

	/****************************	IS_INTEGRAL	******************************/
	
	template < class T > struct is_integral : public std::false_type {};
	template <> struct is_integral < bool > : public std::true_type {};
	template <> struct is_integral < char > : public std::true_type {};
	template <> struct is_integral <wchar_t> : public std::true_type {};
	template <> struct is_integral <char16_t> : public std::true_type {};
	template <> struct is_integral <char32_t> : public std::true_type {};
	template <> struct is_integral < signed char > : public std::true_type {};
	template <> struct is_integral < unsigned char > : public std::true_type {};
	template <> struct is_integral < short int > : public std::true_type {};
	template <> struct is_integral < int > : public std::true_type {};
	template <> struct is_integral < long int > : public std::true_type {};
	template <> struct is_integral < long long int > : public std::true_type {};
	template <> struct is_integral < unsigned int > : public std::true_type {};
	template <> struct is_integral < unsigned short int > : public std::true_type {};
	template <> struct is_integral < unsigned long int > : public std::true_type {};
	template <> struct is_integral < unsigned long long int > : public std::true_type {};
	
	/**********************	LEXICOGRAPHICAL_COMPARE	***********************/
	
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	/**********************	EQUAL	***********************/

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}
}


#endif