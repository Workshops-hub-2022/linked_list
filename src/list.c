/*
** EPITECH PROJECT, 2022
** Hub-Workshop
** File description:
** list
*/

#include "my.h"

list_element_t *new_elem(int value)
{
    list_element_t * element = malloc(sizeof(list_element_t));

    if (element == NULL)
        return (NULL);
    
    element->value = value;
    element->next = NULL;

    return (element);
}

list_element_t * add_elem_back(list_element_t *li, int value)
{
    list_element_t *new_element = new_elem(value);
    list_element_t *temp = li;

    if (li == NULL)
        return (new_element);

    if (new_element == NULL) {
        printf("Error: malloc failed\n");
        return (NULL);
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = new_element;

    return (li);
}

list_element_t *add_elem_front(list_element_t *li, int value)
{
    list_element_t *new_element = new_elem(value);

    if (new_element == NULL) {
        printf("Error: malloc failed\n");
        return (NULL);
    }

    new_element->next = li;

    return (new_element);
}
