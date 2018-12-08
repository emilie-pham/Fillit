/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:48:00 by epham             #+#    #+#             */
/*   Updated: 2018/12/06 17:34:54 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct		list
{
	size_t			x1;
	size_t			x2;
	size_t			x3;
	size_t			x4;
	size_t			y1;
	size_t			y2;
	size_t			y3;
	size_t			y4;
	size_t			status;
	struct s_list	*next;
}					tetri;

#endif
