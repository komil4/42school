#include "fillit.h"

int get_min_solution_size(t_element *element)
{
    int	sqrt;
    int nbr;
    t_element *temp;

    temp = element;
    nbr = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        nbr++;
    }
	nbr = 4 * nbr * nbr;
    sqrt = 1;
	while (sqrt * sqrt < nbr)
		sqrt++;
	return (sqrt);
}

t_solution *create_new_solution_with_copy(t_solution *solution)
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

char **create_solution_map(int solution_size)
{
    char **map;
    int    i;
    int    j;

    i = 0;
    j = 0;
    map = (char**)malloc(sizeof(char*) * (solution_size + SOLUTION_BUF));
    while (i < SOLUTION_BUF + solution_size)
    {
        map[i] = (char*)malloc(sizeof(char) * (solution_size + SOLUTION_BUF));
        while (j < SOLUTION_BUF + solution_size) 
        {
            map[i][j] = 0;
            j++;   
        }
        j = 0;
        i++;  
    }
    return (map);
}

char **create_char_solution_map(int solution_size)
{
    char **map;
    int    i;
    int    j;

    i = 0;
    j = 0;
    map = (char**)malloc(sizeof(char*) * (solution_size + SOLUTION_BUF));
    while (i < SOLUTION_BUF + solution_size)
    {
        map[i] = (char*)malloc(sizeof(char) * (solution_size + SOLUTION_BUF));
        while (j < SOLUTION_BUF + solution_size) 
        {
            map[i][j] = '.';
            j++;   
        }
        j = 0;
        i++;  
    }
    return (map);
}

t_solution *create_char_solution(int solution_size)
{
    t_solution *solution;

    solution = (t_solution*)malloc(sizeof(t_solution));
    solution->size = solution_size;
    solution->map = create_solution_map(solution_size);
    return (solution);
}

t_solution *create_solution(int solution_size)
{
    t_solution *solution;

    solution = (t_solution*)malloc(sizeof(t_solution));
    solution->size = solution_size;
    solution->map = create_solution_map(solution_size);
    return (solution);
}

t_solution *solution(t_element *element, t_solution *global_solution)
{
    t_solution *solution;
    t_solution *char_solution;   
    int         min_solution_size;
    int sol;

    min_solution_size = get_min_solution_size(element);
    min_solution_size = 40;
    global_solution = create_char_solution(min_solution_size);
    solution = create_solution(min_solution_size);
    char_solution = create_char_solution(min_solution_size);

    //sol = find_solution(solution, element, char_solution, global_solution);
    //if (sol > 0)
    //return (global_solution);
    while (!(find_solution(solution, element, char_solution, global_solution)))
    {
        min_solution_size = min_solution_size + 1;
        solution = create_solution(min_solution_size);
        char_solution = create_solution(min_solution_size);
        global_solution = create_solution(min_solution_size);
    }
    return (global_solution);
}

void free_solution(t_solution *solution)
{
    int i;

    i = 0;
    while (i < solution->size + SOLUTION_BUF)
    {
        ft_strdel(&(solution->map[i]));
        i++;
    }
    free(solution->map);
    free(solution);    
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
    {
        //global_solution = create_solution(char_solution->size);
        recovery_solution(global_solution, char_solution);
        return (1);
    }
    temp_solution = create_solution(solution->size);
    temp_char_sollution = create_char_solution(solution->size);
    while (i < solution->size + SOLUTION_BUF - 3)
    {
        while (j < solution->size + SOLUTION_BUF - 3) 
        {
            recovery_solution(temp_solution, solution);
            recovery_solution(temp_char_sollution, char_solution);
            paste_tetr_in_solution(temp_solution, temp_char_sollution,
                element, i, j);
            //print_solution(temp_char_sollution);
            //print_solution_char(temp_solution);
            if (check_solution(temp_solution))
            {
                //print_solution_char(temp_solution);
                //print_solution(temp_char_sollution);
                if (find_solution(temp_solution, element->next,
                    temp_char_sollution, global_solution))
                    {
                        free_solution(temp_solution);
                        free_solution(temp_char_sollution);
                        return (1);
                    }
            }
            j++;
        }
        j = 0;  
        i++;
    }
    free_solution(temp_solution);
    free_solution(temp_char_sollution);
    return (0);
}

void paste_tetr_in_solution(t_solution *solution,
t_solution *char_sollution, t_element *element, int i, int j)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while (a < 4)
    {
        while (b < 4)
        {
            solution->map[a + i][b + j] = solution->map[a + i][b + j] + 
                element->matrix[a][b];
            if (element->matrix[a][b] == 1)
                char_sollution->map[a + i][b + j] = element->char_s;    
            else if (char_sollution->map[a + i][b + j] == 0)
                char_sollution->map[a + i][b + j] = '.';                       
            b++;
        }
        b = 0;
        a++;
    }
}

int check_char_solution(char **map, int i, int j, int size)
{
    if (map[i][j] > 1)
        return (0);
    if (map[i][j] > 0 && 
        (i < 3 || i > size + SOLUTION_BUF -4 ||
        j < 3 || j > size + SOLUTION_BUF -4))
        return (0);
    return (1);
}

int check_solution(t_solution *solution)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (i < SOLUTION_BUF + solution->size)
    {
        while (j < SOLUTION_BUF + solution->size) 
        {
            if (!check_char_solution(solution->map, i, j, solution->size))
                return (0);
            j++;   
        }
        j = 0;
        i++;  
    }
    return (1); 
}

void recovery_solution(t_solution *temp_solution,
    t_solution *solution)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (i < SOLUTION_BUF + solution->size)
    {
        while (j < SOLUTION_BUF + solution->size) 
        {
            temp_solution->map[i][j] = solution->map[i][j]; 
            j++;  
        }
        j = 0;
        i++;  
    }
}