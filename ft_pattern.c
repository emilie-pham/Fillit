/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pattern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:36:55 by epham             #+#    #+#             */
/*   Updated: 2018/12/07 19:09:46 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

int	ft_pattern(void)
{
	char **tab;
	int  i;

	i = 0;
	if (!(tab = malloc(sizeof(char *) * 20)))
		return (0);
	tab[0] 	= ft_strdup("#...#...#...#");
	tab[1] 	= ft_strdup("####");
	tab[2] 	= ft_strdup("##..##");
	tab[3] 	= ft_strdup("#...##..#");
	tab[4] 	= ft_strdup("#..###");
	tab[5] 	= ft_strdup("#..##...#");
	tab[6] 	= ft_strdup("###..#");
	tab[7] 	= ft_strdup("##.##");
	tab[8] 	= ft_strdup("#...##...#");
	tab[9] 	= ft_strdup("##...##");
	tab[10] = ft_strdup("#..##..#");
	tab[11] = ft_strdup("##..#...#");
	tab[12] = ft_strdup("##...#...#");
	tab[13] = ft_strdup("#...###");
	tab[14] = ft_strdup("#.###");
	tab[15] = ft_strdup("#...#...##");
	tab[16] = ft_strdup("#...#..##");
	tab[17] = ft_strdup("###...#");
	tab[18] = ft_strdup("###.#");
	tab[19] = NULL;
	while (tab[i] && ft_strcmp("#...#...##", tab[i]) != 0)
		i++;
	return (i);
}

int		main(void)
{
	int	i;

	i = ft_pattern();
	printf("%d\n", i);
	return (1);
}