/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azizloubar <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:31:03 by azizlouba         #+#    #+#             */
/*   Updated: 2021/08/07 17:57:59 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	str = NULL;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = -1;
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == NULL)
		return (NULL);
	str[len_s1 + len_s2] = '\0';
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		str[len_s1 + i] = s2[i];
		i++;
	}
	return (str);
}
