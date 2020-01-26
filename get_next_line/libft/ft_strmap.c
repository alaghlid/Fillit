/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:17:53 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/04 21:21:17 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ns;
	int		i;

	if (s)
	{
		if ((ns = (char *)malloc(ft_strlen(s) + 1)))
		{
			i = 0;
			while (s[i])
			{
				ns[i] = f(s[i]);
				i++;
			}
			ns[i] = '\0';
			return (ns);
		}
		return (NULL);
	}
	return (NULL);
}
