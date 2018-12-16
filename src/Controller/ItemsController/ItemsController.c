
#include "ItemsController.h"


int itemsControllerIndex(Container *container) {
    while (1) {
        printTitle("Items");

        mapBDList(container->state->items, &_itemsControllerPrint);

        int action = getAction("1 - New", 1);
        switch (action) {
            case 1:
                itemsControllerNew(container);
                break;

            default:
                return 0;
        }
    }
}


int itemsControllerNew(Container *container) {
    printTitle("Items - New");

    Item *item = newItem();
    item->id = container->state->items->length;
    appendToBDList(container->state->items, allocateBDLNode(item, &freeItem));

    return itemsControllerEdit(container, item);
}


int itemsControllerEdit(Container *container, Item *item) {
    while (1) {
        printTitle("Items - Edit");

        _itemsControllerPrint(item, 0, NULL);

        int action = getAction("Change: 1 - Name; 2 - Description; 3 - Count; Other: 4 - Delete", 4);
        switch (action) {
            case 1:
                updateItemName(item);
                break;

            case 2:
                updateItemDescription(item);
                break;

            case 3:
                updateItemCount(item);
                break;

            case 4:
                _itemsControllerDelete(container, item);
                return 0;

            default:
                return 0;
        }
    }
}


void _itemsControllerPrint(Item *item, size_t index, BDList *bdList) {
    printf(" %-5ld |", item->id);
    printf(" %-50s |", item->name->buffer);
    printf(" %-50s", item->description->buffer);

    printf("\n");
    if (bdList && index + 1 < bdList->length) {
        _printDivider(NULL, '-', width);
        printf("\n");
    }
}

int _itemsControllerDelete(Container *container, Item *item) {
    printf("This action couldn't be undone, are you sure you want to delete this item? [Y/n]");

    return 0;
}
