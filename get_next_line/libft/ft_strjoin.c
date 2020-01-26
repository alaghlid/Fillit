/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:37:21 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/04 21:20:44 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 && s2)
	{
		if ((res = (char *)malloc(sizeof(char) * \
						(ft_strlen(s1) + ft_strlen(s2) + 1))))
		{
			i = 0;
			while (s1[i])
			{
				res[i] = s1[i];
				i++;
			}
			j = 0;
			while (s2[j])
				res[i++] = s2[j++];
			res[i] = '\0';
			return (res);
		}
		return (NULL);
	}
	return (NULL);
}
