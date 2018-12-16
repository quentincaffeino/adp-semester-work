
#include "ItemList.h"


BDList *bootstrapItemList() {
    BDList *bdItemList = allocateBDList();

    File *file = openFile(ITEM_LIST_DB_PATH, "r");
    readFile(file);
    if (VERBOSE) {
        printc("Reading items db at: ", NULL);
        printf("%s\n", ITEM_LIST_DB_PATH);
        printFile(file);
    }

    BDList *fileItems = split(file->text, "BREAK\n", -1);
    if (VERBOSE) mapBDList(fileItems, &printString);

    for (size_t i = 0; i < fileItems->length; ++i) {
        Item *item = allocateItem();
        item->id = bdItemList->length;
        appendToBDList(bdItemList, allocateBDLNode(item, &freeItem));

        BDList *fileItemLines = split(((String *) getBDLNodeByIndex(fileItems, i)->data), "\n", -1);
        if (VERBOSE) mapBDList(fileItemLines, &printString);

        for (size_t j = 0; j < fileItemLines->length; ++j) {
            BDList *fileItemLineKV = split(((String *) getBDLNodeByIndex(fileItemLines, j)->data), "=", 2);
            if (VERBOSE) mapBDList(fileItemLineKV, &printString);

            if (fileItemLineKV->length == 2) {
                String *key = (String *) getBDLNodeByIndex(fileItemLineKV, 0)->data;
                String *value = (String *) getBDLNodeByIndex(fileItemLineKV, 1)->data;

                if (beginsWith(key, "name", 0)) {
                    item->name = cloneString(value);
                } else if (beginsWith(key, "description", 0)) {
                    item->description = cloneString(value);
                }
            }

            freeBDList(fileItemLineKV);
        }

        freeBDList(fileItemLines);
    }

//    mapBDList(bdItemList, &printItem);

    freeBDList(fileItems);
    freeFile(file);
    return bdItemList;
}
