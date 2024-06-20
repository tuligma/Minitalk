/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:15:13 by npentini          #+#    #+#             */
/*   Updated: 2024/06/13 04:13:56 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *args, ...);
int	ft_putnbr_m(int num);
int	ft_putnbr_unsigned_m(unsigned int num);
int	ft_hex_m(unsigned long num, char lcase);
int	process_char_m(va_list ap);
int	process_string_m(va_list ap);
int	process_pointer_m(va_list ap);
int	process_decimal_m(va_list ap);
int	process_integer_m(va_list ap);
int	process_unsigned_int_m(va_list ap);
int	process_hexadecimal_low_m(va_list ap);
int	process_hexadecimal_up_m(va_list ap);
int	process_percent_m(va_list ap);

#endif