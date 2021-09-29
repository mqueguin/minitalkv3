/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:28:59 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/16 18:18:59 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_send_signal_0(int pid)
{
	int	failure;

	failure = kill(pid, SIGUSR1);
	if (failure != 0)
	{
		ft_putendl_fd("SIRGUSR1 Signal failed! Please try again.", 2);
		return (0);
	}
	return (1);
}

int	ft_send_signal_1(int pid)
{
	int	failure;

	failure = kill(pid, SIGUSR2);
	if (failure != 0)
	{
		ft_putendl_fd("SIGUSR2 Signal failed! Please try again.", 2);
		return (0);
	}
	return (1);
}
