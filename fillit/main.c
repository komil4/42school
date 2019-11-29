/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:35:19 by bhoth             #+#    #+#             */
/*   Updated: 2019/11/25 21:03:57 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int get_tetr_count(t_element *element)
{
    int nbr;
    t_element *temp;

    temp = element;
    nbr = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        nbr++;
    }
	return (nbr);
}

int main(int argc, char **argv)
{
	t_element *element;
	t_solution *global_solution;
	// "tests/invalid_sample"

	if (argc == 500)
		return (0);
 	element = NULL;
	global_solution = NULL;
	//if (argc != 2)
	//	return(-1);
	//printf("%s", argv[1]);
	//element = create_elements(argv[1]);
	
	element = create_elements("tests/test_8");
	if (element == NULL)
	{	
		printf("error\n");
		return (0);
	}
	if (get_tetr_count(element) > 26
		||!check_elements(element))
	{
		free_elements(element);
		printf("error\n");
		return (0);
	}
	global_solution = solution(element, global_solution);
	print_solution(global_solution);
	free_elements(element);
	free_solution(global_solution);
	//free(solution);
	return (1);
}
