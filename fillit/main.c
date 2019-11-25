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
	create_elements(element, argv[1]);
	if (!check_elements(element))
	{
		return (-1);
		//write("Incorrect file!", 15);
	}
	//solution();
	free_elements(element);
	//print_sollution(*solution);
	//free(solution);
	return (1);
}
