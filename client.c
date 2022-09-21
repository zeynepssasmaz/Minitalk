/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsasmaz <zsasmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:43:04 by zsasmaz           #+#    #+#             */
/*   Updated: 2022/09/20 21:43:33 by zsasmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_ok(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Process Successful");
}

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
		i = (i * 10) + (*str++ - '0');
	return (i);
}

void	ft_procces(int pid, int c)
{
	int				n;
	int				byt;
	unsigned char	ch;

	ch = c;
	byt = 8;
	n = 128;
	while (byt--)
	{
		if (ch / n)
		{
			ch -= n;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(150);
		n /= 2;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		byt;
	char	*msg;

	pid = ft_atoi(argv[1]);
	i = 0;
	if (argc != 3)
	{
		ft_printf("You failed.\n");
		return (0);
	}
	msg = argv[2];
	signal(SIGUSR1, ft_ok);
	while (msg[i])
	{
		ft_procces(pid, msg[i]);
		i++;
	}
	byt = 8;
	while (byt--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}
