/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:58 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_base(t_printf *e, char type)
{
	uintmax_t	tmp;
	uintmax_t	value;

	value = 0;
	uintmax_t_init(e, &tmp);
	if (type == 'O' || e->modifier == ll || e->modifier == j)
		value = (unsigned long long)tmp;
	else if (e->modifier == none)
		value = (unsigned int)tmp;
	else if (e->modifier == h)
		value = (unsigned short)tmp;
	else if (e->modifier == hh)
		value = (unsigned char)tmp;
	else if (e->modifier == l)
		value = (unsigned long long)tmp;
	else if (e->modifier == z)
		value = (size_t)tmp;
	(type == 'b' || type == 'B') ? e->out = ft_uintmax_itoa_base(value, 2) : 0;
	(type == 'o' || type == 'O') ? e->out = ft_uintmax_itoa_base(value, 8) : 0;
	(type == 'x' || type == 'X') ? e->out = ft_uintmax_itoa_base(value, 16) : 0;
	if (type >= 'b' && type <= 'x')
		ft_lowcase(e->out);
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	print_base(e, type, (uintmax_t)value);
}

void	spec_char(t_printf *e, char type)
{
	char	*str;
	int		st;

	e->flag.minus ? e->flag.zero = 0 : 0;
	if (type == 's')
	{
		char_init(e, &str);
		if (str == NULL)
			return (null_str(e));
		e->out = ft_strdup((char*)str);
		print_str(e);
	}
	else if (type == 'c')
	{
		int_init(e, &st);
		print_char(e, st);
	}
}

void	spec_unsint(t_printf *e, char type)
{
	long long			tmp;

	e->flag.sp = 0;
	e->flag.plus = 0;
	long_long_init(e, &tmp);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (type == 'D' || type == 'U')
		e->out = ft_uintmax_itoa((unsigned long long)tmp);
	else if (e->modifier == h)
		e->out = ft_uintmax_itoa((unsigned short)tmp);
	else if (e->modifier == hh)
		e->out = ft_uintmax_itoa((unsigned char)tmp);
	else if (e->modifier == none)
		e->out = ft_uintmax_itoa((unsigned int)tmp);
	else if (e->modifier == l || e->modifier == j)
		e->out = ft_uintmax_itoa((unsigned long)tmp);
	else if (e->modifier == ll)
		e->out = ft_uintmax_itoa((unsigned long long)tmp);
	else if (e->modifier == z)
		e->out = ft_uintmax_itoa((size_t)tmp);
	print_digit(e);
}

void	spec_int(t_printf *e)
{
	long long	tmp;
	long long	i;

	long_long_init(e, &tmp);
	i = (long long)tmp;
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	e->flag.prec >= 0 ? e->flag.zero = 0 : 0;
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (e->modifier == hh)
		e->out = ft_itoa((char)i);
	else if (e->modifier == h)
		e->out = ft_itoa((short)i);
	else if (e->modifier == none)
		e->out = ft_itoa((int)i);
	else if (e->modifier == l)
		e->out = ft_itoa((long)i);
	else if (e->modifier == ll || e->modifier == j)
		e->out = ft_itoa((long long)i);
	else if (e->modifier == z)
		e->out = ft_itoa((size_t)i);
	print_digit(e);
}
