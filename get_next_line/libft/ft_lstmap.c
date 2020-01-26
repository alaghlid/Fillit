/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:47:32 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/08 17:32:01 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *t;

	if (lst)
	{
		if (!(t = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new = f(lst);
		lst = lst->next;
		t = new;
		while (lst)
		{
			t->next = f(lst);
			t = t->next;
			lst = lst->next;
		}
		free(t);
		return (new);
	}
	return (NULL);
}
