/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 00:25:36 by alaghlid          #+#    #+#             */
/*   Updated: 2019/03/30 13:42:30 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sdst;
	char	*ssrc;

	i = 0;
	sdst = (char *)dst;
	ssrc = (char *)src;
	while (i < n)
	{
		sdst[i] = ssrc[i];
		i++;
	}
	return (dst);
}
