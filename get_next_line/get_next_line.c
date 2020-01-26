/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:55:20 by alaghlid          #+#    #+#             */
/*   Updated: 2019/04/28 21:49:34 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*check_fd(int fd, t_list **list)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(list, tmp);
	return (tmp);
}

static int		read_file(const int fd, char **content)
{
	int		r1;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((r1 = read(fd, buf, BUFF_SIZE)))
	{
		buf[r1] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (r1);
}

static int		cpy_l(char **line, char *content)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != '\n')
		i++;
	if (!(*line = ft_strsub(content, 0, i)))
		return (0);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			r;
	static t_list	*l;
	t_list			*now;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || \
			!(now = check_fd(fd, &l)) || BUFF_SIZE < 1)
		return (-1);
	tmp = now->content;
	r = read_file(fd, &tmp);
	now->content = tmp;
	if (!r && !*tmp)
	{
		*line = "";
		return (0);
	}
	r = cpy_l(line, now->content);
	if (tmp)
	{
		r = tmp[r] == '\n' ? r + 1 : r;
		now->content = ft_strdup(&((now->content)[r]));
		free(tmp);
	}
	return (1);
}
