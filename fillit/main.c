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
	// "tests/invalid_sample"

 	element = NULL;
	//if (argc != 2)
	//	return(-1);
	//printf("%s", argv[1]);
	//element = create_elements(argv[1]);
	
	element = create_elements("tests/test_0");
	if (element == NULL)
	{	
		printf("Error create!");
		return (0);
	}
	if (!check_elements(element))
	{
		free_elements(element);
		printf("Elements not good!");
		return (0);
	}
	//solution();
	//free_elements(element);
	//print_sollution(*solution);
	//free(solution);
	return (1);
}
