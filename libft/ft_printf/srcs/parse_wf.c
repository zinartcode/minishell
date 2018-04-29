/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:49 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wstr_init(t_printf *e, wchar_t **tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], wchar_t *);
		return ;
	}
	*tmp = va_arg(e->ap[0], wchar_t *);
}

void	wchar_init(t_printf *e, wchar_t *tmp)
{
	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			*tmp = va_arg(e->ap[0], wchar_t);
		return ;
	}
	*tmp = va_arg(e->ap[0], wchar_t);
}
