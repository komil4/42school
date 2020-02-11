/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:09:59 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/10 21:12:44 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define HEIGHT	1080
# define WIDTH	1920
# define COLOR	0xffffff
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include "minilibx_macos/mlx.h"

typedef struct		s_map
{
	char			**file;
	int				**matrix;
	int				cols;
	int				rows;
	float			x;
	float			y;
	float			z;
	void			*mlx_ptr;
	void			*win_ptr;
	int				zoom;
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
void    			bresenham(float x, float y, float x1, 
						float y1, t_map *map);
void				draw(t_map *map);
float				max(float n1, float n2);
float				min(float n1, float n2);
float				mod(float n);

#endif
