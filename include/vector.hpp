/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:47:05 by fcil              #+#    #+#             */
/*   Updated: 2022/10/25 15:55:52 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

//doc:
//http://www.cplusplus.com/reference/vector/vector/?kw=vector
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >// generic template
	class vector
	{
		public:
			typedef	T										value_type;
			typedef	Alloc									allocator_type;
			typedef allocator_type::reference				reference;
			typedef allocator_type::const_reference			const_reference;
			typedef allocator_type::pointer					pointer;
			typedef allocator_type::const_pointer			const_pointer;
			typedef ft::random_access_iterator<value_type>	iterator;

	}

}