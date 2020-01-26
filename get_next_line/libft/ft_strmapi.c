/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:26:18 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/04 21:24:34 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ns;
	unsigned int	i;

	if (s)
	{
		if ((ns = (char *)malloc(ft_strlen(s) + 1)))
		{
			i = 0;
			while (s[i])
			{
				ns[i] = f(i, s[i]);
				i++;
			}
			ns[i] = '\0';
			return (ns);
		}
		return (NULL);
	}
	return (NULL);
}
