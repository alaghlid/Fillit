/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:57:50 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/03 22:18:39 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*t;
	int		i;
	size_t	j;

	if (s)
	{
		i = 0;
		if ((t = (char *)malloc(sizeof(char) * (len + 1))))
		{
			j = start;
			while (s[j] && j < start + len)
				t[i++] = s[j++];
			t[i] = '\0';
			return (t);
		}
	}
	return (NULL);
}
