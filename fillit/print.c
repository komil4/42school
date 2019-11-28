#include "fillit.h"

void print_elements(t_element *element)
{
    t_element *tmp;
    int i;
    int j;

    i = 0;
    j = 0;
    tmp = element;
    if (tmp == NULL)
        printf("null");
    while (tmp != NULL)
    {
        while (i < tmp->rows)
        {
            while (j < tmp->rows)
            {
                printf("%c", (char)(tmp->matrix[i][j] + 48));
                j++;
            }
            printf("\n");
            j = 0;
            i++;
        }
        printf("\n");
        i = 0;
        tmp = tmp->next;        
    }
}

void print_solution(t_solution *solution)
{
    t_solution *tmp;
    int i;
    int j;

    i = 3;
    j = 3;
    tmp = solution;
    if (tmp == NULL)
        printf("null");

    while (i < tmp->size + SOLUTION_BUF - 3)
    {
        while (j < tmp->size + SOLUTION_BUF - 3)
        {
            printf("%c", tmp->map[i][j]);
            j++;
        }
        printf("\n");
        j = 3;
        i++;
    }
    printf("\n");
    i = 0;       
}

void print_solution_char(t_solution *solution)
{
    t_solution *tmp;
    int i;
    int j;

    i = 0;
    j = 0;
    tmp = solution;
    if (tmp == NULL)    
        printf("null");

    while (i < tmp->size + SOLUTION_BUF)
    {
        while (j < tmp->size + SOLUTION_BUF)
        {
            printf("%c", (char)(tmp->map[i][j] + 48));
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
    printf("\n");
    i = 0;       
}