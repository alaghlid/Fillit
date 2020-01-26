/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:13:46 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/09 18:15:06 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		last;
	int		first;
	char	c;

	first = 0;
	last = 0;
	while (str[last] != '\0')
		last++;
	last--;
	while (first <= last)
	{
		c = str[first];
		str[first] = str[last];
		str[last] = c;
		first++;
		last--;
	}
	return (str);
}
