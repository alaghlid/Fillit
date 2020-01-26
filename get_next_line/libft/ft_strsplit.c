/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:01:27 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/07 22:35:25 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_words(const char *str, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (str[i - 1] == c || i == 0)
				nb++;
		}
		i++;
	}
	return (nb);
}

static int		ft_str_len_word(const char *str, int i, char c)
{
	int len;

	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		d1;
	int		d2;
	int		i;
	char	**fstr;

	if (!s || !(fstr = (char **)malloc(sizeof(char *) * \
					(ft_nbr_words(s, c) + 1))))
		return (0);
	i = 0;
	d1 = 0;
	while (s[i] != '\0')
	{
		d2 = 0;
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			fstr[d1] = (char *)malloc(ft_str_len_word(s, i, c) + 1);
			while (s[i] && s[i] != c)
				fstr[d1][d2++] = s[i++];
			fstr[d1++][d2] = '\0';
		}
	}
	fstr[d1] = 0;
	return (fstr);
}
