/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:09:59 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/02 19:43:39 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_map
{
	char			**file;
	int				**matrix;
	int				cols;
	int				rows;
}					t_map;

typedef struct		s_element_gnl
{
	int						fd;
	char					*buf;
	struct s_element_gnl	*next;
}					t_element_gnl;

int					get_next_line(const int fd, char **line);
void				map_write(t_map *map, char **buf, int *i_tmp);
void   				fd_error(t_map *map);
t_map				*read_map(char *file_str);
void				error(t_map *map);
void 				print_map(t_map *map);
void				write_map_col(t_map *map);
int					convert_map(t_map *map);
void				free_map(t_map *map);
void				free_map_matrix(t_map *map);
void				free_map_file(t_map *map);
void				create_map_matrix(t_map *map);

#endif
