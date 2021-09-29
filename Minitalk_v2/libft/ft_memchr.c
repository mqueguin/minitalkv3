/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azizloubar <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:58:44 by azizlouba         #+#    #+#             */
/*   Updated: 2020/09/09 14:51:53 by azizlouba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_c;
	unsigned char	c_c;

	s_c = (unsigned char *)s;
	c_c = (unsigned char)c;
	i = 0;
	while (i < n && s_c[i] != c_c)
		i++;
	if (i == n)
		return (NULL);
	else
		return (&s_c[i]);
}
