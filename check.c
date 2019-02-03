/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:50:41 by anradix           #+#    #+#             */
/*   Updated: 2018/12/28 18:17:02 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_adj(char **str, int i, int j)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (str[i + 1] != NULL)
		str[i + 1][j] == '#' ? a++ : b++;
	if (i > 0)
		str[i - 1][j] == '#' ? a++ : b++;
	if (j < 3)
		str[i][j + 1] == '#' ? a++ : b++;
	if (j > 0)
		str[i][j - 1] == '#' ? a++ : b++;
	return (a);
}

int		ft_grid_is_valid(char **tmp, int i, int stop)
{
	int j;
	int pattern;
	int adj;

	pattern = 0;
	adj = 0;
	while (i <= stop)
	{
		j = 0;
		while (tmp[i][j] != '\n')
		{
			if (tmp[i][j] && tmp[i][j] != '.' && tmp[i][j] != '#')
				return (0);
			if (tmp[i][j] == '#')
			{
				pattern++;
				adj = adj + ft_is_adj(tmp, i, j);
			}
			j++;
		}
		if (j != 4)
			return (0);
		i++;
	}
	return (pattern != 4 || (adj != 6 && adj != 8)) ? 0 : 1;
}

int		ft_read_to_tmp(int fd, char *line, char **tmp, int len)
{
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && len < 140)
	{
		tmp[len++] = ft_strdup(line);
		free(line);
	}
	tmp[len] = NULL;
	if (len > 130 || len < 3)
	{
		free(line);
		return (0);
	}
	while (i <= len - 3)
	{
		if (i + 3 >= len || !(ft_grid_is_valid(tmp, i, i + 3)))
		{
			free(line);
			return (0);
		}
		i = i + 5;
	}
	free(line);
	return (i == len + 1) ? 1 : 0;
}

char	***ft_tmp_to_tab(char **tmp, char ***tab)
{
	int		a;
	int		i;

	a = 0;
	i = 0;
	while (i <= (int)(ft_tablen(tmp) - 3))
	{
		tab[a] = ft_cpy(tmp, tab[a],
		ft_topleft(tmp, i, i + 3, 0), ft_topleft(tmp, i, i + 3, 1));
		a++;
		i += 5;
	}
	return (tab);
}
