/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:25:21 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/04 18:52:05 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_ELEMS 26
# define MAP_SIZE 20
# define ELEM_SIZE 4
# include "libft/libft.h"

typedef struct	s_elem
{
	int			pos[4][2];
	char		letter;
}				t_elem;

t_list			*create_elem(char *str_elem, char letter);
int				is_invalid_size(char *elem);
int				is_exist(int x, int y, t_elem elem);
int				is_invalid_form(t_elem elem);
t_list			*read_elems(int fd);
void			free_map(char	***map, int map_size);
char			**init_map(int size);
void			put_on_map(char ***map, t_elem *elem, int point[2], char c);
int				is_possible_to_put(char **map, t_elem *elem, int point[2]);
int				size_of_elem(t_elem *elem, const char axis, const char cmp);
int				is_map_filled(char ***map, t_list *elems, int map_size);
void			fillit(t_list *elems);
void			print_map(char **map, int size);
void			error_exit(void);
void			freelst(t_list **alst);

#endif
