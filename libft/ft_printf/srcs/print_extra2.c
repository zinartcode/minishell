/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_extra2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:21:00 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_ptr(t_printf *e, char type)
{
	long long			tmp;
	unsigned long long	addr;

	long_long_init(e, &tmp);
	addr = (unsigned long long)tmp;
	if (e->flag.prec == 0)
		e->out = ft_strdup("\0");
	else
		e->out = ft_itoa_base(addr, 16);
	print_ptr(e, type);
}

void	spec_wchar(t_printf *e, char type)
{
	wchar_t *ws;
	wchar_t wc;

	e->flag.minus ? e->flag.zero = 0 : 0;
	if (type == 's' || type == 'S')
	{
		wstr_init(e, &ws);
		if (ws == NULL)
			return (null_str(e));
		print_wstr(e, ws);
	}
	else if (type == 'c' || type == 'C')
	{
		wchar_init(e, &wc);
		if (wc == 0)
			return (null_char(e));
		ft_putwchar(wc);
	}
}

void	spec_return(t_printf *e)
{
	int	*tmp;

	if (e->tags.tag == val)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tags.val >= 0)
			tmp = va_arg(e->ap[0], int *);
	}
	tmp = va_arg(e->ap[0], int *);
	*tmp = e->ret;
	e->i++;
}

void	spec_percent(t_printf *e)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, "%", 1);
		while (e->flag.width-- > 1)
			e->ret += write(e->fd, " ", 1);
	}
	else
	{
		while (e->flag.width-- > 1)
			e->ret += (e->flag.zero ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, "%", 1);
	}
	e->i++;
}
