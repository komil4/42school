#include "fdf.h"

void error(t_map *map)
{
    free_map(map);
    ft_putstr("error args\n");
    exit (0);
}

int main(int argc, char **argv)
{
    t_map	 	*map;

    map = NULL;
    if (argc != 2)
	    error(map);
	map = read_map(argv[1]);
    convert_map(map);
    print_map(map);
    free_map(map);
    exit (0);
}

void print_map(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map->rows)
    {
        while (j < map->cols)
        {
            printf("%3d", map->matrix[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}
