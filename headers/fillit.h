/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:18 by ggeordi           #+#    #+#             */
/*   Updated: 2019/12/15 17:26:33 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct			s_tetromino
{
	char				*body;
	char				letter;
}						t_tetromino;

t_list					**read_tetrominoes(int fd);

#endif
