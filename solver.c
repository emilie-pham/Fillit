/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:39:35 by anradix           #+#    #+#             */
/*   Updated: 2018/12/21 16:29:51 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_place(char **grid, char **tab, t_point point, int mapsize)
{
	int a;
	int b;

	a = 0;
	while (tab[a])
	{
		b = 0;
		while (tab[a][b])
		{
			if (tab[a][b] == '#' && ((point.j + b) >= mapsize ||
				(point.i + a) >= mapsize))
				return (0);
			else if (tab[a][b] == '#' && grid[point.i + a][point.j + b] != '.')
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	ft_place_delete(char **grid, char **tab, t_point point, char c)
{
	int a;
	int b;

	a = 0;
	while (tab[a])
	{
		b = 0;
		while (tab[a][b])
		{
			if (tab[a][b] == '#')
				grid[point.i + a][point.j + b] = c;
			b++;
		}
		a++;
	}
}

int		ft_backtrack(char **grid, char ***tab, char c, int mapsize)
{
	t_point point;

	point.i = 0;
	if (*tab == NULL)
		return (1);
	while (point.i < mapsize)
	{
		point.j = 0;
		while (point.j < mapsize)
		{
			if (ft_check_place(grid, *tab, point, mapsize) == 1)
			{
				ft_place_delete(grid, *tab, point, c);
				if (ft_backtrack(grid, ++tab, ++c, mapsize) == 1)
					return (1);
				tab--;
				c--;
				ft_place_delete(grid, *tab, point, '.');
			}
			point.j++;
		}
		point.i++;
	}
	return (0);
}

int		ft_solver(char ***tab)
{
	char		c;
	char		**grid;
	int			mapsize;

	c = 'A';
	if (!(mapsize = ft_sqrt(ft_triple_tablen(tab) * 4)))
		return (0);
	if (!(grid = ft_init_tab(mapsize, mapsize, '.')))
	{
		ft_tabdel(grid);
		return (0);
	}
	while (ft_backtrack(grid, tab, c, mapsize) == 0)
	{
		mapsize++;
		ft_tabdel(grid);
		if (!(grid = ft_init_tab(mapsize, mapsize, '.')))
		{
			ft_triple_tabdel(tab);
			ft_tabdel(grid);
			return (0);
		}
	}
	ft_printtabdl(grid);
	ft_tabdel(grid);
	return (1);
}
