#include <stdio.h>
#include <dsa/dll.h>

int main() {
    dll list;

    //init the dll
    dll_init(&list);

    //append to the list
    int n = 6;
    int a[10] = {12, 123, 212, 412, 152, 5};
    for(int i=0; i<n; i++) {
        if(-1 == dll_append(&list, a[i]))
            goto error;
    }

    //display the list
    dll_display_from_head(&list);
    dll_display_from_tail(&list);

    DBG_PRINT(LVL_INFO, "Delete the front node\n");
    if(-1 == dll_del_frontnode(&list))
        goto error;

    dll_display_from_head(&list);
    dll_display_from_tail(&list);

    //prepend to the list

    n=3;
    int b[10] = {53,773, 892};
    for(int i=0; i<n; i++) {
        if(-1 == dll_prepend(&list, b[i]))
            goto error;
    }

    //display the list
    dll_display_from_head(&list);
    dll_display_from_tail(&list);


    DBG_PRINT(LVL_INFO, "Delete the back node\n");
    //delete a node
    if(-1 == dll_del_backnode(&list))
        goto error;

    dll_display_from_head(&list);
    dll_display_from_tail(&list);


    //at the end, free all
    dll_free(&list);

    return 0;

error:
    DBG_PRINT(LVL_ERR, "strerror = %s\n", strerror(errno));
    dll_free(&list); //safely clean up before exiting the program
    return 1;
}

