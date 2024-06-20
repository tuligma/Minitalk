/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:14:57 by npentini          #+#    #+#             */
/*   Updated: 2024/06/13 12:37:13 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_processor_m(va_list ap, char spec)
{
	int		(*process[9])(va_list ap);
	char	*str;
	int		x;
	int		count;

	process[0] = process_char_m;
	process[1] = process_string_m;
	process[2] = process_pointer_m;
	process[3] = process_decimal_m;
	process[4] = process_integer_m;
	process[5] = process_unsigned_int_m;
	process[6] = process_hexadecimal_low_m;
	process[7] = process_hexadecimal_up_m;
	process[8] = process_percent_m;
	str = "cspdiuxX%";
	count = 0;
	x = 0;
	while (str[x] != '\0' && str[x] != spec)
		x++;
	if (str[x] == spec)
		count += process[x](ap);
	else
		count += write(1, &spec, 1);
	return (count);
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		x;
	int		i;

	va_start(ap, args);
	x = 0;
	i = -1;
	while (args[++i] != '\0')
	{
		if (args[i] == '%')
			x += format_processor_m(ap, args[++i]);
		else
			x += write(1, &args[i], 1);
	}
	va_end(ap);
	return (x);
}
