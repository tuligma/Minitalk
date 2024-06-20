/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:30:18 by npentini          #+#    #+#             */
/*   Updated: 2024/06/13 04:05:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_m(int num)
{
	char	c;
	int		count;

	count = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (num < 0)
	{
		count += write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		count += ft_putnbr_m(num / 10);
	c = num % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_unsigned_m(unsigned int num)
{
	char	c;
	int		count;

	count = 0;
	if (num >= 10)
		count += ft_putnbr_unsigned_m(num / 10);
	c = num % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_hex_m(unsigned long num, char lcase)
{
	char	c;
	int		count;

	count = 0;
	if (num >= 16)
		count += ft_hex_m(num / 16, lcase);
	if (num % 16 < 10)
		c = '0' + (num % 16);
	else
		c = (num % 16) + (lcase - 10);
	count += write(1, &c, 1);
	return (count);
}
