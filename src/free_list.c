/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** free_list
*/

#include "my.h"

void free_element(list li)
{
    li->next = NULL;
    free(li);
}

list pop_elem_back(list li)
{
    list temp = li;

    if (is_empty_list(li)) {
        free_element(li);
        return (NULL);
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    free_element(temp);

    return (li);
}

list pop_elem_front(list li)
{
    list new = li->next;

    free_element(li);

    return (new);
}

void clear_list(list li)
{
    while (li != NULL) {
        li = pop_elem_front(li);
    }
}

