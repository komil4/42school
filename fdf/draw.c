#include "fdf.h"

init_steps(float *steps, float x, float x1, float y, float y1)
{
	float tmp;

	steps[0] = x1 - x;
	steps[1] = y1 - y;
	tmp = max(mod(steps[0]), mod(steps[1]));
	steps[0] /= tmp;
	steps[1] /= tmp;
}

void    bresenham(float x, float y, float x1, float y1, t_map *map)
{
	float steps[2];
	float z;
	float z1;
	float z_tmp[2];

	z = map->matrix[(int)y][(int)x];
	z1 = map-> matrix[(int)y1][(int)x1];
	z_tmp[0] = z;
	z_tmp[1] = z1;
	point_rotation(&x, &y, &z, map);
	point_rotation(&x1, &y1, &z1, map);
	point_proection(&x, &y, &z, map);
	point_proection(&x1, &y1, &z1, map);
	point_zoom(&x, &y, &z, map);
	point_zoom(&x1, &y1, &z1, map);
	motion(&x, &x1, &y, &y1, map);
	init_steps(&steps, x, x1, y, y1);
	while ((int)(x - x1) || (int)(y-y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, z || z1 ? map->color : COLOR);
		x += steps[0];
		y += steps[1];
	}
}

void draw(t_map *map)
{
	int x;
	int y;
	
	y = 0;
	print_text(map);
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (x < map->cols - 1)
				bresenham(x, y, x + 1, y, map);
			if (y < map->rows - 1)
				bresenham(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
