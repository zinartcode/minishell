/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 23:13:01 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/12 23:14:37 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	if (ft_strchr(src, c) == NULL)
		return (NULL);
	while (*src)
		src++;
	while (*src != c)
		src--;
	return ((char*)src);
}
