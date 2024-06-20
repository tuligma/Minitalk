/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_process1_ext_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 04:15:24 by npentini          #+#    #+#             */
/*   Updated: 2024/06/19 04:20:44 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	print_decimal_ext1_b(t_flag *flags, int *num, int len, int *padding)
{
	int	count;

	count = 0;
	if (flags->width > len)
	{
		*padding = flags->width - len;
		if (*num < 0 && flags->precision == len)
			(*padding)--;
	}
	if (*num < 0 && flags->precision == -1
		&& *padding > 0 && flags->f_zero == 1)
	{
		count += write(1, "-", 1);
		*num *= -1;
	}
	return (count);
}

int	print_decimal_ext2_b(t_flag *flags, int num, int *padding)
{
	int	count;

	count = 0;
	if ((flags->f_space == 1 || flags->f_plus == 1
			|| flags->f_zero == 1) && num > -1)
	{
		if (flags->f_space == 1 && flags->f_plus == 0)
		{
			count = write(1, " ", 1);
			(*padding)--;
		}
		else if (flags->f_zero == 1 && flags->f_plus == 1
			&& (flags->precision == -1 || flags->width <= flags->precision))
		{
			count = write(1, "+", 1);
			flags->f_plus = 0;
		}
		if (flags->f_zero == 1 && padding == 0)
		{
			count += write(1, "0", 1);
			(*padding)--;
		}
	}
	return (count);
}

int	print_decimal_ext3_b(t_flag *flags, int num, int final_num, int *padding)
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
	if (num < 0 && final_num == num)
		count += write(1, "-", 1);
	else if (num > -1 && flags->f_plus == 1)
		count += write(1, "+", 1);
	return (count);
}
