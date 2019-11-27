#include "fillit.h"

t_solution *solution(t_element *element)
{
    t_solution *solution;
    t_solution *char_solution;
    t_element *temp_element;
    t_solution *global_solution;

    solution = (t_solution*)malloc(sizeof(t_solution));
    solution->size = SIDE_SIZE;
    solution->map = create_solution_map();
    char_solution = (t_solution*)malloc(sizeof(t_solution));
    char_solution->size = SIDE_SIZE;
    char_solution->map = create_char_solution_map();
    if (find_solution(solution, element, char_solution, global_solution))
        return (global_solution);
    return (NULL);
}

int find_solution(t_solution *solution, t_element *element,
    t_solution *char_solution, t_solution *global_solution)
{
    t_solution  *temp_solution;
    t_solution  *temp_char_sollution;
    int         i;
    int         j;

    i = 0;
    j = 0;
    if (element == NULL)
        return (1);
    temp_solution = create_sollution(solution);
    temp_char_sollution = create_char_sollution(solution);
    while (i < solution->size + SOLUTION_BUF)
    {
        while (j < solution->size + SOLUTION_BUF) 
        {
            recovery_sollution(temp_solution, solution);
            paste_tetr_in_solution(temp_solution, temp_char_sollution,
                element,i, j);
            if (check_solution(temp_solution))
            {
                if (find_solution(solution, element->next,
                    char_solution, global_solution))
                    {
                        free_solution(solution);
                        free_solution(char_solution);
                        return (1);
                    }
            }
            j++;
        }
        j = 0;  
        i++;
    }
    return (0);
}

t_solution *create_sollution(t_solution *solution)
{
    t_solution *temp_solution;
    int i;

    i = 0;
    temp_solution = (t_solution*)malloc(sizeof(t_solution));
    temp_solution->size = solution->size;
    temp_solution->map = (char**)malloc(sizeof(char*) * (solution->size + SOLUTION_BUF));
    while (i < (solution->size + SOLUTION_BUF))
    {
        temp_solution->map[i] = ft_strdup(solution->map[i]); 
        i++;  
    }
    return (temp_solution);
}

t_solution *create_solution_map()
{
    char **map;
    int    i;
    int    j;

    i = 0;
    j = 0;
    map = (char**)malloc(sizeof(char*) + (SIDE_SIZE + SOLUTION_BUF));
    while (i < SOLUTION_BUF + SIDE_SIZE)
    {
        map[i] = (char*)malloc(sizeof(char) * (SOLUTION_BUF + SIDE_SIZE));
        while (j < SOLUTION_BUF + SIDE_SIZE) 
        {
            map[i][j] = 0;   
        }
        j = 0;
        i++;  
    }
}

t_solution *create_char_solution_map()
{
    char **map;
    int    i;
    int    j;

    i = 0;
    j = 0;
    map = (char**)malloc(sizeof(char*) + (SIDE_SIZE + SOLUTION_BUF));
    while (i < SOLUTION_BUF + SIDE_SIZE)
    {
        map[i] = (char*)malloc(sizeof(char) * (SOLUTION_BUF + SIDE_SIZE));
        while (j < SOLUTION_BUF + SIDE_SIZE) 
        {
            map[i][j] = ' ';   
        }
        j = 0;
        i++;  
    }
}

int check_solution(t_solution *solution)
{

}

void recovery_sollution(t_solution *temp_solution,
    t_solution *solution)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (i < SOLUTION_BUF + SIDE_SIZE)
    {
        while (j < SOLUTION_BUF + SIDE_SIZE) 
        {
            temp_solution->map[i][j] = solution->map[i][j];   
        }
        j = 0;
        i++;  
    }
}