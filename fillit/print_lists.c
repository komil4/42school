#include "fillit.h"

void print_elements(t_element *element)
{
    t_element *tmp;
    int i;

    i = 0;
    tmp = element;
    if (tmp == NULL)
        printf("null");
    while (tmp != NULL)
    {
        while (i <= tmp->rows)
        {
            printf("%s\n", tmp->matrix[i]);
            i++;
        }
        printf("\n");
        i = 0;
        tmp = tmp->next;        
    }
}
