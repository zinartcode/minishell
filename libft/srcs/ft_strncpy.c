/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 23:12:14 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/12 23:13:06 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *d;

	d = dst;
	while (len > 0 && *src != '\0')
	{
		*d++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*d++ = '\0';
		--len;
	}
	return (dst);
}
