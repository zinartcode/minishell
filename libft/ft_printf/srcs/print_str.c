/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:21:04 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		null_str(t_printf *e)
{
	int len;

	len = (e->flag.prec < 0 ? 6 : e->flag.prec);
	while (e->flag.width-- > len)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
	e->ret += write(e->fd, "(null)", len);
	e->i++;
}

static void	width_string(t_printf *e)
{
	int len;

	len = ft_strlen(e->out);
	while (e->flag.width-- > len)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void		print_str(t_printf *e)
{
	char	*tmp;

	if (e->flag.prec >= 0 && e->flag.prec < (int)ft_strlen(e->out))
	{
		tmp = ft_strsub(e->out, 0, (e->flag.prec));
		free(e->out);
		e->out = tmp;
	}
	if (e->flag.minus)
	{
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		width_string(e);
	}
	else
	{
		width_string(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	e->i++;
	free(e->out);
}
