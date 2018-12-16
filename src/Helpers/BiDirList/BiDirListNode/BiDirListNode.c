
#include "BiDirListNode.h"


BDLNode *allocateBDLNode(void *data, void (*pFreeDataCb)(void **)) {
    BDLNode *bdlNode = calloc(1, sizeof(BDLNode));
    bdlNode->data = data;
    bdlNode->pFreeDataCb = pFreeDataCb;
    return bdlNode;
}

void freeBDLNode(BDLNode *bdlNode, int recursive) {
    if (bdlNode != 0 && bdlNode != NULL) {
        if (recursive) {
            if (bdlNode->prev != 0 && bdlNode->prev != NULL) {
                bdlNode->prev->next = NULL;
                freeBDLNode(bdlNode->prev, recursive);
            }

            if (bdlNode->next != 0 && bdlNode->next != NULL) {
                bdlNode->next->prev = NULL;
                freeBDLNode(bdlNode->next, recursive);
            }
        } else {
            if (!(bdlNode->prev == 0 && bdlNode->prev == NULL)) {
                bdlNode->prev->next = bdlNode->next;
            }

            if (!(bdlNode->next == 0 && bdlNode->next == NULL)) {
                bdlNode->next->prev = bdlNode->prev;
            }
        }

        if (bdlNode->pFreeDataCb != 0 && bdlNode->pFreeDataCb != NULL) {
            bdlNode->pFreeDataCb(&bdlNode->data);
        }
        free(bdlNode);
    }
}


void insertBDLNodeAfter(BDLNode *refBDLNode, BDLNode *newBDLNode) {
    newBDLNode->prev = refBDLNode;
    newBDLNode->next = refBDLNode->next;
    if (refBDLNode->next != 0 && refBDLNode->next != NULL) {
        newBDLNode->next->prev = newBDLNode;
    }
    refBDLNode->next = newBDLNode;
}
