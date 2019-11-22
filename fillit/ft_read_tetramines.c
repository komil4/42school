#include "fillit.h"

int ft_create_elements(t_element *element,char *str)
{
	int			fd;
	char		*temp;
	t_element	*el_temp;

	fd = open(str, O_RDONLY)
	if(fd < 0 || fd == 1 || fd == 2)
		return (0);	
	i = 0;
	while (!get_next_line(fd, &temp))
	{
		if (i == 0)
		{
				
		}	



		 || !(*temp) || temp = "")
			el_temp = element;
			element = (*t_element)malloc(sizeof(t_element));	
			
			el_temp = el_temp->next;
			el_temp->matrix[i] = ft_strnew():
		}
		if (!(*temp) || temp = "")
			el_temp->matrix[i] = ft_strcpy(el_temp->matrix[i], temp);
		i++;
	}
	return (1);
}

t_element *ft_create_fitrst_list()
{
	t_element *element;

	element = (*t_element)malloc(sizeof(t_element));
}



char ***ft_new_line_mas(char ***mas)
{
	char	**temp;
	int		i;

	if (mas = NULL)
		return (NULL);
	temp = mas;
	while (temp[i])
		i++;
	mas = (**char)malloc(sizeof(**char) * i + 2);
	if (mas = NULL)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		mas[i] = ft_strcpy(temp[i])
		i++;
	}
	free(temp);
	mas[i] = ft_strnew();
	i++;
	mas[i] = NULL;
	return (&mas);
}

void ft_create_next_list()