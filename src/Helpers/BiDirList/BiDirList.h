
#ifndef BIDIRLIST_H
#define BIDIRLIST_H

#include <stdlib.h>
#include "BiDirListNode/BiDirListNode.h"
#include "../../Foundation/Globals.h"


typedef struct BDList {
    struct BDLNode *data;
    struct BDLNode *_end;
    size_t length;
} BDList;


BDList *allocateBDList();

void freeBDList(BDList *bdList);


struct BDLNode *getBDLNodeByIndex(BDList *bdList, size_t index);

void appendToBDList(BDList *bdList, struct BDLNode *bdlNode);


void mapBDList(BDList *bdList, void (*callback)(void *, size_t index, BDList *bdList));

#endif /* BIDIRLIST_H */
