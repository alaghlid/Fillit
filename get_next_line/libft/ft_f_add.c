/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:26:32 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/10 00:45:01 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_f_add(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = NULL;
	if (alst)
	{
		if (*alst == NULL)
		{
			*alst = new;
			return ;
		}
		temp = *alst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}
