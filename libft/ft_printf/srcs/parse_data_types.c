/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:44 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uintmax_t_init(t_printf *e, uintmax_t *tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], uintmax_t);
		return ;
	}
	*tmp = va_arg(e->ap[0], uintmax_t);
}

void	long_long_init(t_printf *e, long long *tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], long long);
		return ;
	}
	*tmp = va_arg(e->ap[0], long long);
}

void	char_init(t_printf *e, char **tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], char *);
		return ;
	}
	*tmp = va_arg(e->ap[0], char *);
}

void	int_init(t_printf *e, int *tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], int);
		return ;
	}
	*tmp = va_arg(e->ap[0], int);
}
