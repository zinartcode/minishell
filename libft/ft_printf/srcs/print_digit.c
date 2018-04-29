/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:56 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_sign(t_printf *e)
{
	if (e->flag.plus || e->flag.sp)
		e->ret += (e->flag.plus == 1 ?
		write(e->fd, "+", 1) : write(e->fd, " ", 1));
	else if (e->flag.neg)
		e->ret += write(e->fd, "-", 1);
}

static void	print_width(t_printf *e)
{
	int i;
	int len;

	i = -1;
	len = ((int)ft_strlen(e->out) > e->flag.prec ?
	(int)ft_strlen(e->out) : e->flag.prec);
	(e->flag.plus + e->flag.sp + e->flag.neg) >= 1 ? e->flag.width-- : 0;
	if (e->flag.prec >= 0)
	{
		while (e->flag.width - ++i > len)
			e->ret += write(e->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(e->out) < len - ++i)
			e->ret += write(e->fd, "0", 1);
	}
	else
		while (e->flag.width - ++i > len)
			e->ret += (e->flag.zero == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

static void	check_sign(t_printf *e)
{
	char *tmp;

	if (e->out[0] == '-')
	{
		tmp = ft_strdup(e->out + 1);
		free(e->out);
		e->out = tmp;
		e->flag.sp = 0;
		e->flag.plus = 0;
		e->flag.neg = 1;
	}
}

static void	check_prec(t_printf *e)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	check_sign(e);
	len = (int)ft_strlen(e->out);
	if (e->flag.prec == 0 && e->out[0] == '0')
		e->out[0] = '\0';
	else if (e->flag.prec > len)
	{
		i = e->flag.prec - len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(tmp);
		free(e->out);
		e->out = res;
	}
}

void		print_digit(t_printf *e)
{
	check_prec(e);
	if (e->flag.zero)
	{
		print_sign(e);
		print_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.minus)
	{
		print_sign(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_width(e);
	}
	else
	{
		print_width(e);
		print_sign(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	e->i++;
	free(e->out);
}
