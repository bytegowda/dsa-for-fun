#include <dsa/sll.h>
#include <stdlib.h>
#include <stdio.h>

void sll_init(sll *list) {
    list->head = list->tail = NULL;
    list->size = 0;
}

void sll_node_free(Node* node) {
    if(node) {
        free(node);
        node = NULL;
    }
}

void sll_free(sll *list) {
    if(list->head) {
        Node *tmp = NULL;
        while(list->head != NULL) {
            DBG_PRINT(LVL_DBG, " data=%d\n", list->head->data);
            tmp = list->head->next;
            sll_node_free(list->head);
            list->head = tmp;
        }

        list->head = list->tail = NULL;
    }
}

int sll_append(sll *list, const int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(NULL == new_node) {
        DBG_PRINT(LVL_ERR, "FATAL: Failed to MALLOC. Exit...\n");
        //exit(EXIT_FAILURE);
        errno = ENOMEM;
        return -1;
    }

    new_node->data = data;

    if(NULL == list->head) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
/*        Node *tmp = list->head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
*/
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
    return 0;
}

int sll_prepend(sll *list, const int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(NULL == new_node) {
        DBG_PRINT(LVL_ERR, "FATAL: Failed to MALLOC. Exit...\n");
        //exit(EXIT_FAILURE);
        errno = ENOMEM;
        return -1;
    }
    new_node->data = data;

    if(NULL == list->head) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        Node *tmp = list->head;
        list->head = new_node;
        list->head->next = tmp;
    }

    list->size++;
    return 0;
}

void sll_display(const sll * const list) {
    if(list->head) {
        Node *tmp = list->head;
        int i=0;
        DBG_PRINT(LVL_INFO, "===== Printing LL data Start =========\n");
        while(tmp != NULL) {
            DBG_PRINT(LVL_INFO, "node = %d, data = %d\n", i, tmp->data);
            i++;
            tmp = tmp->next;
        }
        DBG_PRINT(LVL_INFO, "===== Printing LL data End =========\n");
    }
    DBG_PRINT(LVL_INFO, "List size = %ld\n", sll_list_size(list));
}

int sll_del_frontnode(sll *list) {
    if(list) {
        if(list->head == list->tail) {
            sll_free(list);
        }
        else {
            Node *p = list->head;
            list->head = p->next;
            sll_node_free(p);
        }
        list->size--;
    }
    return 0;
}

int sll_del_backnode(sll *list) {
    if(list) {
        if(list->head == list->tail) {
            sll_free(list);
        }
        else {
            Node *p = list->head;
            while(p->next != list->tail)
                p = p->next;

            list->tail = p;
            sll_node_free(list->tail->next);
            list->tail->next = NULL;
        }
        list->size--;
    }
    return 0;
}

size_t sll_list_size(const sll * const list) {
    if(list) {
        return list->size;
    }
    else {
        return 0;
    }
}
