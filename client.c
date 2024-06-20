/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:08:45 by npentini          #+#    #+#             */
/*   Updated: 2024/06/20 04:20:48 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

void	send_signal(int pid, int c)
{
	int	x;
	int	buffer[8];

	x = 8;
	while (--x >= 0)
	{
		if (c % 2 == 0)
			buffer[x] = SIGUSR1;
		else
			buffer[x] = SIGUSR2;
		c /= 2;
	}
	while (++x < 8)
	{
		kill(pid, buffer[x]);
		usleep(50);
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		pid;
	int		x;

	if (argc != 3)
	{
		printf("Argument error\n");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (str == NULL)
	{
		send_signal(pid, '\n');
		return (0);
	}
	x = -1;
	while (str[++x] != '\0')
		send_signal(pid, str[x]);
	send_signal(pid, '\n');
	return (0);
}
