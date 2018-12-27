
#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "../../BiDirList/BiDirList.h"
#include "../../FileSystem/File/File.h"
#include "../../../Entity/Item/Item.h"
#include "../../../Entity/Property/Property.h"

#define ITEM_LIST_DB_PATH "./data/items"

static File *file = NULL;


BDList *bootstrapItemList();

void releaseItemList(BDList *bdList);

void _writeItemToFile(Item *item, size_t index, BDList *bdList);

void _writeItemPropertyToFile(Property *property, size_t index, BDList *bdList);


Item *getItemByIdItemList(BDList *bdList, size_t id);

#endif /* ITEMLIST_H */
