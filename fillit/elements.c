/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:43:28 by bhoth             #+#    #+#             */
/*   Updated: 2019/11/25 21:00:45 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_element *create_elements(char *str)
{
	int			fd;
	int 		i;
	char		*buf;
	t_element	*temp;
	t_element 	*element;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);	
	i = 0;
	element = (t_element*)malloc(sizeof(t_element));
	temp = element;
	while (get_next_line(fd, &buf) > 0)
	{
		if (*buf == FREE_STR_GNL)
		{
			if (temp->matrix == NULL)
			{
				free_elements(element);
				return (NULL);
			}
			temp->next = (t_element*)malloc(sizeof(t_element));
			temp = temp->next;
			i = 0;
		}
		else
		{
			temp->matrix = create_matrix(temp->matrix, i, buf);
			temp->next = NULL;
			i++;
			temp->rows = i;
		}		
	}
	return (element);
}

int check_element(char **mas, t_element *temp)
{
	if (check_size_tetr(mas, temp)
		&& check_char_tetr(mas)
		&& check_tetr_form(mas))
	{
		tetr_char_replace(temp);
		return (1);	
	}	
	return (0);
}

int check_elements(t_element *element)
{
	t_element *temp;
	int i;

	i = 0;
	temp = element;
	while (temp != NULL)
	{
		if (check_element(temp->matrix, temp))
		{
			temp->char_s = (char)(65 + i);
			temp = temp->next;
			i++;
		}
		else 
			return (0);
	}
	return (1);
}

void free_elements(t_element *element)
{
	t_element *temp;

	temp = element;
	if (temp != NULL)
	{
		if (temp->next != NULL)
			free_elements(temp->next);
		free(temp->matrix);
		free(temp);
	} 	
}

char **create_matrix(char **matrix, int count, char *buf)
{
	char **temp;
	int i;

	temp = (char**)malloc(sizeof(char*) * (count + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		temp[i] = ft_strdup(matrix[i]);
		i++;
	}
	temp[i] = ft_strdup(buf);
	free_element_matrix(matrix, count);
	free(matrix);
	return (temp);
}

void free_element_matrix(char **matrix, int count)
{
	int i;

	i = 0;
	while (i < count)
	{	
		if (*matrix != NULL)
			free(matrix[i]);
		i++;
	}
}