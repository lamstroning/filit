/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/28/19 17:29:50 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/04 12:36:40 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int		main(int argc, char **argv)
{
	t_list	*elems;
	int		fd;

	if (argc != 2)
	{
		ft_putendl("useage: ./fillit file");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	elems = read_elems(fd);
	fillit(elems);
	free(elems);
	return (0);
}
