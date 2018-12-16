
#ifndef ITEMSCONTROLLER_H
#define ITEMSCONTROLLER_H

#include <stdio.h>
#include "../Controller.h"


int itemsControllerIndex(Container *container);

int itemsControllerList(Container *container);

int itemsControllerNew(Container *container);

int itemsControllerEdit(Container *container, Item *item);


void _itemsControllerPrint(Item *item, size_t index, BDList *bdList);

int _itemsControllerDelete(Container *container, Item *item);

#endif /* ITEMSCONTROLLER_H */
