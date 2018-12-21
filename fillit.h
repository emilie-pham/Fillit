/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:29:44 by anradix           #+#    #+#             */
/*   Updated: 2018/12/21 17:29:46 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_point
{
	int			i;
	int			j;
}				t_point;

int				ft_nb_pattern(char **tmp);
int				ft_topleft(char **tab, int i, int stop, int choose);
char			**ft_cpy(char **tmp, char **tab, int i, int j);
int				ft_read_to_tmp(int fd, char *line, char **tmp);
char			***ft_tmp_to_tab(char **tmp, char ***tab);
int				ft_free(int error, char **tmp, char ***tab);
int				ft_solver(char ***str);

#endif
