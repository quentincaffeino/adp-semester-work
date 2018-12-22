
#include "ItemsController.h"


int itemsControllerIndex(Container *container) {
    while (1) {
        printTitle("Items");

        printf(" %-5s", "#");
        printf(" | %-50s", "Name");
        printf(" | %-50s", "Description");
        printf(" | %-10s\n", "Count");
        _printDivider(NULL, '=', width);
        printf("\n");
        mapBDList(container->state->items, &_itemsControllerPrintItem);

        int action = getAction("1 - New; 2 - Edit", 2);
        switch (action) {
            case 1:
                itemsControllerNew(container);
                break;

            case 2: {
                Item *item = NULL;

                do {
                    printf("Select item to edit (id): ");
                    size_t id = (size_t) readInt();

                    item = getItemByIdItemList(container->state->items, id);
                    if (item) {
                        itemsControllerEdit(container, item);
                    } else {
                        printf("Could not find item with id: %ld, please try again.\n", id);
                    }
                } while (!item);
                break;
            }

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

        printItem(item);

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


void _itemsControllerPrintItem(Item *item, size_t index, BDList *bdList) {
    if (item) {
        printf(" %-5ld", item->id);
        printf(" | %-47.*s", 47, item->name->buffer);
        if (strlen(item->name->buffer) >= 47) printf("..."); else printf("   ");
        printf(" | %-47.*s", 47, item->description->buffer);
        if (strlen(item->description->buffer) >= 47) printf("..."); else printf("   ");
        printf(" | %-5ld", item->count);

        printf("\n");
        if (bdList && index + 1 < bdList->length) {
            _printDivider(NULL, '-', width);
            printf("\n");
        }
    }
}


int _itemsControllerDelete(Container *container, Item *item) {
    BDLNode *bdlNode = findNodeByDataBDList(container->state->items, item);

    if (bdlNode) {
        bool decision = confirm("This action couldn't be undone, are you sure you want to delete this item?");
        if (decision) removeFromBDList(container->state->items, bdlNode);
    } else {
        printf("Failed to remove item: \n");
        printItem(item);
    }

    return 0;
}
