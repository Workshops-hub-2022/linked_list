/*
** EPITECH PROJECT, 2022
** linked_list_element
** File description:
** free_list_element
*/

#include "my.h"

void free_element(list_element_t *li)
{
    li->next = NULL;
    free(li);
}

list_element_t *pop_elem_back(list_element_t *li)
{
    list_element_t *temp = li;

    if (is_empty_list(li)) {
        return (NULL);
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    free_element(temp);
    temp = NULL;
    return (li);
}

list_element_t *pop_elem_front(list_element_t *li)
{
    list_element_t *new = li->next;

    free_element(li);

    return (new);
}

void clear_list(list_element_t *li)
{
    while (li != NULL) {
        li = pop_elem_front(li);
    }
}

