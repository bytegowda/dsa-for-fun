#include <stdio.h>
#include <dsa/sll.h>

int main() {
    sll list;

    //init the sll
    sll_init(&list);

    //append to the list
    int n = 6;
    int a[10] = {12, 123, 212, 412, 152, 5};
    for(int i=0; i<n; i++) {
        if(-1 == sll_append(&list, a[i]))
            goto error;
    }

    //display the list
    sll_display(&list);

    DBG_PRINT(LVL_INFO, "Delete the front node\n");
    if(-1 == sll_del_frontnode(&list))
        goto error;

    sll_display(&list);

    //prepend to the list

    n=3;
    int b[10] = {53,773, 892};
    for(int i=0; i<n; i++) {
        if(-1 == sll_prepend(&list, b[i]))
            goto error;
    }

    //display the list
    sll_display(&list);

    DBG_PRINT(LVL_INFO, "Delete the back node\n");
    //delete a node
    if(-1 == sll_del_backnode(&list))
        goto error;

    sll_display(&list);

    //at the end, free all
    sll_free(&list);

    return 0;

error:
    DBG_PRINT(LVL_ERR, "strerror = %s\n", strerror(errno));
    sll_free(&list); //safely clean up before exiting the program
    return 1;
}

