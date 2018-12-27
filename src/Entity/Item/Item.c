
#include "Item.h"


Item *allocateItem() {
    Item *item = calloc(1, sizeof(Item));
    item->properties = allocateBDList();
    return item;
}

void freeItem(Item **item) {
    if (item && *item) {
        if ((*item)->name) freeString(&(*item)->name);
        if ((*item)->description) freeString(&(*item)->description);
        if ((*item)->properties) freeBDList(&(*item)->properties);

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

        if (item->name) printf("Name: `%s`\n", item->name->buffer);
        if (item->description) printf("Description: `%s`\n", item->description->buffer);

        printf("Count: %lu\n", item->count);
        printf("Price: %.2f\n", (double) item->price / 100.0);
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
    char *line = readCharsLine(stdin);
    item->count = charsToSizeT(line);
    free(line);
}

void updateItemPrice(Item *item) {
    printf("Price (in cents): ");
    char *line = readCharsLine(stdin);
    item->price = charsToSizeT(line);
    free(line);
}
