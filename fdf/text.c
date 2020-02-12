#include "fdf.h"

void	print_text(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 10,
			map->text_color, "bhoth");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 50,
			map->text_color, "Projection : space");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 70,
			map->text_color, "Move : arrows");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 90,
			map->text_color, "Zoom : + - scroll");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 110,
			map->text_color, "Height : < >");
}