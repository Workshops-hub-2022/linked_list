/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** utils_list
*/

#include "my.h"

bool is_empty_list(list_element_t *li)
{
    if (li == NULL)
        return (true);
    return (false);
}

int length_list(list_element_t *li)
{
    int size = 0;

    while (li != NULL) {
        size++;
        li = li->next;
    }

    return (size);
}

void print_list(list_element_t *li)
{
    if (li == NULL) {
        printf("The list is empty\n");
        return;
    }

    while (li != NULL) {
        printf("%i\n", li->value);
        li = li->next;
    }
}
