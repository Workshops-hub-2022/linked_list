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


typedef struct list_element_s {
    int value;
    struct list_element_s *next;
}list_element_t;

// list.c
list_element_t*new_elem(int value);
list_element_t*add_elem_back(list_element_t*li, int value);
list_element_t*add_elem_front(list_element_t*li, int value);

// free_list.cd
list_element_t*pop_elem_back(list_element_t*li);
list_element_t*pop_elem_front(list_element_t*li);
void clear_list(list_element_t*li);

// utils_list.c
int length_list(list_element_t*li);
void print_list(list_element_t*li);
bool is_empty_list(list_element_t*li);

#endif /* !MY_H_ */
