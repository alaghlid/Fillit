/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:40:53 by alaghlid          #+#    #+#             */
/*   Updated: 2019/06/27 21:52:04 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_free_tab(char *tab)
{
	free(tab);
	ft_putstr("error\n");
	exit(0);
}

void	ft_check1(char *tab, int fd)
{
	if (tab[ft_strlen(tab) - 1] == '\n' || tab[0] == '\0'
			|| ft_strlen(tab) > 441)
	{
		close(fd);
		ft_free_tab(tab);
	}
	else
		close(fd);
}

char	*ft_read(int fd, char *tab)
{
	char	*l;
	int		cpt;
	char	*p1;
	char	*p2;

	cpt = 0;
	while (get_next_line(fd, &l) > 0)
	{
		cpt++;
		if (!(ft_strlen(l) == 0 || ft_strlen(l) == 4) || tab[0] == '\n'
				|| (l[0] != '\0' && cpt % 5 == 0))
		{
			free(l);
			close(fd);
			ft_free_tab(tab);
		}
		p1 = l;
		l = l[0] == '\0' ? "\n" : l;
		p2 = tab;
		tab = ft_strjoin(tab, l);
		free(p1);
		free(p2);
	}
	ft_check1(tab, fd);
	return (tab);
}
