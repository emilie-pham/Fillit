/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:49:04 by epham             #+#    #+#             */
/*   Updated: 2018/12/21 17:28:12 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nb_pattern(char **tmp)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (tmp[i])
	{
		if (ft_strlen(tmp[i]) != 4)
			len++;
		i++;
	}
	return (len + 1);
}

int		ft_topleft(char **tab, int i, int stop, int choose)
{
	int	j;
	int	left;
	int	top;
	int	bin;

	left = 4;
	bin = 0;
	while (i <= stop)
	{
		j = 0;
		if (ft_strchr(tab[i], '#') != NULL && bin == 0)
		{
			top = i;
			bin = 1;
		}
		while (tab[i][j])
		{
			if (tab[i][j] == '#' && j < left)
				left = j;
			j++;
		}
		i++;
	}
	return (choose == 0) ? top : left;
}

char	**ft_cpy(char **tmp, char **tab, int i, int j)
{
	int shape;
	int a;
	int b;
	int swp;

	a = 0;
	swp = j;
	shape = 0;
	while (shape < 4)
	{
		b = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == '#')
				shape++;
			tab[a][b] = tmp[i][j];
			j++;
			b++;
		}
		i++;
		a++;
		j = swp;
	}
	return (tab);
}

void	ft_tmpdel(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int		ft_free(int error, char **tmp, char ***tab)
{
	if (error == 0)
	{
		ft_putendl("usage: ./fillit input_tetriminos_file");
		return (0);
	}
	if (error == 3 || error == 2)
		ft_triple_tabdel(tab);
	if (error == 1 || error == 2)
		ft_putendl("error");
	ft_tmpdel(tmp);
	return (0);
}
