/*
** EPITECH PROJECT, 2022
** Hub-Workshop
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct list_element
{
    int value;
    struct list_element *next;
}list_element, *list;

// list.c
list new_elem(int value);
list add_elem_back(list li, int value);
list add_elem_front(list li, int value);

// free_list.cd
list pop_elem_back(list li);
list pop_elem_front(list li);
void clear_list(list li);

// utils_list.c
int length_list(list li);
void print_list(list li);
bool is_empty_list(list li);

#endif /* !MY_H_ */
