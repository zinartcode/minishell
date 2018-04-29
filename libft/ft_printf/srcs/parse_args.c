/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:35 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_width(t_printf *e)
{
	e->flag.width = va_arg(e->ap[0], int);
	if (e->flag.width < 0)
	{
		e->flag.width *= -1;
		e->flag.minus = 1;
	}
}

void	set_precision(const char *restrict format, t_printf *e)
{
	if (e->flag.prec >= 0)
	{
		e->i++;
		return ;
	}
	if (format[e->i] == '.' && format[e->i + 1] == '*')
	{
		e->flag.prec = va_arg(e->ap[0], int);
		e->i += 2;
	}
	else if (format[e->i] == '.')
	{
		e->i++;
		e->flag.prec = ft_atoi(format + e->i);
		while (format[e->i] >= '0' && format[e->i] <= '9')
			e->i++;
	}
}

void	set_modifier(const char *restrict format, t_printf *e)
{
	if (format[e->i] == 'h' && format[e->i + 1] != 'h' && e->modifier == none)
		e->modifier = h;
	else if (format[e->i] == 'h' && format[e->i + 1] == 'h'
			&& e->modifier == none)
	{
		e->modifier = hh;
		e->i++;
	}
	else if (format[e->i] == 'l' && format[e->i + 1] != 'l')
		e->modifier = l;
	else if (format[e->i] == 'l' && format[e->i + 1] == 'l')
	{
		e->modifier = ll;
		e->i++;
	}
	else if (format[e->i] == 'j')
		e->modifier = j;
	else if (format[e->i] == 'z')
		e->modifier = z;
}

void	set_flag(const char *restrict format, t_printf *e)
{
	while (format[e->i] == ' ' || format[e->i] == '#' || format[e->i] == '*'
	|| format[e->i] == '+' || (format[e->i] >= '0' && format[e->i] <= '9')
	|| format[e->i] == '-' || format[e->i] == '.' || format[e->i] == 'l'
	|| format[e->i] == 'h' || format[e->i] == 'j' || format[e->i] == 'z')
	{
		format[e->i] >= 'a' && format[e->i] <= 'z'
		? set_modifier(format, e) : 0;
		format[e->i] == ' ' ? e->flag.sp = 1 : 0;
		format[e->i] == '-' ? e->flag.minus = 1 : 0;
		format[e->i] == '+' ? e->flag.plus = 1 : 0;
		format[e->i] == '#' ? e->flag.hash = 1 : 0;
		format[e->i] == '*' ? set_width(e) : 0;
		format[e->i] == '0' ? e->flag.zero = 1 : 0;
		if (format[e->i] == '.')
			set_precision(format, e);
		else if (format[e->i] >= '1' && format[e->i] <= '9' && e->flag.prec < 0)
		{
			e->flag.width = ft_atoi(format + e->i);
			while (format[e->i] >= '0' && format[e->i] <= '9')
				e->i++;
		}
		else
			e->i++;
	}
}

void	set_tag(const char *restrict format, t_printf *e)
{
	int	i;
	int tmp;

	flag_init(&e->flag);
	e->modifier = none;
	e->tags.tag = null;
	i = 0;
	if (format[e->i] >= '0' && format[e->i] <= '9')
	{
		tmp = ft_atoi(format + e->i);
		while (format[e->i + i] >= '0' && format[e->i + i] <= '9')
			i++;
	}
}
