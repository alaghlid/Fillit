/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:24:35 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/07 22:39:34 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len_n(int n)
{
	int		len;
	long	nb;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		nb = n * -1;
	}
	else
		nb = n;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	unsigned int	nb;
	char			*s;
	int				i;

	if ((s = (char *)malloc(sizeof(char) * ft_len_n(n))))
	{
		if (n < 0)
		{
			s[0] = '-';
			nb = n * -1;
		}
		else
			nb = n;
		s[ft_len_n(n)] = '\0';
		i = ft_len_n(n) - 1;
		if (n == 0)
			s[i] = '0';
		while (nb != 0)
		{
			s[i--] = nb % 10 + '0';
			nb /= 10;
		}
		return (s);
	}
	return (NULL);
}
