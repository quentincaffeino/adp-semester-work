
#ifndef ITEMPROPERTIESCONTROLLER_H
#define ITEMPROPERTIESCONTROLLER_H

#include <stdio.h>
#include "../Controller.h"
#include "../../Entity/Property/Property.h"


int itemPropertiesControllerIndex(Container *container, Item *item);

int itemPropertiesControllerNew(Container *container, Item *item);

int itemPropertiesControllerEdit(Container *container, Property *property);


void _itemPropertiesControllerPrintItemPropertyList(BDList *bdList);

void _itemPropertiesControllerPrintItemProperty(Property *property, size_t index, BDList *bdList);

#endif /* ITEMPROPERTIESCONTROLLER_H */
