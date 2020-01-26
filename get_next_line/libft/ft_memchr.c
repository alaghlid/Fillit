/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:48:16 by alaghlid          #+#    #+#             */
/*   Updated: 2019/03/31 20:55:35 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	e;
	char			*ss;

	i = 0;
	e = (unsigned char)c;
	ss = (char *)s;
	while (i < n)
	{
		if (e == (unsigned char)ss[i])
			return (ss + i);
		i++;
	}
	return (NULL);
}
