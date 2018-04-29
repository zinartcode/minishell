/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/30 19:29:52 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>
# define NONE "\033[0m"

typedef enum	e_tag
{
	null = 0,
	val
}				t_tag;

typedef struct	s_tags
{
	t_tag		tag;
	int			val;
}				t_tags;

typedef struct	s_flag
{
	int			sp;
	int			plus;
	int			neg;
	int			minus;
	int			hash;
	int			zero;
	int			prec;
	int			width;
}				t_flag;

typedef enum	e_mod
{
	none = 0,
	h,
	hh,
	l,
	ll,
	j,
	z,
	t
}				t_mod;

typedef	struct	s_printf
{
	va_list		ap[2];
	char		*out;
	t_tags		tags;
	t_flag		flag;
	t_mod		modifier;
	int			fd;
	int			i;
	int			ret;
}				t_printf;

/*
**				libft
*/

int				ft_atoi(const char *str);
char			*ft_itoa(intmax_t n);
char			*ft_itoa_base(intmax_t val, intmax_t base);
void			ft_lowcase(char *str);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_uintmax_itoa(uintmax_t n);
char			*ft_uintmax_itoa_base(uintmax_t n, int base);

/*
** 				ft_printf
*/

void			flag_init(t_flag *flag);
void			print_conversion(const char *restrict format, t_printf *t);
int				ft_printf(const char *restrict format, ...);

/*
**				parse_args
*/

void			set_modifier(const char *restrict format, t_printf *t);
void			set_width(t_printf *t);
void			set_precision(const char *restrict format, t_printf *t);
void			set_flag(const char *restrict format, t_printf *t);
void			set_tag(const char *restrict format, t_printf *t);

/*
**				parse_color
*/

void			set_format(const char *restrict format, t_printf *t);
void			set_text_color(const char *restrict format, t_printf *t);
void			set_bg_color(const char *restrict format, t_printf *t);
void			check_settings(const char *restrict format, t_printf *t);

/*
**				parse_data_types
*/

void			char_init(t_printf *t, char **tmp);
void			int_init(t_printf *t, int *tmp);
void			uintmax_t_init(t_printf *t, uintmax_t *tmp);
void			long_long_init(t_printf *t, long long *tmp);
void			wchar_init(t_printf *e, wchar_t *tmp);
void			wstr_init(t_printf *e, wchar_t **tmp);

/*
**				parse_spec
*/

void			get_spec_more(const char *restrict format, t_printf *t);
void			get_spec(const char *restrict format, t_printf *t);

/*
**				pparse_wf
*/

void			wstr_init(t_printf *e, wchar_t **tmp);
void			wchar_init(t_printf *e, wchar_t *tmp);
/*
**				print_base
*/

void			print_base(t_printf *e, char type, long long val);

/*
**				print_char
*/

void			null_char(t_printf *e);
void			print_char(t_printf *e, char c);

/*
**				print_digit
*/

void			print_digit(t_printf *e);

/*
**				print_extra
*/

void			init_base(t_printf *t, char type);
void			spec_char(t_printf *t, char type);
void			spec_unsint(t_printf *e, char type);
void			spec_int(t_printf *e);

/*
**				print_extra2
*/

void			spec_percent(t_printf *t);
void			spec_return(t_printf *t);
void			spec_wchar(t_printf *t, char type);
void			spec_ptr(t_printf *t, char type);

/*
**				print_ptr
*/

void			print_ptr(t_printf *e, char type);

/*
**				print_str
*/

void			print_str(t_printf *e);
void			null_str(t_printf *e);

/*
**				print_tools
*/

void			print_prec_width(t_printf *e);
char			*ft_str_prec(char *s1, int dot, int end, int hash);

/*
**				print_wstr
*/

void			ft_putwchar(wchar_t c);
void			print_wstr(t_printf *e, wchar_t *wc);

#endif
