/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:54:51 by npentini          #+#    #+#             */
/*   Updated: 2024/06/19 04:35:40 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	process_integer_b(va_list ap, t_flag *flags)
{
	return (process_decimal_b(ap, flags));
}

int	process_unsigned_int_b(va_list ap, t_flag *flags)
{
	unsigned int	num;
	int				o_len;
	int				len;

	num = va_arg(ap, int);
	o_len = ft_putnbr_unsigned_b(num, 1);
	if (num == 0 && flags->precision == 0)
		o_len = 0;
	len = o_len;
	if (flags->precision > len)
		len = flags->precision;
	if (flags->f_plus == 1 && flags->f_space == 0)
		len++;
	return (print_unsigned_int_b(flags, num, o_len, len));
}

int	process_hexadecimal_low_b(va_list ap, t_flag *flags)
{
	unsigned int	num;
	int				o_len;

	num = va_arg(ap, unsigned long long);
	o_len = ft_hex_b(num, 'a', 1, 0);
	if (num == 0 && flags->precision == 0)
		o_len = 0;
	return (print_hexadecimal_low_up_b(flags, num, 'a', o_len));
}

int	process_hexadecimal_up_b(va_list ap, t_flag *flags)
{
	unsigned int	num;
	int				o_len;

	num = va_arg(ap, unsigned long long);
	o_len = ft_hex_b(num, 'A', 1, 0);
	if (num == 0 && flags->precision == 0)
		o_len = 0;
	return (print_hexadecimal_low_up_b(flags, num, 'A', o_len));
}

int	process_percent_b(va_list ap, t_flag *flags)
{
	(void)ap;
	(void)flags;
	return (write(1, "%", 1));
}
