/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:20:17 by alaghlid          #+#    #+#             */
/*   Updated: 2019/06/29 19:29:55 by alaghlid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_npos
{
	int					nx;
	int					ny;
}						t_npos;

typedef struct			s_tetriminos
{
	char				tet[4][4];
	char				c;
	int					max_x;
	int					max_y;
	int					nmax_x;
	int					nmax_y;
	int					min_x;
	int					min_y;
	t_pos				p_s[4];
	t_npos				np_s[4];
	struct s_tetriminos	*prev;
	struct s_tetriminos *next;
}						t_tetriminos;
void					ft_check_n(char *str);
char					*ft_read(int fd, char *tab);
void					ft_check(char *tab, int i, int j, int t);
int						ft_free_tab(char *tab);
void					ft_check2(char *tab, int i, int cpt, int t);
void					ft_check1(char *tab, int fd);
t_tetriminos			*ft_tet_new(t_tetriminos *head, char *str,
		int d1, int i);
t_tetriminos			*ft_tet(t_tetriminos *head, char *tab);
void					ft_ipos(t_tetriminos *head);
void					ft_position(t_tetriminos *head, int d1, int d2, int i);
void					ft_min(t_tetriminos *temp);
void					ft_max(t_tetriminos *temp);
void					ft_npos(t_tetriminos *temp);
void					ft_mv(t_tetriminos *temp);
int						ft_size_map(t_tetriminos *head);
char					**ft_make_map(int n);
int						ft_place(char **map, t_tetriminos *temp, int n);
int						ft_mv_place(t_tetriminos *temp, int n);
int						ft_stock(char **map, t_tetriminos *temp, int n);
void					ft_free_map(char **map);
void					ft_re_position(t_tetriminos *temp);
void					ft_clear_c(t_tetriminos *temp, char **map);
void					ft_back_track(t_tetriminos *head, t_tetriminos *temp,
		char **map, int n);
void					ft_print_map(char **map, t_tetriminos *head);
void					ft_free_head(t_tetriminos *head);
#endif
