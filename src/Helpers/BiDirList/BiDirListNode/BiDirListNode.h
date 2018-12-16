
#ifndef BIDIRNODE_H
#define BIDIRNODE_H

#include <stdlib.h>
#include "../../String/String.h"


typedef struct BDLNode {
    struct BDLNode *prev;
    void *data;
    struct BDLNode *next;

    void (*pFreeDataCb)(void **);
} BDLNode;


BDLNode *allocateBDLNode(void *data, void (*pFreeDataCb)(void **));

void freeBDLNode(BDLNode *bdlNode, int recursive);


void insertBDLNodeAfter(BDLNode *refBDLNode, BDLNode *newBDLNode);

#endif /* BIDIRNODE_H */
