/*
** EPITECH PROJECT, 2022
** Hub-Workshop
** File description:
** main
*/
#include "my.h"

list_element_t *create_all_list(char **av)
{
    int index = 1;
    list_element_t *list = NULL;

    while (av[index] != NULL) {
        list = add_elem_back(list, atoi(av[index]));
        if (!list) {
            return (NULL);
        }
        index++;
    }

    return (list);
}

int main(int ac, char **av)
{
    list_element_t *list = NULL;

    if (ac <= 2)
        return (84);

    list = create_all_list(av);
    print_list(list);

    return (1);
}
