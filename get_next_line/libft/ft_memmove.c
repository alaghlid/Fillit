/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:00:05 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/07 20:11:13 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	if (src < dst)
	{
		if ((temp = (char *)malloc(sizeof(char) * len)))
		{
			ft_memcpy((void *)temp, src, len);
			ft_memcpy(dst, (void *)temp, len);
			free(temp);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
