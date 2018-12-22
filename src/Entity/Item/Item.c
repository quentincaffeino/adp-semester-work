
#include "Item.h"


Item *allocateItem() {
    return calloc(1, sizeof(Item));
}

void freeItem(Item **item) {
    if (item && *item) {
        if ((*item)->name) freeString(&(*item)->name);
        if ((*item)->description) freeString(&(*item)->description);
        free(*item);
        *item = NULL;
    }
}


Item *newItem() {
    Item *item = allocateItem();
    updateItemName(item);
    updateItemDescription(item);
    updateItemCount(item);
    return item;
}

void printItem(Item *item) {
    if (item) {
        printf("Id: %ld\n", item->id);

        if (item->name) {
            printf("Name: `%s`\n", item->name->buffer);
        }

        if (item->description) {
            printf("Description: `%s`\n", item->description->buffer);
        }

        printf("Count: %lu\n", item->count);
    }
}


void updateItemName(Item *item) {
    printf("Name: ");
    if (item->name) freeString(&(item->name));
    item->name = readStringLine(stdin);
}

void updateItemDescription(Item *item) {
    printf("Description: ");
    if (item->description) freeString(&(item->description));
    item->description = readStringLine(stdin);
}

void updateItemCount(Item *item) {
    printf("Count: ");
    item->count = readInt();
}
