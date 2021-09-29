/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_Bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:34:03 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/16 18:19:26 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_print_buff(char *buff, int *i, int *first, int *eight)
{
	write(1, buff, ft_strlen(buff));
	if (buff[*i - 1] == '\0')
		write(1, "\n", 1);
	sgnal()
	*i = 0;
	*first = 0;
	*eight = 0;
}

void	ft_manage_bits(int bit)
{
	static int	i = 0;
	static int	eight_turns = 0;
	static int	first_occurence = 0;
	char		buff[1024];

	if (first_occurence == 0)
	{
		ft_memset(buff, 0, 1024);
		first_occurence = 1;
	}
	if (bit == 1)
		buff[i] = buff[i] | 128 >> eight_turns;
	eight_turns++;
	if (eight_turns == 8)
	{
		i++;
		eight_turns = 0;
		if (i == 1023 || buff[i - 1] == '\0')
			ft_print_buff(buff, &i, &first_occurence, &eight_turns);
	}
}

void	ft_check_bits(int signal)
{
	if (signal == SIGUSR1)
		ft_manage_bits(0);
	if (signal == SIGUSR2)
		ft_manage_bits(1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		signal(SIGUSR1, ft_check_bits);
		signal(SIGUSR2, ft_check_bits);
		while (1)
			;
	}
	else
		ft_putendl_fd("No Arguments Needed. Please try again.\n", 2);
	return (0);
}
