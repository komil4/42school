#ifndef FILLIT_H
#define FILLIT_H

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct	s_element
{
	char 		**matrix;
	char 		char_s;
	t_element	*next;
}				t_element;

typedef struct	s_solution
{
	char 		**map;
	int 		size;	
}				t_solution;

int ft_check_create_tetr(char *m_tetr, );

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