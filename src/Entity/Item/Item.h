
#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Helpers/String/String.h"
#include "../PropertyArray/PropertyArray.h"


typedef struct Item {
    size_t id;
    String *name;
    String *description;
    size_t count;
    PropertyArray *properties;
} Item;


Item *allocateItem();

void freeItem(Item **item);


Item *newItem();

void printItem(Item *item);


void updateItemName(Item *item);

void updateItemDescription(Item *item);

void updateItemCount(Item *item);

#endif /* ITEM_H */
