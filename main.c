/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:27:29 by anradix           #+#    #+#             */
/*   Updated: 2018/12/21 17:29:52 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*tmp[140];
	char	***tab;

	line = NULL;
	tab = NULL;
	if (ac != 2)
		return (ft_free(0, tmp, tab));
	if (!(fd = open(av[1], O_RDONLY)) || !ft_read_to_tmp(fd, line, tmp))
		return (ft_free(1, tmp, tab));
	if (!(tab = ft_init_triple_tab(ft_nb_pattern(tmp), 4, 4, '.')) ||
		!(tab = ft_tmp_to_tab(tmp, tab)))
		return (ft_free(1, tmp, tab));
	if (!(ft_solver(tab)))
		return (ft_free(2, tmp, tab));
	return (ft_free(3, tmp, tab));
}
