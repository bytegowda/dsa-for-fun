#pragma once
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "common.h"

typedef struct dll_node {
    int data;
    struct dll_node *next;
    struct dll_node *prev;
} dll_node;

typedef struct dll {
    dll_node *head;
    dll_node *tail;
    size_t size;
} dll;

//DLL Operations
void dll_init(dll *list);
int dll_append(dll *list, const int data);
int dll_prepend(dll *list, const int data);
void dll_display_from_head(const dll * const list);
void dll_display_from_tail(const dll * const list);
void dll_free(dll *list);
void dll_node_free(dll_node* node);
int dll_del_frontnode(dll *list);
int dll_del_backnode(dll *list);
size_t dll_list_size(const dll * const list);

