#include "fillit.h"

int main(int argc, char **argv)
{
	t_element *element;

 	if (argc != 2)
		return(-1);
	if (!create_elements(element, argv[1]))
		return (-1);
	if (!check_elements(element))
	{
		return (-1);
		write("Incorrect file!", 15);
	}
	solution();
	free_elements(element);
	print_sollution(t_solution *solution);
	free(solution);
	return (1);
}