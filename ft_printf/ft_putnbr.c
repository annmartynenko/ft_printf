/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:43:39 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/10 12:12:54 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len_res)
{
	if (n == -2147483648)
	{
		n = n % 1000000000;
		n = -n;
		(*len_res) += ft_putchar('-');
		(*len_res) += ft_putchar('2');
	}
	if (n < 0)
	{
		n = -n;
		(*len_res) += ft_putchar('-');
	}
	if (n < 10)
		(*len_res) += ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10, len_res);
		(*len_res) += ft_putchar(n % 10 + '0');
	}
}
