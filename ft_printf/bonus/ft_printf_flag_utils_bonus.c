/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 04:41:10 by npentini          #+#    #+#             */
/*   Updated: 2024/06/13 04:07:06 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	flag_verifier_b(char c)
{
	char	*flag;
	int		x;

	flag = "-+ #0";
	x = 0;
	while (flag[x] != '\0' && flag[x] != c)
		x++;
	if (flag[x] == '\0')
		return (-1);
	return (x);
}

int	specifier_verifier_b(char c)
{
	char	*specifier;
	int		x;

	specifier = "cspdiuxX%";
	x = 0;
	while (specifier[x] != '\0' && specifier[x] != c)
		x++;
	if (specifier[x] == '\0')
		return (-1);
	return (specifier[x] + '0');
}

void	flag_identifier_b(const char *format, t_flag *flags)
{
	int	flag[5];
	int	x;
	int	j;

	x = 5;
	while (--x >= 0)
		flag[x] = 0;
	while (format[++x] != '\0' && specifier_verifier_b(format[x]) == -1)
	{
		if (x > 0 && (format[x - 1] >= '1' && format[x - 1] <= '9'))
			continue ;
		j = flag_verifier_b(format[x]);
		if (j != -1)
			flag[j] = 1;
	}
	flags->f_minus = flag[0];
	flags->f_plus = flag[1];
	flags->f_space = flag[2];
	flags->f_hash = flag[3];
	flags->f_zero = flag[4];
	if (format[x] != '\0')
	{
		flags->specifier = format[x];
		flags->distance = x;
	}
}

void	width_and_precision_b(const char *format, t_flag *flags)
{
	char	specifier;
	int		width;
	int		precision;
	int		x;

	specifier = flags->specifier;
	width = 0;
	precision = -1;
	x = -1;
	while (format[++x] != '\0' && format[x] != specifier && format[x] != '.')
	{
		if (format[x] >= '0' && format[x] <= '9')
			width = width * 10 + (format[x] - '0');
	}
	if (format[x] == '.')
	{
		precision = 0;
		while (format[++x] >= '0' && format[x] <= '9')
			precision = precision * 10 + (format[x] - '0');
	}
	flags->width = width;
	flags->precision = precision;
}

t_flag	*flag_initialization_b(const char *format)
{
	t_flag	*flags;

	flags = (t_flag *)malloc(sizeof(t_flag));
	if (flags == NULL)
		return (NULL);
	flags->specifier = '\0';
	flags->f_minus = 0;
	flags->f_plus = 0;
	flags->f_space = 0;
	flags->f_hash = 0;
	flags->f_zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->distance = 0;
	flag_identifier_b(format, flags);
	width_and_precision_b(format, flags);
	return (flags);
}
