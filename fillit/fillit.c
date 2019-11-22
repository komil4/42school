#include "fillit.h"

void ft_print_sollution(t_solution *solution)
{
	char **temp;

	temp = solution->map;
	while (*temp)
	{
		write (1, &(*temp), ft_strlen(*temp);
		temp++;
	}
}

void ft_element_preparation(t_element **element)
{
	t_element *temp;
	
	if(!elem)
		return(0);
	temp = elem;
	while(temp != NULL)
	{
		if (!check_elem_matrix(temp->matrix))
			return (0);		
		temp = temp->next;
	}
}

int ft_str_count(str)
{
	int count;

	if (*str)
		count = 1;
	else
		return (0);
	while (*str)
	{
		if (*str == 'n')
			count++;
		str++;
	}
	return (count);
}



int main(int argc, char **argv)
{
	t_element *element;

 	if (argc != 2)
		return(-1);
	if (!ft_create_element(element, argv[1]))
		return (-1);




	//read file
	//построчно читаем файл и пишем все в масивы
	//check чекаем входные данные
	if (!ft_check_elem(element))
	{
		return (-1);
		write("Incorrect file!", 15);
	}
	//preparation start char, start pozition
	//заполняем листы данными о символе заполнения
	ft_element_preparation(&element);
	//решение
	ft_solution();
	//зачистка листов
	ft_free(element);
	//вывод решения
	ft_print_sollution(t_solution *solution)
	//зачистка решения
	ft_free(solution);

	return (1);
}