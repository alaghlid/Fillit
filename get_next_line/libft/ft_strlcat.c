/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:21:17 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/04 21:07:31 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sd;
	size_t	j;
	size_t	ss;
	size_t	ret;

	j = 0;
	ss = ft_strlen(src);
	if (size == 0)
		return (ss);
	sd = ft_strlen(dst);
	if (size <= sd)
		ret = size + ss;
	else
		ret = sd + ss;
	while (src[j] && sd < size - 1)
		dst[sd++] = src[j++];
	if (sd < size)
		dst[sd] = '\0';
	return (ret);
}
