#include "fdf.h"

void	write_map_col(t_map *map)
{
	int i;
	int space;

	i = 0;
	if (map->file[0][i])
		space = 1;
	while (map->file[0][i])
	{
		if (map->file[0][i] == ' '
		&& map->file[0][i + 1] != ' ')
			space++;
		i++;
	}
	map->cols = space;
	return ;
}

int		convert_map(t_map *map)
{
	int     i;
	int     j;
	char    **mas_str;

	write_map_col(map);
	create_map_matrix(map);
	i = 0;
	j = 0;
	while (i < map->rows)
	{
		mas_str = ft_strsplit(map->file[i], ' ');
		while (j < map->cols)
		{
			map->matrix[i][j] = ft_atoi(mas_str[j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	create_map_matrix(t_map *map)
{
	int i;

	map->matrix = (int**)ft_memalloc(sizeof(int**) * map->rows);
	i = 0;
	while (i < map->rows)
	{
		map->matrix[i] = (int*)ft_memalloc(sizeof(int*) * map->cols);
		i++;
	}
}