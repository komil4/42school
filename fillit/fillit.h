#ifndef FILLIT_H
#define FILLIT_H

# define BUFF_SIZE 32
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_element
{
	char 				**matrix;
	char 				char_s;
	struct s_element	*next;
}				t_element;

typedef struct	s_solution
{
	char 		**map;
	int 		size;	
}				t_solution;

typedef struct        s_element_g
{
    int						fd;
    char					*buf;
    struct s_element_g		*next;
}                     t_element_g;

int get_next_line(const int fd, char **line);

void tetr_char_replace(char **matrix);
int count_adj(char **matrix, int i, int j);
int check_tetr_form(char **matrix);
int check_char_tetr(char **matrix);
int check_size_tetr(char **matrix);
int	check_element(char **mas);
int check_elements(t_element *element);
void create_elements(t_element *element, char *str);
void free_elements(t_element *element);

#endif
