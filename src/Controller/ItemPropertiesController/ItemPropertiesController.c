
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
                Property *property = NULL;

                do {
                    printf("Select property to edit (id): ");
                    size_t id = (size_t) readInt();

                    property = getItemByIdItemList(item->properties, id);
                    if (property) {
                        itemPropertiesControllerEdit(container, property);
                    } else {
                        printf("Could not find property with id: %ld, please try again.\n", id);
                    }
                } while (!property);
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
    while (1) {
        printTitle("Item Property - Edit");

        printProperty(property);

        int action = getAction("Change: 1 - Name, 2 - Description; Other: 3 - Delete", 3);
        switch (action) {
            case 1:
                updatePropertyName(property);
                break;

            case 2:
                updatePropertyDescription(property);
                break;

            case 3:
                _itemsControllerDelete(container, property);
                return 0;

            default:
                return 0;
        }
    }
}


void _itemPropertiesControllerPrintItemPropertyList(BDList *bdList) {
    printf(" %-5s", "#");
    printf(" | %-50s", "Name");
    printf(" | %-50s\n", "Description");
    _printDivider(NULL, '=', width);
    printf("\n");
    mapBDList(bdList, &_itemPropertiesControllerPrintItemProperty);
}

void _itemPropertiesControllerPrintItemProperty(Property *property, size_t index, BDList *bdList) {
    if (property) {
        printf(" %-5ld", property->id);
        printf(" | %-47.*s", 47, property->name ? property->name->buffer : "");
        if (property->name && strlen(property->name->buffer) >= 47) printf("..."); else printf("   ");
        printf(" | %-77.*s", 77, property->description ? property->description->buffer : "");
        if (property->description && strlen(property->description->buffer) >= 77) printf("..."); else printf("   ");

        printf("\n");
        if (bdList && index + 1 < bdList->length) {
            _printDivider(NULL, '-', width);
            printf("\n");
        }
    }
}
