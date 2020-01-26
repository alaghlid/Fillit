/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:55:15 by alaghlid          #+#    #+#             */
/*   Updated: 2019/03/30 13:43:58 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	e;
	char			*str;

	i = 0;
	e = (unsigned char)c;
	str = (char *)b;
	while (i < len)
	{
		str[i] = e;
		i++;
	}
	return (b);
}
