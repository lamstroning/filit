/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:54:32 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/16 13:48:48 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **begin_list, t_list *new)
{
	t_list *current;

	current = *begin_list;
	if (current == NULL)
		*begin_list = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
