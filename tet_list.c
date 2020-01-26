/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 21:23:02 by alaghlid          #+#    #+#             */
/*   Updated: 2019/07/06 18:52:35 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetriminos	*ft_tet_new(t_tetriminos *head, char *str, int d1, int i)
{
	t_tetriminos	*new;
	t_tetriminos	*temp;
	int				d2;

	if (!(new = (t_tetriminos *)malloc(sizeof(t_tetriminos))))
		return (NULL);
	while (str[i] && d1 < 4)
	{
		d2 = 0;
		while (d2 < 4)
			new->tet[d1][d2++] = str[i++];
		d1++;
	}
	new->next = NULL;
	new->prev = NULL;
	if (head == NULL)
		return (new);
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (head);
}

t_tetriminos	*ft_tet(t_tetriminos *head, char *tab)
{
	char	*str;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i] == '\n' || tab[i + 1] == '\0')
		{
			n = tab[i] == '\n' ? i - j : i - j + 1;
			str = ft_strsub(tab, j, n);
			head = ft_tet_new(head, str, 0, 0);
			free(str);
			j = i + 1;
		}
		i++;
	}
	free(tab);
	return (head);
}
