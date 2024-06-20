/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:17:59 by npentini          #+#    #+#             */
/*   Updated: 2024/06/20 04:22:25 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	signal_handler(int signal)
{
	static int	buffer;
	static int	signal_count;
	int			bit;

	bit = 0;
	if (signal == SIGUSR2)
		bit = 1;
	buffer = (buffer << 1) | bit;
	signal_count++;
	if (signal_count == 8)
	{
		write(STDOUT_FILENO, &buffer, 1);
		buffer = 0;
		signal_count = 0;
	}
}

int	main(void)
{
	struct sigaction	signal_action;
	int					error;

	signal_action.sa_handler = signal_handler;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = 0;
	error = sigaction(SIGUSR1, &signal_action, NULL);
	if (error == -1)
	{
		printf("Something went wrong with the server");
		return (-1);
	}
	error = sigaction(SIGUSR2, &signal_action, NULL);
	if (error == -1)
	{
		printf("Something went wrong with the server");
		return (-1);
	}
	printf("\nlets talk mini!!!\n\n");
	printf("Server PID: %d\n", getpid());
	while (1)
		usleep(100);
	return (0);
}
