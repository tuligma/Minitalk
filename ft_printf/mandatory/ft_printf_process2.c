/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:54:51 by npentini          #+#    #+#             */
/*   Updated: 2024/06/13 03:58:10 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	process_integer_m(va_list ap)
{
	return (process_decimal_m(ap));
}

int	process_unsigned_int_m(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	return (ft_putnbr_unsigned_m(num));
}

int	process_hexadecimal_low_m(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	return (ft_hex_m(num, 'a'));
}

int	process_hexadecimal_up_m(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	return (ft_hex_m(num, 'A'));
}

int	process_percent_m(va_list ap)
{
	(void)ap;
	return (write(1, "%", 1));
}
