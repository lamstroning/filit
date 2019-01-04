/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:25:33 by drdraugr          #+#    #+#             */
/*   Updated: 2019/01/03 22:46:34 by variya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	free_map(char ***map)
{
	int		i;
	int		size;

	i = -1;
	size = sizeof(*map) / sizeof(*map[0]);
	if (*map == NULL)
		return ;
	if (*map != NULL)
	{
		while (++i < size)
			free(*map[i]);
		free(*map);
		*map = NULL;
	}
}

char	**init_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = (char **)malloc(sizeof(char *) * size);
	if (map == NULL)
		error_exit();
	while (++i < size)
	{
		j = -1;
		map[i] = (char *)malloc(sizeof(char) * size);
		while (++j < size)
			map[i][j] = '.';
	}
	return (map);
}

void	put_on_map(char ***map, t_elem *elem, int point[2], char c)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (++i < ELEM_SIZE)
	{
		x = elem->pos[i][0] + point[0];
		y = elem->pos[i][1] + point[1];
		(*map)[y][x] = c;
	}
}

int		is_possible_to_put(char **map, t_elem *elem, int point[2])
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (++i < ELEM_SIZE)
	{
		x = elem->pos[i][0] + point[0];
		y = elem->pos[i][1] + point[1];
		if (map[y][x] != '.')
			return (0);
	}
	return (1);
}

void	print_map(char **map, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
}
