/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:12:26 by amartyne          #+#    #+#             */
/*   Updated: 2018/07/18 19:18:30 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LOW 0
# define UP 1
# define P 2
# define UNCO 3
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_struct
{
	char			plus;
	char			minus;
	char			space;
	char			hash;
	char			nul;
	int				width;
	int				precision;
	char			sp;
}					t_struct;
size_t				ft_strlen(const char *s);
int					ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putnbr(int n, int *len_res);
void				*ft_memcpy(void *restrict dst, const void *restrict src, \
size_t n);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
void				n_time(int i, int *len_res, char str);
void				ft_putunsnbr(unsigned int n, t_struct flags, int *len_res);
int					ft_itoa_base(long long int n, int base, int letter,\
t_struct flags);
void				word(char format, va_list ap, t_struct flags, int *len_res);
void				number(char format, va_list ap, t_struct flags,\
int *len_res);
int					ft_printf(char *format, ...);
int					count_bin(unsigned int numb);
void				unicode(wchar_t numb, t_struct flags, int mark,\
int *len_res);
void				ft_putunslnbr(unsigned long int n, t_struct flags,\
int *len_res);
void				uni_str(wchar_t *arr, t_struct flags, int *len_res);
void				ft_putlnbr(long long int n, t_struct flags, int *len_res);
int					convert(char format, va_list ap, t_struct flags);
t_struct			find_flag(char *str, int *i, va_list ap);
int					a_len(long long int n, int base, int len, long long *j);
void				if_flags(t_struct flags, int len, int *len_res);
void				next_fl(char *str, int *i, t_struct *flags);
int					if_flags_ito(t_struct flags, int len, int base, int letter);
void				for_minus(t_struct flags, int len, int base, int *len_res);
int					len_unco(int size);
void				ft_putstring(char const *s, t_struct flags, int *len_res);
void				ft_putnumber(long long int n, t_struct flags, int *len_res);
int					specifier(char *format, int *i, va_list ap, t_struct flags);
int					valid(char format);
void				not_spec(t_struct flags, int *len_res);
int					ft_itoa_base_int(unsigned int n, unsigned int base,\
int letter, t_struct flags);
int					ft_itoa_unslong(unsigned long n, unsigned long base,\
int letter, t_struct flags);
int					ft_itoa_max(uintmax_t n, uintmax_t base, int letter,\
t_struct flags);
void				ft_putmax(intmax_t n, t_struct flags, int *len_res);
t_struct			if_flags_d(t_struct flags, int *len, int *len_res);
void				ft_putschar(int n, t_struct flags, int *len_res);
void				for_h(char format, va_list ap, t_struct flags,\
int *len_res);
void				for_l(char format, va_list ap, t_struct flags,\
int *len_res);
void				for_ll(char format, va_list ap, t_struct flags,\
int *len_res);
void				for_hh(char format, va_list ap, t_struct flags,\
int *len_res);
void				ft_putwchr(wchar_t *s, t_struct flags, int *len_res);
int					ft_putwchar(wchar_t c);
int					for_p(t_struct flags, int len);
int					print_space(t_struct flags, int len, int base, int letter);
int					print_nul(t_struct flags, int len, int base, int letter);
int					print_nul_pr(t_struct flags, int len, int base, int letter);
int					specifier_j(char *format, int *i, va_list ap,\
t_struct flags);

#endif
