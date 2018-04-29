/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:49:48 by azinnatu          #+#    #+#             */
/*   Updated: 2017/07/26 16:07:20 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *src1;
	const unsigned char *src2;

	src1 = s1;
	src2 = s2;
	while (n--)
	{
		if (*src1 != *src2)
		{
			return (*src1 - *src2);
		}
		else
		{
			src1++;
			src2++;
		}
	}
	return (0);
}
