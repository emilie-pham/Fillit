/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:00:43 by anradix           #+#    #+#             */
/*   Updated: 2018/12/07 16:21:28 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_pos(char **shape, char **grid)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (shape[x])
	{
		while (shape[x][y])
		{
			if (shape[x][y] == '#')
				grid[i + x][i + y] = shape[x][y];
			i++;
		}
	}
}

void	ft_generate(void)
{
	char **grid;
	char **shape;
	int i = 0;

	shape = malloc(sizeof(char*) * 4);
	grid = malloc(sizeof(char*) * 4);
	while (i < 4)
	{
		shape[i] = malloc(sizeof(char*) * 4);
		grid[i] = malloc(sizeof(char*) * 4);
		i++;
	}
	shape[i] = NULL;
	shape[0] = "....\n"; shape[1] = ".#..\n"; shape[2] = ".#..\n"; shape[3] = ".##.\n";

	grid[i] = NULL;
	grid[0] = "....\n"; grid[1] = "....\n"; grid[2] = "....\n"; grid[3] = "....\n";
}

void	ft_print(void)
{
	printf("\nAffichage de la grille vide\n");
	while (grid[i])
	{
		printf("%s", grid[i]);
		i++;
	}
	printf("\nAffichage de la piece\n");
	i = 0;
	while (i < 4)
	{
		printf("%s", shape[i]);
		i++;
	}
	ft_pos(shape, grid);
}

int		main(void)
{
	ft_generate();
	ft_print();
	return (1);
}
