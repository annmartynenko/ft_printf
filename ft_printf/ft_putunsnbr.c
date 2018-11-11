/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:30:26 by amartyne          #+#    #+#             */
/*   Updated: 2018/07/25 20:30:30 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putn(unsigned long n, int *len_res)
{
	int				len;
	long long int	j;

	j = 1;
	len = 0;
	len = a_len(n, 10, len, &j);
	if (n < 10)
		(*len_res) += ft_putchar((char)(n + '0'));
	else
	{
		ft_putn((n / 10), len_res);
		(*len_res) += ft_putchar((char)(n % 10 + '0'));
	}
}

void	ft_putunslnbr(unsigned long int n, a_struct flags, int *len_res)
{
	int				len;
	long long int	j;

	j = 1;
	len = 0;
	len = a_len(n, 10, len, &j);
	if_flags(flags, len, len_res);
	if (n != 0 || flags.precision != 0)
		ft_putn(n, len_res);
	if (flags.minus && flags.width > len)
		n_time((flags.width - len), len_res, ' ');
}

void	ft_putunsnbr(unsigned int n, a_struct flags, int *len_res)
{
	int				len;
	long long int	j;

	j = 1;
	len = 0;
	len = a_len(n, 10, len, &j);
	if_flags(flags, len, len_res);
	if (n < 10)
		(*len_res) += ft_putchar((char)(n + '0'));
	else
	{
		ft_putnbr((n / 10), len_res);
		(*len_res) += ft_putchar((char)(n % 10 + '0'));
	}
	if (flags.minus && flags.width > len)
		n_time((flags.width - len), len_res, ' ');
}

void	if_nb_n(long long *nb, int *len_res, long long n)
{
	if ((*nb) == -922337203685477580.8 * 10)
	{
		(*nb) = (*nb) % 1000000000000000000;
		(*nb) = -(*nb);
		(*len_res) += ft_putchar('-');
		(*len_res) += ft_putchar('9');
	}
	else if (n < 0)
	{
		(*nb) = -(*nb);
		*len_res += ft_putchar('-');
	}
}

void	ft_putlnbr(long long int n, a_struct flags, int *len_res)
{
	int				len;
	long long int	nb;
	long long int	j;

	j = 1;
	len = 0;
	nb = n;
	len = a_len(n, 10, len, &j);
	if_nb_n(&nb, len_res, n);
	if_flags(flags, len, len_res);
	if (nb < 10)
		(*len_res) += ft_putchar((char)(nb + '0'));
	else
	{
		ft_putlnbr((nb / 10), flags, len_res);
		(*len_res) += ft_putchar((char)(nb % 10 + '0'));
	}
	if (flags.minus && flags.width > len)
	{
		if (flags.plus)
			len++;
		if (flags.space)
			len++;
		n_time((flags.width - len), len_res, ' ');
	}
}
