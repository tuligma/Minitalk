/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:17:59 by npentini          #+#    #+#             */
/*   Updated: 2024/06/21 04:44:51 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned int	buffer;
	static unsigned int	signal_count;
	unsigned int		bit;
	pid_t				client_pid;

	(void)context;
	bit = 0;
	if (signal == SIGUSR2)
		bit = 1;
	buffer = (buffer << 1) + bit;
	signal_count++;
	client_pid = info->si_pid;
	if (signal_count == 8)
	{
		write(STDOUT_FILENO, &buffer, 1);
		buffer = 0;
		signal_count = 0;
		kill(client_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	signal_action;
	int					error1;
	int					error2;

	signal_action.sa_sigaction = signal_handler;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = SA_SIGINFO;
	error1 = sigaction(SIGUSR1, &signal_action, NULL);
	error2 = sigaction(SIGUSR2, &signal_action, NULL);
	if (error1 == -1 || error2 == -1)
	{
		ft_printf("%sOpps..Something went wrong!!!%s", BHRE, CR);
		ft_printf("😫 %s[ sigaction() returns -1 ]%s", BHBL, CR);
		return (-1);
	}
	ft_printf("\n%sLets talk mini with%s ", BBU, CR);
	ft_printf("%sMINITALK!!!%s\n\n", BHMA, CR);
	ft_printf("🖥  %sServer PID: %s%d%s\n\n", BHBL, BHGR, getpid(), CR);
	ft_printf("💬 %sRecieved Messages:%s\n\n", BHBL, CR);
	while (1)
		pause();
	return (0);
}
