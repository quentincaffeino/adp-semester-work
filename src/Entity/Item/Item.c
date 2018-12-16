
#include "Item.h"


Item *allocateItem() {
    Item *item = calloc(1, sizeof(Item));
    return item;
}

void freeItem(Item *item) {
    if (item->name != 0 && item->name != NULL) {
        freeString(item->name);
    }

    if (item->description != 0 && item->description != NULL) {
        freeString(item->description);
    }

    free(item);
}


void printItem(Item *item) {
    if (item->name != 0 && item->name != NULL) {
        printf("Name: `%s`\n", item->name->buffer);
    }

    if (item->description != 0 && item->description != NULL) {
        printf("Description: `%s`\n", item->description->buffer);
    }

    printf("Count: %lu\n", item->count);

    if (item->properties != NULL) {
    }
}
