
#include "ItemsController.h"


int itemsControllerIndex(Container *container) {
    while (1) {
        printTitle("Items");

        int action = getAction("Actions: 1 - List; 2 - New; 3 - Edit; 4 - Delete", 4);
        switch (action) {
            case 1:
                itemsControllerList(container);
                break;

            case 2:
                itemsControllerNew(container);
                break;

            case 3:
                itemsControllerEdit(container);
                break;

            case 4:
                itemsControllerDelete(container);
                break;

            default:
                return 0;
        }
    }
}


void _printItem(Item *item, size_t index, BDList *bdList) {
    printf("Item: [%ld]:\n", index + 1);
    printItem(item);

    if (index + 1 < bdList->length) {
        printf("\n");
    }
}

int itemsControllerList(Container *container) {
    printTitle("Items - List");

    mapBDList(container->state->items, &_printItem);

    return 0;
}


int itemsControllerNew(Container *container) {
    printTitle("Items - New");
    return 0;
}


int itemsControllerEdit(Container *container) {
    printTitle("Items - Edit");
    return 0;
}


int itemsControllerDelete(Container *container) {
    printTitle("Items - Delete");
    return 0;
}
