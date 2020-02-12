/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:09:59 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/11 23:21:07 by bhoth            ###   ########.fr       */
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
	int				max_heigt;
	float			angle_x;
	float			angle_y;
	float			angle_z;
	float			zoom;
	float			zoom_z;
	float			dist;
	int				x0;
	int				y0;
	int				color;
	int				text_color;
	void			*mlx_ptr;
	void			*win_ptr;
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
void				draw(t_map *map);
float				max(float n1, float n2);
float				min(float n1, float n2);
float				mod(float n);
int					deal_key(int key, t_map *map);
void    			map_create(t_map *map);
void				print_text(t_map *map);
void 				point_rotation(float *x, float *y,
						float *z, t_map *map);
void				motion(float *x, float *x1,
						float *y, float *y1, t_map *map);
void				point_zoom(float *x, float *y,
						float *z, t_map *map);
void				point_proection(float *x, float *y,
						float *z, t_map *map);


#endif
