#include "fdf.h"

void    bresenham(float x, float y, float x1, float y1, t_map *map)
{
	float x_step;
	float y_step;
	float tmp;

	x *= map->zoom;
	y *= map->zoom;
	x1 *= map->zoom;
	y1 *= map->zoom;

	x_step = x1 - x;
	y_step = y1 - y;
	tmp = max(mod(x_step), mod(y_step));
	x_step /= tmp;
	y_step /= tmp;
	while ((int)(x-x1) || (int)(y-y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, COLOR);
		x += x_step;
		y += y_step;
	}
}


void draw(t_map *map)
{
	int x;
	int y;

	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "FDF");
	y = 0;
	map->zoom = 20;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			bresenham(x, y, x + 1, y, map);
			bresenham(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
	mlx_key_hook(map->win_ptr, 0, NULL);
	mlx_loop(map->mlx_ptr);
}