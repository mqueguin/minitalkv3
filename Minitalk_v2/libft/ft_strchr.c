/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azizloubar <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:50:11 by azizlouba         #+#    #+#             */
/*   Updated: 2021/01/18 14:56:43 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	c_c;

	i = 0;
	c_c = (unsigned char)c;
	while (s[i] && s[i] != c_c)
		i++;
	if (s[i] == '\0' && c_c != '\0')
		return (NULL);
	else
		return ((char *)&s[i]);
}
