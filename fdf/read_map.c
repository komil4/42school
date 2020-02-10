#include "fdf.h"

void	map_write(t_map *map, char **buf, int *i_tmp)
{
	char		**temp;
	int			i;

	temp = (char**)ft_memalloc(sizeof(char*) * (map->rows + 1));
	i = 0;
	while (i < map->rows)
	{
		temp[i] = ft_strdup(map->file[i]);
		ft_memdel((void**)(&(map->file[i])));
		i++;
	}
	temp[i] = ft_strdup(*buf);
	(*i_tmp)++;
	map->rows = *i_tmp;
	ft_memdel((void**)(&(map->file)));
	ft_memdel((void**)(&(*buf)));
	map->file = temp;
	return ;
}

void   fd_error(t_map *map)
{
	if (map)
		ft_memdel((void**)&map);
	ft_putstr("map error!");
	exit (0);
}

t_map	*read_map(char *file_str)
{
    t_map	*map;
    int     fd[2];
    int     i;
    char    *buf;

    fd[0] = open(file_str, O_RDONLY);
	if (fd[0] < 0)
		fd_error(NULL);
    map = (t_map*)ft_memalloc(sizeof(t_map));
	i = 0; 
    while ((fd[1] = get_next_line(fd[0], &buf)) > 0)
	{
        map_write(map, &buf, &i);
	}
	ft_memdel((void**)&buf);
	if (fd[1] < 0)
		fd_error(map);
	close(fd[0]);
	return (map);
}