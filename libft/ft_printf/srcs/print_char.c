/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:53 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		null_char(t_printf *e)
{
	int len;

	len = (e->flag.prec < 0 ? 6 : e->flag.prec);
	while (e->flag.width-- > len)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
	e->ret += write(e->fd, "\0", 1);
	e->i++;
}

static void	char_width(t_printf *e)
{
	while (e->flag.width-- > 1)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void		print_char(t_printf *e, char c)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, &c, 1);
		char_width(e);
	}
	else
	{
		char_width(e);
		e->ret += write(e->fd, &c, 1);
	}
	e->i++;
}
