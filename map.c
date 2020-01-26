/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:54:27 by alaghlid          #+#    #+#             */
/*   Updated: 2019/07/05 16:26:31 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_make_map(int n)
{
	char	**map;
	int		d1;
	int		d2;

	d1 = 0;
	d2 = 0;
	if (!(map = (char **)malloc(sizeof(char *) * n + 1)))
		return (NULL);
	map[n] = NULL;
	while (d1 < n)
	{
		if (!(map[d1] = (char *)malloc(sizeof(char) * n + 1)))
			return (NULL);
		map[d1][n] = '\0';
		d2 = 0;
		while (d2 < n)
			map[d1][d2++] = '.';
		d1++;
	}
	return (map);
}

int		ft_place(char **map, t_tetriminos *temp, int n)
{
	int i;

	i = 0;
	if (temp->nmax_y >= n || temp->nmax_x >= n)
		return (0);
	while (i < 4)
	{
		if (map[temp->np_s[i].nx][temp->np_s[i].ny] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		ft_mv_place(t_tetriminos *temp, int n)
{
	int i;

	i = 0;
	if (temp->nmax_y + 1 < n)
	{
		while (i < 4)
			temp->np_s[i++].ny++;
		temp->nmax_y++;
		return (1);
	}
	else if (temp->nmax_x + 1 < n)
	{
		temp->nmax_y = temp->max_y;
		while (i < 4)
		{
			temp->np_s[i].ny = temp->p_s[i].y;
			i++;
		}
		i = 0;
		while (i < 4)
			temp->np_s[i++].nx++;
		temp->nmax_x++;
		return (1);
	}
	return (0);
}

int		ft_stock(char **map, t_tetriminos *temp, int n)
{
	int i;

	i = 0;
	while (ft_place(map, temp, n) == 0)
	{
		if (ft_mv_place(temp, n) == 0)
			return (0);
	}
	while (i < 4)
	{
		map[temp->np_s[i].nx][temp->np_s[i].ny] = temp->c;
		i++;
	}
	return (1);
}

void	ft_free_map(char **map)
{
	int d1;

	d1 = 0;
	while (map[d1])
		free(map[d1++]);
	free(map);
	map = NULL;
}
