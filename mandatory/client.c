/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:08:45 by npentini          #+#    #+#             */
/*   Updated: 2024/06/25 22:22:07 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

static void	send_signal(int pid, int c)
{
	int	x;
	int	buffer;
	int sig;

	x = 8;
	sig = 0;
	while (--x >= 0)
	{
		buffer = (c >> x) & 1;
		if (buffer == 0)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		kill(pid, sig);
		usleep(150);
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		pid;
	int		x;

	if (argc != 3)
	{
		ft_printf("%sArgument error:%s ", BHRE, BHBL);
		ft_printf("Please provide the correct %s", BHGR);
		ft_printf("server-PID%s and your %smessage%s!%s\n", BHBL, BHMA);
		ft_printf("message%s!%s\n", BHBL, CR);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	x = -1;
	while (str != NULL && str[++x] != '\0')
		send_signal(pid, str[x]);
	send_signal(pid, '\n');
	return (0);
}
