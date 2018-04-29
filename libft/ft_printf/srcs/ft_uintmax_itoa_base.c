/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_itoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:33 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_lenght(uintmax_t n, int base, int *len)
{
	int i;

	i = 1;
	while (n >= (unsigned)base)
	{
		n /= base;
		i++;
	}
	*len = i;
}

char		*ft_uintmax_itoa_base(uintmax_t val, int base)
{
	char			*res;
	char			bs[17];
	int				len;

	len = 1;
	ft_strcpy(bs, "0123456789ABCDEF");
	if (val == 0)
		return (ft_strdup("0"));
	ft_lenght(val, base, &len);
	res = (char*)malloc(sizeof(char) * len + 1);
	res[len--] = '\0';
	while (val >= (unsigned)base)
	{
		res[len--] = bs[val % base];
		val /= base;
	}
	res[len] = bs[val % base];
	return (res);
}
