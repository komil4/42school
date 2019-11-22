#include "fillit.h"

int check_size_tetr(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (!matrix[i])
	{
		j = 0;
		while (!matrix[i][j])
		{
			j++;
		}
		i++
	}
	if (i != 3 || j != 3)
		return (0);
	return (1);
}

int check_char_tetr(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (!matrix[i][j])
	{
		j = 0;
		while (!matrix[i][j])
		{
			if (!(matrix[i][j] == '#' || matrix[i][j] == ' '))
				return (0);
		}
	}
	return (1);
}

int check_tetr_form(char **matrix)
{
	int count;
	int i;
	int j;

	i = 0;
	count = 0;
	while (matrix[i][j])
	{
		j = 0;
		while (matrix[i][j])
		{
			count = count + count_adj(matrix, i, j);
			j++;
		}
		i++;
	}
	if (count >= 6)
		return (1)
	return (0);

}

int count_adj(char **matrix, int i, int j)
{
	int count;

	count = 0;
	if (i = 0)
		count = (matrix[i + 1][j] == "#" ? count + 1 : count);
	if (i = 3)
		count = (matrix[i - 1][j] == "#" ? count + 1 : count);
	if (j = 0)
		count = (matrix[i][j + 1] == "#" ? count + 1 : count);
	if (j = 3)
		count = (matrix[i][j - 1] == "#" ? count + 1 : count);
	return (count);
}

void tetr_char_replace(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (!matrix[i][j])
	{
		j = 0;
		while (!matrix[i][j])
		{
			if (matrix[i][j] == '#')
				matrix[i][j] = 1;
			if (matrix[i][j] == ' ')
				matrix[i][j] = 0;
		}
	}
}
