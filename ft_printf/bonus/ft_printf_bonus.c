/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:14:57 by npentini          #+#    #+#             */
/*   Updated: 2024/06/13 12:43:33 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	process_hub_b(va_list ap, int (**process)(va_list, t_flag*), t_flag *flags)
{
	char	*specifier;
	int		count;
	int		x;

	specifier = "cspdiuxX%";
	count = 0;
	x = 0;
	while (specifier[x] != '\0' && specifier[x] != flags->specifier)
		x++;
	if (specifier[x] == flags->specifier)
		count += process[x](ap, flags);
	else
		count = -1;
	return (count);
}

int	format_processor_b(va_list ap, const char *format, int *i)
{
	t_flag	*flags;
	int		(*process[9])(va_list ap, t_flag *flags);
	int		count;

	flags = flag_initialization_b(format);
	if (flags == NULL)
		return (-1);
	else if (flags->specifier == '\0')
		return (write(1, &format[*i], 1));
	process[0] = process_char_b;
	process[1] = process_string_b;
	process[2] = process_pointer_b;
	process[3] = process_decimal_b;
	process[4] = process_integer_b;
	process[5] = process_unsigned_int_b;
	process[6] = process_hexadecimal_low_b;
	process[7] = process_hexadecimal_up_b;
	process[8] = process_percent_b;
	count = process_hub_b(ap, process, flags);
	if (count == -1)
		count = write(1, &format[*i], 1);
	*i += flags->distance;
	free(flags);
	return (count);
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		x;
	int		i;
	int		result;

	va_start(ap, args);
	x = 0;
	i = -1;
	while (args[++i] != '\0')
	{
		if (args[i] == '%')
		{
			i++;
			result = format_processor_b(ap, args + i, &i);
			if (result == -1)
				return (-1);
			else
				x += result;
		}
		else
			x += write(1, &args[i], 1);
	}
	va_end(ap);
	return (x);
}
