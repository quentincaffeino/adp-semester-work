
#ifndef ITEMSCONTROLLER_H
#define ITEMSCONTROLLER_H

#include <stdio.h>
#include "../Controller.h"
#include "../ItemPropertiesController/ItemPropertiesController.h"


int itemsControllerIndex(Container *container);

int itemsControllerNew(Container *container);

int itemsControllerEdit(Container *container, Item *item);


void _itemsControllerPrintItem(Item *item, size_t index, BDList *bdList);

int _itemsControllerDelete(Container *container, Item *item);

#endif /* ITEMSCONTROLLER_H */
