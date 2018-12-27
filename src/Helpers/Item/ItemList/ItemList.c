
#include "ItemList.h"


BDList *bootstrapItemList() {
    BDList *bdItemList = allocateBDList();

    file = openFile(ITEM_LIST_DB_PATH, "r");
    readFile(file);
    if (VERBOSE) {
        printc("Reading items db at: ", NULL);
        printf("%s\n", ITEM_LIST_DB_PATH);
        printFile(file);
    }

    BDList *fileItems = split(file->text, "BREAK\n", -1);
    if (VERBOSE) mapBDList(fileItems, &printString);

    for (size_t i = bdItemList->length; i < fileItems->length; ++i) {
        Item *item = allocateItem();
        item->id = i;
        appendToBDList(bdItemList, allocateBDLNode(item, &freeItem));

        BDList *fileItemLines = split(((String *) getBDLNodeByIndex(fileItems, i)->data), "\n", -1);
        if (VERBOSE) mapBDList(fileItemLines, &printString);

        for (size_t j = 0; j < fileItemLines->length; ++j) {
            BDList *fileItemLineKV = split(((String *) getBDLNodeByIndex(fileItemLines, j)->data), "=", 2);
            if (VERBOSE) {
                mapBDList(fileItemLineKV, &printString);
                printf("\n");
            }

            if (fileItemLineKV->length >= 2) {
                String *key = (String *) getBDLNodeByIndex(fileItemLineKV, 0)->data;
                String *value = (String *) getBDLNodeByIndex(fileItemLineKV, 1)->data;

                if (beginsWith(key, "name")) {
                    item->name = cloneString(value);
                } else if (beginsWith(key, "description")) {
                    item->description = cloneString(value);
                } else if (beginsWith(key, "count")) {
                    item->count = charsToSizeT(value->buffer);
                } else if (beginsWith(key, "price")) {
                    item->price = charsToSizeT(value->buffer);
                } else if (beginsWith(key, "properties")) {
                    BDList *fileItemProperties = split(value, ";", -1);

                    if (fileItemProperties->length) {
                        for (size_t k = 0; k < fileItemProperties->length; ++k) {
                            String *itemPropertyString = (String *) getBDLNodeByIndex(fileItemProperties, k)->data;
                            BDList *fileItemPropertyKV = split(itemPropertyString, "=", 2);

                            if (fileItemPropertyKV->length >= 2) {
                                Property *property = allocateProperty();
                                property->id = k;
                                property->name = cloneString((String *) getBDLNodeByIndex(fileItemPropertyKV, 0)->data);
                                property->description = cloneString(
                                        (String *) getBDLNodeByIndex(fileItemPropertyKV, 1)->data);
                                appendToBDList(item->properties, allocateBDLNode(property, &freeProperty));
                            }

                            freeBDList(&fileItemPropertyKV);
                        }
                    }

                    freeBDList(&fileItemProperties);
                }
            }

            freeBDList(&fileItemLineKV);
        }

        freeBDList(&fileItemLines);
    }

    freeBDList(&fileItems);
    freeFile(&file);
    return bdItemList;
}

void releaseItemList(BDList *bdList) {
    file = openFile(ITEM_LIST_DB_PATH, "w");

    mapBDList(bdList, &_writeItemToFile);

    freeFile(&file);
}

void _writeItemToFile(Item *item, size_t index, BDList *bdList) {
    if (item->name) {
        fputs("name=", file->pFile);
        fputs(item->name->buffer, file->pFile);
        fputc('\n', file->pFile);
    }

    if (item->description) {
        fputs("description=", file->pFile);
        fputs(item->description->buffer, file->pFile);
        fputc('\n', file->pFile);
    }

    if (item->count) {
        fputs("count=", file->pFile);
        char *chars = sizeTToChars(item->count);
        fputs(chars, file->pFile);
        free(chars);
        fputc('\n', file->pFile);
    }

    if (item->price) {
        fputs("price=", file->pFile);
        char *chars = sizeTToChars(item->price);
        fputs(chars, file->pFile);
        free(chars);
        fputc('\n', file->pFile);
    }

    if (item->properties && item->properties->length) {
        fputs("properties=", file->pFile);
        mapBDList(item->properties, &_writeItemPropertyToFile);
        fputc('\n', file->pFile);
    }

    fputs("BREAK\n", file->pFile);
}

void _writeItemPropertyToFile(Property *property, size_t index, BDList *bdList) {
    fputs(property->name->buffer, file->pFile);
    fputc('=', file->pFile);
    fputs(property->description->buffer, file->pFile);
    fputc(';', file->pFile);
}


Item *getItemByIdItemList(BDList *bdList, size_t id) {
    if (VERBOSE) printf("ItemList: getItemByIdItemList: Length: %ld; Looking for: %ld\n", bdList->length, id);
    for (size_t i = 0; i < bdList->length; ++i) {
        BDLNode *currentNode = getBDLNodeByIndex(bdList, i);
        Item *currentItem = (Item *) currentNode->data;

        if (currentItem) {
            if (VERBOSE) printf("ItemList: getItemByIdItemList: [%ld], current item id: %ld\n", i, currentItem->id);

            if (currentItem->id == id) {
                if (VERBOSE) printf("ItemList: getItemByIdItemList: Found: %ld", id);
                return (Item *) currentNode->data;
            }
        }
    }

    return NULL;
}
