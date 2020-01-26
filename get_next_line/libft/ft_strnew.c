/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 01:34:05 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/04 21:10:45 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if ((s = (char *)malloc(size + 1)))
	{
		while (i <= size)
		{
			s[i] = 0;
			i++;
		}
		return (s);
	}
	return (NULL);
}
