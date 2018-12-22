
#include "BiDirListNode.h"


BDLNode *allocateBDLNode(void *data, void (*pFreeDataCb)(void **)) {
    BDLNode *bdlNode = calloc(1, sizeof(BDLNode));
    bdlNode->data = data;
    bdlNode->pFreeDataCb = pFreeDataCb;
    return bdlNode;
}

void freeBDLNode(BDLNode **bdlNode, bool recursive) {
    if (*bdlNode) {
        if (recursive) {
            if ((*bdlNode)->prev) {
                (*bdlNode)->prev->next = NULL;
                freeBDLNode(&(*bdlNode)->prev, recursive);
            }

            if ((*bdlNode)->next) {
                (*bdlNode)->next->prev = NULL;
                freeBDLNode(&(*bdlNode)->next, recursive);
            }
        } else {
            if ((*bdlNode)->prev) {
                (*bdlNode)->prev->next = (*bdlNode)->next;
            }

            if ((*bdlNode)->next) {
                (*bdlNode)->next->prev = (*bdlNode)->prev;
            }
        }

        if ((*bdlNode)->pFreeDataCb) {
            (*bdlNode)->pFreeDataCb(&(*bdlNode)->data);
        }

        free(*bdlNode);
        *bdlNode = NULL;
    }
}


void insertBDLNodeAfter(BDLNode *refBDLNode, BDLNode *newBDLNode) {
    if (newBDLNode) {
        newBDLNode->prev = refBDLNode;

        if (refBDLNode) {
            newBDLNode->next = refBDLNode->next;
            if (refBDLNode->next) {
                newBDLNode->next->prev = newBDLNode;
            }
            refBDLNode->next = newBDLNode;
        }
    }
}
