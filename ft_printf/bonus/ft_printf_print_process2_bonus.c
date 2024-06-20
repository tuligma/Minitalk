/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_process2_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:39:26 by npentini          #+#    #+#             */
/*   Updated: 2024/06/19 04:22:44 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	print_unsigned_int_b(t_flag *flags, unsigned int num, int o_len, int len)
{
	unsigned int	padding;
	int				count;

	count = 0;
	padding = 0;
	if (flags->width > len)
		padding = flags->width - len;
	while (flags->f_minus == 0 && padding-- > 0)
	{
		if (flags->f_zero == 1 && flags->precision == -1)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
	}
	while (flags->precision-- > o_len)
		count += write(1, "0", 1);
	if (o_len > 0)
		count += ft_putnbr_unsigned_b(num, 0);
	while (flags->f_minus == 1 && padding-- > 0)
		count += write(1, " ", 1);
	return (count);
}

int	print_hexadecimal_ext1_b(t_flag *flags, unsigned long long num, char lcase,
	int len)
{
	int	count;

	count = 0;
	if (num > 0 && flags->f_hash == 1 && flags->f_zero == 1)
	{
		if (flags->width > 0
			&& (flags->precision == -1 || flags->width <= (int)len))
		{
			if (lcase == 'a')
				count += write(1, "0x", 2);
			else
				count += write(1, "0X", 2);
			flags->f_hash = 0;
		}
	}
	return (count);
}

int	print_hexadecimal_ext2_b(t_flag *flags, unsigned long long num, char lcase,
	int *padding)
{
	int	count;

	count = 0;
	while (flags->f_minus == 0 && (*padding)-- > 0)
	{
		if (flags->f_zero == 1 && flags->precision == -1)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
	}
	if (flags->f_hash == 1 && num > 0)
	{
		if (lcase == 'a')
			count += write(1, "0x", 2);
		else
			count += write(1, "0X", 2);
	}
	return (count);
}

int	print_hexadecimal_low_up_b(t_flag *flags, unsigned long long num,
	char lcase, int o_len)
{
	int				len;
	int				padding;
	int				count;

	len = o_len;
	if (flags->precision > len)
		len = flags->precision;
	padding = 0;
	if (flags->width > len)
		padding = flags->width - len;
	count = print_hexadecimal_ext1_b(flags, num, lcase, len);
	if (count == 2 && padding >= 1)
		padding -= 2;
	if (num > 0 && flags->f_hash == 1 && flags->width > len)
		padding -= 2;
	count += print_hexadecimal_ext2_b(flags, num, lcase, &padding);
	while (flags->precision-- > o_len)
		count += write(1, "0", 1);
	if (o_len > 0)
		count += ft_hex_b(num, lcase, 0, 0);
	while (flags->f_minus == 1 && padding-- > 0)
		count += write(1, " ", 1);
	return (count);
}
