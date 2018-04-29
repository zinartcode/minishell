/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:21:02 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ptraddr_prec(t_printf *e)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = (int)ft_strlen(e->out);
	if (e->flag.prec > len)
	{
		tmp = ft_strnew(e->flag.prec - len);
		while (++i < e->flag.prec - len)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(e->out);
		free(tmp);
		e->out = res;
	}
	tmp = ft_strjoin("0x", e->out);
	free(e->out);
	e->out = tmp;
}

static void	print_width(t_printf *e)
{
	int len;

	len = ft_strlen(e->out);
	while (e->flag.width-- > len)
		e->ret += write(e->fd, " ", 1);
}

void		print_ptr(t_printf *e, char type)
{
	if (e->flag.zero && e->flag.prec == -1)
		e->flag.prec = e->flag.width - 2;
	ptraddr_prec(e);
	if (type == 'p')
		ft_lowcase(e->out);
	if (e->flag.minus)
	{
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_width(e);
	}
	else
	{
		print_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	e->i++;
	free(e->out);
}
