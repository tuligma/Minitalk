/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:52:38 by npentini          #+#    #+#             */
/*   Updated: 2024/06/18 00:02:29 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	process_char_b(va_list ap, t_flag *flags)
{
	char	c;
	int		count;
	int		padding;

	c = (char)va_arg(ap, int);
	count = 0;
	padding = flags->width;
	if (padding > 1)
	{
		while (flags->f_minus == 0 && padding-- > 1)
			count += write(1, " ", 1);
		count += write(1, &c, 1);
		while (flags->f_minus == 1 && padding-- > 1)
			count += write(1, " ", 1);
	}
	else
		count += write(1, &c, 1);
	return (count);
}

int	process_string_b(va_list ap, t_flag *flags)
{
	char	*str;
	int		len;
	int		print_null;

	str = va_arg(ap, char *);
	print_null = 0;
	if (str == NULL && flags->precision > -1)
		print_null = 1;
	if (str == NULL)
		str = "(null)";
	len = 0;
	if (str != NULL)
		len = ft_strlen_b(str);
	if (flags->precision > -1 && flags->precision < len)
		len = flags->precision;
	return (print_string_b(flags, str, len, print_null));
}

int	process_pointer_b(va_list ap, t_flag *flags)
{
	unsigned long	addr;
	int				len;

	addr = (unsigned long) va_arg(ap, void *);
	if (addr > 0)
		len = ft_hex_b(addr, 'a', 1, 0) + 2;
	else
		len = 5;
	return (print_pointer_b(flags, addr, len));
}

int	process_decimal_b(va_list ap, t_flag *flags)
{
	int	num;
	int	len;
	int	o_len;
	int	count;

	num = va_arg(ap, int);
	count = 0;
	o_len = ft_putnbr_b(num, 1);
	if (num == 0 && flags->precision == 0)
		o_len = 0;
	len = o_len;
	if (num < 0 && flags->precision <= len)
		len++;
	if (flags->precision > len)
		len = flags->precision;
	if (flags->f_plus == 1 && num > -1 && flags->f_space == 0)
		len++;
	return (print_decimal_b(flags, num, len, o_len) + count);
}
