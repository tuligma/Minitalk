/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:15:13 by npentini          #+#    #+#             */
/*   Updated: 2024/06/19 04:21:33 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		specifier;
	int		f_minus;
	int		f_plus;
	int		f_space;
	int		f_hash;
	int		f_zero;
	int		width;
	int		precision;
	int		distance;
}	t_flag;

int		ft_printf(const char *args, ...);
int		ft_putnbr_b(int num, int is_length);
int		ft_putnbr_unsigned_b(unsigned int num, int is_length);
int		ft_hex_b(unsigned long num, char lcase, int is_length, int usage);
int		ft_strlen_b(char *str);
int		process_char_b(va_list ap, t_flag *flags);
int		process_string_b(va_list ap, t_flag *flags);
int		process_pointer_b(va_list ap, t_flag *flags);
int		process_decimal_b(va_list ap, t_flag *flags);
int		process_integer_b(va_list ap, t_flag *flags);
int		process_unsigned_int_b(va_list ap, t_flag *flags);
int		process_hexadecimal_low_b(va_list ap, t_flag *flags);
int		process_hexadecimal_up_b(va_list ap, t_flag *flags);
int		process_percent_b(va_list ap, t_flag *flags);
int		print_string_b(t_flag *flags, char *str, int len, int print_null);
int		print_string_ext_b(t_flag *flags, char *str, int len, int print_null);
int		print_pointer_b(t_flag *flags, unsigned long addr, int len);
int		print_decimal_ext1_b(t_flag *flags, int *num, int len, int *padding);
int		print_decimal_ext2_b(t_flag *flags, int num, int *padding);
int		print_decimal_ext3_b(t_flag *flags, int num,
			int final_num, int *padding);
int		print_decimal_b(t_flag *flags, int num, int len, int o_len);
int		print_unsigned_int_b(t_flag *flags, unsigned int num,
			int o_len, int len);
int		print_hexadecimal_ext1_b(t_flag *flags, unsigned long long num,
			char lcase, int len);
int		print_hexadecimal_ext2_b(t_flag *flags, unsigned long long num,
			char lcase, int *padding);
int		print_hexadecimal_low_up_b(t_flag *flags, unsigned long long num,
			char lcase, int o_len);
int		flag_verifier_b(char c);
int		specifier_verifier_b(char c);
void	flag_identifier_b(const char *format, t_flag *flags);
void	width_and_precision_b(const char *format, t_flag *flags);
t_flag	*flag_initialization_b(const char *format);

#endif