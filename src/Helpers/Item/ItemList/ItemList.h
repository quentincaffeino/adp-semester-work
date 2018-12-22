
#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "../../BiDirList/BiDirList.h"
#include "../../FileSystem/File/File.h"
#include "../../../Entity/Item/Item.h"

#define ITEM_LIST_DB_PATH "./data/items"


BDList *bootstrapItemList();

Item *getItemByIdItemList(BDList *bdList, size_t id);

#endif /* ITEMLIST_H */
