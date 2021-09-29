/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:35:09 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/16 18:18:38 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_sig;

static	void	ft_signal(void)
{
	while (g_sig == 0)
		usleep(100);
	if (g_sig == 1)
		g_sig = 0;
}

static int	ft_isdigitminitalk(char *str)
{
	while (*str)
		if (!(ft_isdigit(*str++)))
			return (0);
	return (1);
}

static int	ft_send_zero_at_end(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!(ft_send_signal_0(pid)))
			return (0);
		i++;
		ft_signal();
	}
	return (1);
}

static int	ft_choose_signal(char *str, int pid)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (++j < 8)
		{
			if (128 >> j & str[i])
			{
				if (!(ft_send_signal_1(pid)))
					return (0);
				ft_signal();
			}
			else
			{
				if (!(ft_send_signal_0(pid)))
					return (0);
				ft_signal();
			}
		}
	}
	if (!(ft_send_zero_at_end(pid)))
		return (0);
	return (1);
}

static void	ft_check_errors(char **av)
{
	if (!av[2])
	{
		ft_putendl_fd("String is not valid. Please try again.", 2);
		exit(0);
	}
	if (!(ft_isdigitminitalk(av[1])))
	{
		ft_putendl_fd("1st Arg should be the PID. Please try again.", 2);
		exit(0);
	}
}

void	ft_handler(int sig)
{
	(void)sig;
	g_sig = 1;
	return ;
}

int	main(int ac, char **av)
{
	int	PID_OF_SERVER;

	PID_OF_SERVER = 0;
	if (ac != 3)
	{
		ft_putendl_fd("Args should be PID then a String! Please try again.", 2);
		exit(0);
	}
	else if (ac == 3)
	{
		signal(SIGUSR1, ft_handler);
		ft_check_errors(av);
		PID_OF_SERVER = ft_atoi(av[1]);
		if (PID_OF_SERVER < 1 || PID_OF_SERVER > 4194304)
		{
			ft_putendl_fd("PID number is not valid! Please try again.", 2);
			exit(0);
		}
		if (!(ft_choose_signal(av[2], PID_OF_SERVER)))
			exit(0);
	}
	return (0);
}
