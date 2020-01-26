/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:24:41 by alaghlid          #+#    #+#             */
/*   Updated: 2019/07/04 22:11:56 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_re_position(t_tetriminos *temp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		temp->np_s[i].nx = temp->p_s[i].x;
		temp->np_s[i].ny = temp->p_s[i].y;
		i++;
	}
	temp->nmax_x = temp->max_x;
	temp->nmax_y = temp->max_y;
}

void	ft_clear_c(t_tetriminos *temp, char **map)
{
	int i;

	i = 0;
	if (temp)
	{
		while (i < 4)
		{
			map[temp->np_s[i].nx][temp->np_s[i].ny] = '.';
			i++;
		}
	}
}

void	ft_back_track(t_tetriminos *head, t_tetriminos *temp, char **map, int n)
{
	while (temp)
	{
		if ((ft_stock(map, temp, n)) == 0)
		{
			ft_re_position(temp);
			temp = temp->prev;
			ft_clear_c(temp, map);
			while (temp && (ft_mv_place(temp, n)) == 0)
			{
				ft_re_position(temp);
				temp = temp->prev;
				ft_clear_c(temp, map);
			}
			if (temp == NULL)
			{
				ft_free_map(map);
				map = ft_make_map(++n);
				temp = head;
			}
		}
		else
			temp = temp->next;
	}
	ft_print_map(map, head);
	ft_free_map(map);
}

void	ft_print_map(char **map, t_tetriminos *head)
{
	int d1;

	d1 = 0;
	if (head)
	{
		while (map[d1])
		{
			ft_putstr(map[d1++]);
			write(1, "\n", 1);
		}
	}
	ft_free_head(head);
}

void	ft_free_head(t_tetriminos *head)
{
	t_tetriminos *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
