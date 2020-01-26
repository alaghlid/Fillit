/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 22:21:44 by alaghlid          #+#    #+#             */
/*   Updated: 2019/07/05 16:54:21 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_position(t_tetriminos *temp, int d1, int d2, int i)
{
	while (d1 < 4)
	{
		d2 = 0;
		while (d2 < 4)
		{
			if (temp->tet[d1][d2] == '#')
			{
				temp->p_s[i].x = d1;
				temp->p_s[i++].y = d2;
			}
			d2++;
		}
		d1++;
	}
}

void	ft_max(t_tetriminos *temp)
{
	int max_y;
	int max_x;
	int i;

	i = 1;
	max_y = temp->p_s[0].y;
	max_x = temp->p_s[0].x;
	while (i < 4)
	{
		max_y = (temp->p_s[i].y > max_y) ? temp->p_s[i].y : max_y;
		max_x = (temp->p_s[i].x > max_x) ? temp->p_s[i].x : max_x;
		i++;
	}
	temp->max_y = max_y;
	temp->nmax_y = max_y;
	temp->max_x = max_x;
	temp->nmax_x = max_x;
}

void	ft_min(t_tetriminos *temp)
{
	int min_y;
	int min_x;
	int i;

	i = 1;
	min_y = temp->p_s[0].y;
	min_x = temp->p_s[0].x;
	while (i < 4)
	{
		min_y = (temp->p_s[i].y < min_y) ? temp->p_s[i].y : min_y;
		min_x = (temp->p_s[i].x < min_x) ? temp->p_s[i].x : min_x;
		i++;
	}
	temp->min_y = min_y;
	temp->min_x = min_x;
}

void	ft_npos(t_tetriminos *temp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		temp->np_s[i].nx = temp->p_s[i].x;
		temp->np_s[i].ny = temp->p_s[i].y;
		i++;
	}
}

void	ft_mv(t_tetriminos *temp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		temp->tet[temp->p_s[i].x][temp->p_s[i].y] = '.';
		temp->p_s[i].y = temp->p_s[i].y - temp->min_y;
		temp->p_s[i].x = temp->p_s[i].x - temp->min_x;
		temp->tet[temp->p_s[i].x][temp->p_s[i].y] = '#';
		i++;
	}
}
