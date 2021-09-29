/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azizloubar <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:01:06 by azizlouba         #+#    #+#             */
/*   Updated: 2021/08/07 18:33:19 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] == c)
			return ((char *)str + len);
		len--;
	}
	return (NULL);
}
