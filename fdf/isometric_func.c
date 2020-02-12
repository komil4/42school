#include "fdf.h"

void	point_rotation(float *x, float *y, float *z, t_map *map)
{
	*y = *y * cos(map->angle_x) + *z * sin(map->angle_x);
	*z = (-1) * *y * sin(map->angle_x) + *z * cos (map->angle_x);
	*x = *x * cos(map->angle_y) + *z * sin(map->angle_y);
	*z = (-1) * *x * sin(map->angle_x) + *z * cos (map->angle_y);
	*x = *x * cos(map->angle_z) + *y * sin(map->angle_z);
	*y = (-1) * *x * sin(map->angle_z) + *y * cos (map->angle_z);
}

void	motion(float *x, float *x1, float *y, float *y1, t_map *map)
{
	*x += map->x0;
	*y += map->y0;
	*x1 += map->x0;
	*y1 += map->y0;
}

void	point_zoom(float *x, float *y, float *z, t_map *map)
{
	*x *= map->zoom;
	*y *= map->zoom;
	*z *= map->zoom_z;
}

void	point_proection(float *x, float *y, float *z, t_map *map)
{
    *x = *x * map->dist / *z;
    *y = *y * map->dist / *z;
}
