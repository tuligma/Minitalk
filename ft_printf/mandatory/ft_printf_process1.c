/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:52:38 by npentini          #+#    #+#             */
/*   Updated: 2024/06/13 04:08:22 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	process_char_m(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	return (write(1, &c, 1));
}

int	process_string_m(va_list ap)
{
	char	*str;
	int		x;
	int		count;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	x = -1;
	count = 0;
	while (str[++x] != '\0')
		count += write(1, &str[x], 1);
	return (count);
}

int	process_pointer_m(va_list ap)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long) va_arg(ap, void *);
	if (addr == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_hex_m(addr, 'a');
	return (count);
}

int	process_decimal_m(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	return (ft_putnbr_m(num));
}
