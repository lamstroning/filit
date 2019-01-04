/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:58:23 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/04 12:58:25 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	error_exit(void)
{
	ft_putendl("error");
	exit(1);
}

int		is_invalid_size(char *elem)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	if (elem == NULL)
		return (1);
	while (i < MAP_SIZE - 1)
	{
		if ((elem[i] != '.' && elem[i] != '#' && (i + 1) % (ELEM_SIZE + 1)) ||
			(elem[i] != '\n' && !((i + 1) % (ELEM_SIZE + 1))))
			return (1);
		if (elem[i] == '#')
			size++;
		i++;
	}
	if (size != ELEM_SIZE)
		error_exit();
	return (0);
}

int		is_exist(int x, int y, t_elem elem)
{
	int	i;

	i = -1;
	while (++i < ELEM_SIZE)
	{
		if (elem.pos[i][0] == x && elem.pos[i][1] == y)
			return (1);
	}
	return (0);
}

int		is_invalid_form(t_elem elem)
{
	int		i;
	int		x;
	int		y;
	int		sum;

	i = -1;
	sum = 0;
	while (++i < ELEM_SIZE)
	{
		x = elem.pos[i][0];
		y = elem.pos[i][1];
		sum += is_exist(x + 1, y, elem) + is_exist(x - 1, y, elem) \
			+ is_exist(x, y + 1, elem) + is_exist(x, y - 1, elem);
		if (sum < 1)
			error_exit();
	}
	if (sum < 5)
		error_exit();
	return (0);
}

void	freelst(t_list **alst)
{
	t_list	*lst;
	t_list	*nxtlst;

	lst = *alst;
	while (lst)
	{
		nxtlst = lst->next;
		free(&(lst->content));
		free(&(lst->content_size));
		free(lst);
		lst = nxtlst;
	}
	*alst = NULL;
}
