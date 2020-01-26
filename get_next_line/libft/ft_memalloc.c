/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:16:43 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/04 21:09:16 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if ((s = (char *)malloc(size)))
	{
		while (i < size)
		{
			s[i] = 0;
			i++;
		}
		return ((void *)s);
	}
	return (NULL);
}
