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

void create_elements(t_element *element, char *str)
{
	int			fd;
	int 		i;
	char		*buf;
	t_element	*temp;

	fd = open(str, O_RDONLY);
	if (fd < 0 || fd == 1 || fd == 2)
		return;	
	i = 0;
	element = (t_element*)malloc(sizeof(t_element));
	temp = element;
	while (!get_next_line(fd, &buf))
	{
		if (i == 0)
			temp = (t_element*)malloc(sizeof(t_element));
		if (buf == NULL)
		{
			temp->next = (t_element*)malloc(sizeof(t_element));
			temp = temp->next;
			i = 0;
		}
		else
			temp->matrix[i] = ft_strcpy(temp->matrix[i], buf);
		i++;
	}
}

int check_element(char **mas)
{
	if (check_size_tetr(mas)
		&& check_char_tetr(mas)
		&& check_tetr_form(mas))
	{
		tetr_char_replace(mas);
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
		if (check_element(temp->matrix))
		{
			temp->char_s = (char)(65 + i);
			temp = temp->next;
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
