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
	
	element = create_elements("tests/test_0");
	if (element == NULL)
	{	
		printf("error\n");
		return (0);
	}
	if (!check_elements(element))
	{
		free_elements(element);
		printf("error\n");
		return (0);
	}
	//print_elements(element);
	global_solution = solution(element, global_solution);
	//free_elements(element);
	print_solution(global_solution);
	//free(solution);
	return (1);
}
