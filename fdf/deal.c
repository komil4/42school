#include "fdf.h"

void rotate_key(int key, t_map *map)
{
    if (key == 12)
        map->angle_x += 0.05;
    if (key == 13)
        map->angle_x -= 0.05;
    if (key == 0)
        map->angle_y += 0.05;
    if (key == 1)
        map->angle_y -= 0.05;
}

void zoom_key(int key, t_map *map)
{
    if (key == 78)
    {
        map->zoom -= 3;
        map->zoom_z = map->zoom_z * map->zoom / (map->zoom + 3);
    }
    if (key == 69)
    {
        map->zoom += 3;
        map->zoom_z = map->zoom_z * map->zoom / (map->zoom - 3);
    }
}

void zoom_z_key(int key, t_map *map)
{
    if (key == 43)
        map->zoom_z -= 1;
    if (key == 47)
        map->zoom_z += 1;
}

void xy_key(int key, t_map *map)
{
    if (key == 126)
        map->y0 -= 10;
    if (key == 125)
        map->y0 += 10;
    if (key == 123)
        map->x0 -= 10;
    if (key == 124)
        map->x0 += 10;
}

int		deal_key(int key, t_map *map)
{
    printf("%i\n", key);
    
    rotate_key(key, map); 
    zoom_key(key, map);
    zoom_z_key(key, map);
    xy_key(key, map);
    mlx_clear_window(map->mlx_ptr, map->win_ptr);
    draw(map);
    return (0);	
}
