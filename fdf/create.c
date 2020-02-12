#include "fdf.h"

void    map_create(t_map *map)
{
    map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "FDF");
    map->x0 = 960;
	map->y0 = 540;
    map->angle_x = 1;
    map->angle_y = 0;
    map->angle_z = 1;
    map->color = 0xe80c0c;
	map->zoom = 10;
    map->zoom_z = 10;
    map->color = 0xe80c0c;
    map->text_color = 0xe80c0c;
}