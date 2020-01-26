/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:51:42 by alaghlid          #+#    #+#             */
/*   Updated: 2019/06/27 21:16:14 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check2(char *tab, int i, int cpt, int t)
{
	if (cpt > 4 || (tab[i + 1] == '\0' && cpt != 4))
		ft_free_tab(tab);
	if (tab[i] == '\n' && (tab[i + 1] == '\n' || cpt != 4))
		ft_free_tab(tab);
	if (tab[i] != '\n' && tab[i] != '.' && tab[i] != '#')
		ft_free_tab(tab);
	if ((tab[i] == '\n' || tab[i + 1] == '\0') && t != 3 && t != 4)
		ft_free_tab(tab);
}

void	ft_check(char *tab, int i, int j, int t)
{
	int cpt;

	cpt = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
		{
			cpt++;
			if (tab[i + 1] == '#')
				t++;
			if (tab[i + 4] == '#' && j < 13)
				t++;
		}
		ft_check2(tab, i, cpt, t);
		if (tab[i] == '\n' && cpt == 4 && (t == 3 || t == 4))
		{
			cpt = 0;
			t = 0;
			j = 0;
		}
		i++;
		j++;
	}
}
