#include <dsa/dll.h>
#include <stdlib.h>
#include <stdio.h>

void dll_init(dll *list) {
    list->head = list->tail = NULL;
    list->size = 0;
}

void dll_node_free(dll_node* node) {
    if(node) {
        free(node);
        node = NULL;
    }
}

void dll_free(dll *list) {
    if(list->head) {
        dll_node *tmp = NULL;
        while(list->head != NULL) {
            DBG_PRINT(LVL_DBG, " data=%d\n", list->head->data);
            tmp = list->head->next;
            dll_node_free(list->head);
            list->head = tmp;
        }

        list->head = list->tail = NULL;
    }
}

int dll_append(dll *list, const int data) {
    dll_node *new_node = (dll_node*)malloc(sizeof(dll_node));
    if(NULL == new_node) {
        DBG_PRINT(LVL_ERR, "FATAL: Failed to MALLOC. Exit...\n");
        errno = ENOMEM;
        return -1;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(NULL == list->head) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }

    list->size++;
    return 0;
}

int dll_prepend(dll *list, const int data) {
    dll_node *new_node = (dll_node*)malloc(sizeof(dll_node));
    if(NULL == new_node) {
        DBG_PRINT(LVL_ERR, "FATAL: Failed to MALLOC. Exit...\n");
        errno = ENOMEM;
        return -1;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(NULL == list->head) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->head->prev = new_node;
        new_node->next = list->head;
        list->head = new_node;
    }

    list->size++;
    return 0;
}

void dll_display_from_head(const dll * const list) {
    if(list->head) {
        dll_node *tmp = list->head;
        int i=0;
        DBG_PRINT(LVL_INFO, "===== Printing DLL From Head - Start =========\n");
        while(tmp != NULL) {
            DBG_PRINT(LVL_INFO, "node = %d, data = %d\n", i, tmp->data);
            i++;
            tmp = tmp->next;
        }
        DBG_PRINT(LVL_INFO, "===== Printing DLL End =========\n");
    }
    DBG_PRINT(LVL_INFO, "List size = %ld\n", dll_list_size(list));
}

void dll_display_from_tail(const dll * const list) {
    if(list->tail) {
        dll_node *tmp = list->tail;
        int i=0;
        DBG_PRINT(LVL_INFO, "===== Printing DLL from Tail - Start =========\n");
        while(tmp != NULL) {
            DBG_PRINT(LVL_INFO, "node = %d, data = %d\n", i, tmp->data);
            i++;
            tmp = tmp->prev;
        }
        DBG_PRINT(LVL_INFO, "===== Printing DLL End =========\n");
    }
    DBG_PRINT(LVL_INFO, "List size = %ld\n", dll_list_size(list));
}
int dll_del_frontnode(dll *list) {
    if(list) {
        if(list->head == list->tail) {
            dll_free(list);
        }
        else {
            dll_node *p = list->head;
            list->head = p->next;
            list->head->prev = NULL;
            dll_node_free(p);
        }
        list->size--;
    }
    return 0;
}

int dll_del_backnode(dll *list) {
    if(list) {
        if(list->head == list->tail) {
            dll_free(list);
        }
        else {
            dll_node *p = list->tail->prev;
            dll_node_free(list->tail);
            list->tail = p;
            list->tail->next = NULL;
        }
        list->size--;
    }
    return 0;
}

size_t dll_list_size(const dll * const list) {
    if(list) {
        return list->size;
    }
    else {
        return 0;
    }
}
