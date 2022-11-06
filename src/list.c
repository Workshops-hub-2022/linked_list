/*
** EPITECH PROJECT, 2022
** Hub-Workshop
** File description:
** list
*/

#include "my.h"

list new_elem(int value)
{
    list element = malloc(sizeof(list));

    if (element == NULL)
        return (NULL);
    
    element->value = value;
    element->next = NULL;

    return (element);
}

list add_elem_back(list li, int value)
{
    list new_element = new_elem(value);
    list temp = li;

    if (li == NULL)
        return (new_element);

    if (new_element == NULL) {
        printf("Error: malloc failed\n");
        return (NULL);
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    new_element->next = li;

    return (li);
}

list add_elem_front(list li, int value)
{
    list new_element = new_elem(value);

    if (new_element == NULL) {
        printf("Error: malloc failed\n");
        return (NULL);
    }

    new_element->next = li;

    return (new_element);
}

bool is_empty_list(list li)
{
    if (li == NULL)
        return (true);
    return (false);
}

int length_list(list li)
{
    int size = 0;

    while (li != NULL) {
        size++;
        li = li->next;
    }

    return (size);
}

void print_list(list li)
{
    if (li == NULL) {
        printf("The list is empty\n");
        return;
    }

    while (li != NULL) {
        printf("%i", li->value);
        li = li->next;
    }
}
