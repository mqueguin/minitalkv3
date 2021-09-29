/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azizloubar <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 11:53:24 by azizlouba         #+#    #+#             */
/*   Updated: 2021/08/07 18:29:35 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size(long nb, size_t neg)
{
	size_t	size;
	long	tmp;

	size = 0;
	if (nb < 0)
		nb = -nb;
	tmp = nb;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	if (nb == 0)
		size = 1;
	else
		size = size + neg;
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	size_t	neg;
	long	nb;
	char	*str;

	nb = n;
	neg = 0;
	if (nb < 0)
	{
		neg++;
		nb = -nb;
	}
	size = ft_get_size(nb, neg);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (neg > 0)
		str[0] = '-';
	while (size-- > neg)
	{
		str[size] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
