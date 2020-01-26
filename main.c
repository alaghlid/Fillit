/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 22:55:07 by alaghlid          #+#    #+#             */
/*   Updated: 2019/07/04 22:38:09 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char			*tab;
	char			**map;
	t_tetriminos	*head;
	int				n;
	int				fd;

	tab = ft_strnew(0);
	head = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (-1);
	}
	ft_check_n(argv[1]);
	fd = open(argv[1], O_RDONLY);
	tab = ft_read(fd, tab);
	ft_check(tab, 0, 0, 0);
	head = ft_tet(head, tab);
	ft_ipos(head);
	n = ft_size_map(head);
	map = ft_make_map(n);
	ft_back_track(head, head, map, n);
	return (0);
}

void	ft_check_n(char *str)
{
	char	c;
	int		fd;

	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		;
	if (c != '\n')
	{
		close(fd);
		ft_free_tab(NULL);
	}
}

void	ft_ipos(t_tetriminos *head)
{
	t_tetriminos	*temp;
	int				cpt;

	temp = head;
	cpt = 0;
	while (temp)
	{
		ft_position(temp, 0, 0, 0);
		ft_min(temp);
		ft_mv(temp);
		ft_max(temp);
		ft_npos(temp);
		temp->c = 'A' + cpt;
		cpt++;
		temp = temp->next;
	}
}

int		ft_size_map(t_tetriminos *head)
{
	t_tetriminos	*temp;
	int				cpt;
	int				n;

	temp = head;
	cpt = 0;
	n = 0;
	while (temp)
	{
		temp = temp->next;
		cpt++;
	}
	while (n <= 46340)
	{
		if (n * n >= cpt * 4)
			return (n);
		n++;
	}
	return (0);
}
