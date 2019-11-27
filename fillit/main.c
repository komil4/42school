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


	

 	element = NULL;
	if (argc != 2)
		return(-1);
	element = create_elements(argv[1]);
	if (element != NULL)
	//printf("Elements created!");
	//print_elements(element);
	//printf("Elements created!");
	if (!check_elements(element))
	{
		//printf("Elements not good!");
		return (-1);
		
		//free_elements(element);
		//write("Incorrect file!", 15);
	}
	//solution();
	//free_elements(element);
	//print_sollution(*solution);
	//free(solution);
	return (1);
}
