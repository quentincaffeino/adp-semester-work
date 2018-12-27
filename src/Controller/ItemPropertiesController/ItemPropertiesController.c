
#include "ItemPropertiesController.h"


int itemPropertiesControllerIndex(Container *container, Item *item) {
    while (1) {
        printTitle("Item Properties");

        _itemPropertiesControllerPrintItemPropertyList(item->properties);

        int action = getAction("1 - New; 2 - Edit", 2);
        switch (action) {
            case 1:
                itemPropertiesControllerNew(container, item);
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

int itemPropertiesControllerNew(Container *container, Item *item) {
    printTitle("Item Properties - New");

    Property *property = newProperty();
    property->id = item->properties->length;
    appendToBDList(item->properties, allocateBDLNode(property, &freeProperty));

    return itemPropertiesControllerEdit(container, property);
}

int itemPropertiesControllerEdit(Container *container, Property *property) {
    printTitle("Item Properties - Edit");
}


void _itemPropertiesControllerPrintItemPropertyList(BDList *bdList) {
    printf(" %-5s", "#");
    printf(" | %-50s", "Name");
    printf(" | %-50s\n", "Description");
    _printDivider(NULL, '=', width);
    printf("\n");
    mapBDList(bdList, &_itemPropertiesControllerPrintItemProperty);
}

void _itemPropertiesControllerPrintItemProperty(Item *item, size_t index, BDList *bdList) {
    if (item) {
        printf(" %-5ld", item->id);
        printf(" | %-47.*s", 47, item->name->buffer);
        if (strlen(item->name->buffer) >= 47) printf("..."); else printf("   ");
        printf(" | %-77.*s", 77, item->description->buffer);
        if (strlen(item->description->buffer) >= 77) printf("..."); else printf("   ");

        printf("\n");
        if (bdList && index + 1 < bdList->length) {
            _printDivider(NULL, '-', width);
            printf("\n");
        }
    }
}
