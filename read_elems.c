/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:09:43 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/03 13:36:47 by variya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		size_of_elem(t_elem *elem, const char axis, const char cmp)
{
	int		elem_size;
	int		dim;
	int		i;

	if (axis != 'x' && axis != 'y')
		error_exit();
	dim = 1;
	if (axis == 'x')
		dim = 0;
	i = 0;
	elem_size = elem->pos[i][dim];
	while (++i < ELEM_SIZE)
	{
		if ((elem->pos[i][dim] > elem_size && cmp == '>') || \
			(elem->pos[i][dim] < elem_size && cmp == '<'))
			elem_size = elem->pos[i][dim];
	}
	if (cmp == '>')
		return (elem_size + 1);
	else
		return (elem_size);
}

void	normalize(t_elem *elem)
{
	int		i;
	int		min_x;
	int		min_y;

	min_x = size_of_elem(elem, 'x', '<');
	min_y = size_of_elem(elem, 'y', '<');
	i = -1;
	while (++i < ELEM_SIZE)
	{
		elem->pos[i][0] -= min_x;
		elem->pos[i][1] -= min_y;
	}
}

t_list	*create_elem(char *str_elem, char letter)
{
	int			i;
	int			point;
	t_elem		elem;
	t_list		*new;

	point = 0;
	i = 0;
	if (str_elem == NULL)
		error_exit();
	while (str_elem[i] != '\0')
	{
		if (str_elem[i] == '#')
		{
			elem.pos[point][0] = i % (ELEM_SIZE + 1);
			elem.pos[point][1] = i / (ELEM_SIZE + 1);
			elem.letter = letter;
			point++;
		}
		i++;
	}
	if (is_invalid_form(elem))
		return (NULL);
	normalize(&elem);
	new = ft_lstnew(&elem, sizeof(t_elem));
	return (new);
}

t_list	*read_elems(int fd)
{
	int			ret;
	char		letter;
	char		str_elem[MAP_SIZE + 2];
	t_list		*elems;
	t_list		*elem;

	if (fd < 0)
		error_exit();
	elems = NULL;
	letter = 'A';
	while ((ret = read(fd, str_elem, MAP_SIZE + 1)) && ret != -1)
	{
		str_elem[ret] = '\0';
		if (is_invalid_size(str_elem) || ft_lstlen(elems) >= 26)
			error_exit();
		elem = create_elem(str_elem, letter++);
		if (elem == NULL)
			free(elems);
		ft_lstappend(&elems, elem);
	}
	if (ret == -1 || elems == NULL || str_elem[20] == '\n')
		error_exit();
	return (elems);
}
