#pragma once
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "common.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct sll {
    Node *head;
    Node *tail;
    size_t size;
} sll;

//SLL Operations
void sll_init(sll *list);
int sll_append(sll *list, const int data);
int sll_prepend(sll *list, const int data);
void sll_display(const sll * const list);
void sll_free(sll *list);
void sll_node_free(Node* node);
int sll_del_frontnode(sll *list);
int sll_del_backnode(sll *list);
size_t sll_list_size(const sll * const list);

