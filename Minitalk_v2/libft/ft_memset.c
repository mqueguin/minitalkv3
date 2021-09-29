/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azizloubar <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:38:28 by azizlouba         #+#    #+#             */
/*   Updated: 2020/09/08 15:48:02 by azizlouba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	curr;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	curr = (unsigned char)c;
	while (len-- > 0)
	{
		ptr[i] = curr;
		i++;
	}
	return (b);
}
