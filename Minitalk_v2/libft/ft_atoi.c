/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azizloubar <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 21:04:54 by azizlouba         #+#    #+#             */
/*   Updated: 2021/08/17 16:45:37 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace_is_negative(char *str, int i, int *np)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*np = *np * -1;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		np;
	int		ret;

	ret = 1;
	res = 0;
	np = 1;
	i = ft_isspace_is_negative(str, 0, &np);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res < 0 && (np == 1))
			ret = -1;
		else if (res < 0 && (np == -1))
			ret = 0;
		i++;
	}
	if (ret == 1)
		return (res * np);
	else
		return (ret);
}
