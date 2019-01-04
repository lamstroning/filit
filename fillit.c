/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:52:41 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/04 12:52:43 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		is_map_filled(char ***map, t_list *elems, int map_size)
{
	int		pivot_point[2];
	t_elem	*elem;

	if (elems == NULL)
		return (1);
	pivot_point[1] = 0;
	elem = (t_elem *)elems->content;
	while (pivot_point[1] < map_size - size_of_elem(elem, 'y', '>') + 1)
	{
		pivot_point[0] = 0;
		while (pivot_point[0] < map_size - size_of_elem(elem, 'x', '>') + 1)
		{
			if (is_possible_to_put(*map, elem, pivot_point))
			{
				put_on_map(map, elem, pivot_point, elem->letter);
				if (is_map_filled(map, elems->next, map_size))
					return (1);
				else
					put_on_map(map, elem, pivot_point, '.');
			}
			pivot_point[0]++;
		}
		pivot_point[1]++;
	}
	return (0);
}

void	fillit(t_list *elems)
{
	char	**map;
	int		map_size;

	map_size = ft_sqrt(ft_lstlen(elems) * 4);
	map = init_map(map_size);
	while (!is_map_filled(&map, elems, map_size))
	{
		map_size++;
		free_map(&map);
		map = init_map(map_size);
	}
	print_map(map, map_size);
	free_map(&map);
}
