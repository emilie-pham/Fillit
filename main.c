/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:46:12 by epham             #+#    #+#             */
/*   Updated: 2018/12/07 18:14:45 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_error(int fd)
{
	(void)fd;
	return (1);
}

int		main(int ac, char **av)
{
	int fd;
	t_list 	*head;
	t_list 	*current;
	t_list	*new;
	t_list	*temp;
	char	*line;
	int		i;

	
	if (ac != 2)
		return (-1);
	if (!(fd = open(av[1], O_RDONLY)))
		return (-1);
	if (!ft_check_error(fd))
		return (-1);
	if (!(head = ft_lstnew("\0", 1)))
		return (-1);

// Créer un maillon à chaque nouvelle pièce

	current = head;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (i < 4)
		{
			temp = current->content;
			current->content = ft_strjoin(current->content, line);
			free(temp);
			i++;
			if (i == 4)
				current->content = ft_strtrim_chr(current->content, '.');
		}
		else
		{
			new = ft_lstnew("\0", current->content_size + 1);
			ft_pushback(&current, new);
			current = new;
			i = 0;
		}
		ft_strdel(&line);
	}

// Afficher tous les maillons 

	current = head;
	while (current)
	{
		ft_putendl(current->content);
		current = current->next;
	}

	if (get_next_line(fd, &line) == -1)
		return (-1);

	int		n;

	n = ft_sqrt(ft_lstlen(head) * 4);
	return (1);

// Créer un double tableau avec une case par pièce et les coordonées de chaque pièce dans la structure tetri

	char **tab;

	if (!(tab = malloc(sizeof(tetri) * ft_lstlen(head))))
		return (NULL);
	

}
