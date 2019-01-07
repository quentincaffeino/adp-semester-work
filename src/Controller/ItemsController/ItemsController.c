
#include "ItemsController.h"


int itemsControllerIndex(Container *container) {
    while (1) {
        printTitle("Items");

        printf(" %-5s", "#");
        printf(" | %-40s", "Name");
        printf(" | %-80s", "Description");
        printf(" | %-10s", "Count");
        printf(" | %-10s\n", "Price");
        _printDivider(NULL, '=', width);
        printf("\n");
        ITEMS_ON_CURRENT_PAGE = 0;
        mapBDList(container->state->items, &_itemsControllerPrintItem);
        printf("Current page: %d\n", ITEMS_PAGE + 1);

        int action = 0;
        if (ITEMS_PAGE > 0 && ITEMS_ON_CURRENT_PAGE < (ITEMS_PAGE + 1) * ITEMS_PERPAGE) {
            action = getAction("Page: 1 - Prev; Items: 3 - New, 4 - Edit", 4);
        } else if (ITEMS_PAGE > 0) {
            action = getAction("Page: 1 - Prev, 2 - Next; Items: 3 - New, 4 - Edit", 4);
        } else {
            action = getAction("Page: 2 - Next; Items: 3 - New, 4 - Edit", 4);
        }

        switch (action) {
            case 1:
                if (ITEMS_PAGE > 0) --ITEMS_PAGE;
                break;

            case 2:
                if (ITEMS_ON_CURRENT_PAGE >= (ITEMS_PAGE + 1) * ITEMS_PERPAGE) ++ITEMS_PAGE;
                break;

            case 3: {
                int result = itemsControllerNew(container);
                if (result != 0) printf("Failed to create a new item.\n");
                break;
            }

            case 4: {
                Item *item = NULL;

                do {
                    printf("Select item to edit (id): ");
                    size_t id = (size_t) readInt();

                    item = getItemByIdItemList(container->state->items, id);
                    if (item) {
                        int result = itemsControllerEdit(container, item);
                        if (result != 0) printf("Failed to edit item.\n");
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
    if (!item) return 1;

    item->id = container->state->items->length;
    appendToBDList(container->state->items, allocateBDLNode(item, &freeItem));

    return itemsControllerEdit(container, item);
}


int itemsControllerEdit(Container *container, Item *item) {
    while (item) {
        printTitle("Item - Edit");

        printItem(item);
        _printDivider("Item Properties", '=', width);
        _itemPropertiesControllerPrintItemPropertyList(item->properties);

        int action = getAction(
                "Change: 1 - Name, 2 - Description, 3 - Count, 4 - Price, 5 - Properties; Other: 6 - Delete", 6);
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
                updateItemPrice(item);
                break;

            case 5:
                if (!item->properties) {
                    item->properties = allocateBDList();
                }

                itemPropertiesControllerIndex(container, item);
                break;

            case 6: {
                int result = _itemsControllerDelete(container, item);
                if (result != 0) printf("Failed to remove an item.\n");
                return result;
            }

            default:
                return 0;
        }
    }

    printf("No item were provided.");
    return 1;
}


void _itemsControllerPrintItem(Item *item, size_t index, BDList *bdList) {
    if (item &&
        ITEMS_ON_CURRENT_PAGE >= ITEMS_PERPAGE * ITEMS_PAGE &&
        ITEMS_ON_CURRENT_PAGE < ITEMS_PERPAGE * (ITEMS_PAGE + 1)
            ) {
        printf(" %-5ld", item->id);
        printf(" | %-37.*s", 37, item->name->buffer);
        if (strlen(item->name->buffer) >= 37) printf("..."); else printf("   ");
        printf(" | %-77.*s", 77, item->description ? item->description->buffer : "");
        if (item->description && strlen(item->description->buffer) >= 77) printf("..."); else printf("   ");
        printf(" | %-10ld", item->count);
        printf(" | %-10.2f", (double) item->price / 100.0);

        printf("\n");
        if (bdList && index + 1 < bdList->length) {
            _printDivider(NULL, '-', width);
            printf("\n");
        }
    }

    ++ITEMS_ON_CURRENT_PAGE;
}

int _itemsControllerDelete(Container *container, Item *item) {
    if (item) {
        BDLNode *bdlNode = findNodeByDataBDList(container->state->items, item);
        if (!bdlNode) return 1;

        bool decision = confirm("This action couldn't be undone, are you sure you want to delete this item?");
        if (decision) removeFromBDList(container->state->items, bdlNode);

        return 0;
    }

    return 1;
}
