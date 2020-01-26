/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:46:11 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/08 22:08:36 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	e;

	i = 0;
	if (!src && !dst)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	e = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == e)
			return (dst + i + 1);
		i++;
	}
	return (!c && n ? dst + i + 1 : NULL);
}
