/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:30:18 by npentini          #+#    #+#             */
/*   Updated: 2024/06/13 04:00:55 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_putnbr_b(int num, int is_length)
{
	char	c;
	int		count;

	count = 0;
	if (num == -2147483648)
	{
		if (is_length == 1)
			return (10);
		else
			return (write(1, "2147483648", 10));
	}
	else if (num < 0)
		num *= -1;
	if (num >= 10)
		count += ft_putnbr_b(num / 10, is_length);
	c = num % 10 + '0';
	if (is_length == 1)
		return (count + 1);
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_unsigned_b(unsigned int num, int is_length)
{
	char	c;
	int		count;

	count = 0;
	if (num >= 10)
		count += ft_putnbr_unsigned_b(num / 10, is_length);
	c = num % 10 + '0';
	if (is_length == 1)
		return (count + 1);
	count += write(1, &c, 1);
	return (count);
}

int	ft_hex_b(unsigned long num, char lcase, int is_length, int usage)
{
	char	c;
	int		count;

	count = 0;
	if (num >= 16)
		count += ft_hex_b(num / 16, lcase, is_length, usage);
	if (num % 16 < 10)
		c = '0' + (num % 16);
	else
		c = (num % 16) + (lcase - 10);
	if (is_length == 1)
		return (count + 1);
	if (usage == 1 && count == 0)
		count += write(1, "0x", 2);
	count += write(1, &c, 1);
	return (count);
}

int	ft_strlen_b(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}
