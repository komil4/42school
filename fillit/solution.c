#include "fillit.h"

t_solution *solution(t_element *element)
{
    t_solution *solution;
    t_element *temp_element;

    solution = (t_solution*)malloc(sizeof(t_solution));
    solution->size = 

    


}

int find_solution(t_solution *solution,
    t_element *element, t_solution global_solution)
{
    int i;
    int j;

    while ()

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
