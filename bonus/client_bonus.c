/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:08:45 by npentini          #+#    #+#             */
/*   Updated: 2024/06/21 05:50:03 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static int	g_signal_recieved = 0;

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

static void	acknowledge_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		g_signal_recieved++;
	if (g_signal_recieved == 1)
	{
		ft_printf("Transmision starting ");
		ft_printf("from PID: %d\n", info->si_pid);
	}
	usleep(100);
}

static void	send_signal(int pid, int c)
{
	int	x;
	int	buffer[8];
	int	usleep_delay;

	usleep_delay = 100;
	if (c >= 128)
		usleep_delay = 150;
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
		usleep(usleep_delay);
	}
}

int	error_handler(struct sigaction *signal_action, int argc, int state)
{
	if (state == 0)
	{
		if (argc != 3)
		{
			ft_printf("%sArgument error:%s ", BHRE, BHBL);
			ft_printf("Please provide the correct ");
			ft_printf("%sserver-PID%s and ", BHGR, BHBL);
			ft_printf("your %smessage%s!%s\n", BHMA, BHBL, CR);
			return (1);
		}
	}
	else
	{
		if (sigaction(SIGUSR1, signal_action, NULL) == -1
			|| sigaction(SIGUSR2, signal_action, NULL) == -1)
		{
			ft_printf("%sOpps..Something went wrong!!!%s", BHRE, CR);
			ft_printf("😫 %s[ sigaction() returns -1 ]%s", BHBL, CR);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	signal_action;
	char				*str;
	int					pid;
	int					x;
	int					error;

	error = error_handler(NULL, argc, 0);
	if (error == 1)
		return (error);
	signal_action.sa_sigaction = acknowledge_signal;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = SA_SIGINFO;
	error = error_handler(&signal_action, argc, 1);
	if (error == 1)
		return (error);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	x = -1;
	while (str != NULL && str[++x] != '\0')
		send_signal(pid, (unsigned char)str[x]);
	send_signal(pid, '\n');
	ft_printf("Total signals recieved from PID %d:%d", pid, g_signal_recieved);
	return (0);
}
