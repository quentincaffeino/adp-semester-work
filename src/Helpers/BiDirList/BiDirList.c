
#include "BiDirList.h"


BDList *allocateBDList() {
    return calloc(1, sizeof(BDList));
}

void freeBDList(BDList **bdList) {
    if (bdList && *bdList) {
        freeBDLNode(&(*bdList)->data, true);
        free(*bdList);
    }
}


struct BDLNode *getBDLNodeByIndex(BDList *bdList, size_t index) {
    if (index > bdList->length) {
        return NULL;
    }

    BDLNode *found = bdList->data;
    size_t i = 0;

    while (i < index && found->next != 0 && found->next != NULL) {
        found = found->next;
        ++i;
    }

    return found;
}

void appendToBDList(BDList *bdList, struct BDLNode *bdlNode) {
    if (bdList) {
        if (bdList->length == 0) {
            bdList->data = bdlNode;
            bdList->_end = bdlNode;
        } else {
            insertBDLNodeAfter(bdList->_end, bdlNode);
            bdList->_end = bdlNode;
        }

        ++bdList->length;
    }
}

void removeFromBDList(BDList *bdList, struct BDLNode *bdlNode) {
    if (bdList) {
        BDLNode *currentNode = bdList->data;

        do {
            if (currentNode == bdlNode) {
                if (bdList->data == currentNode) { // Removing first node in list
                    bdList->data = bdList->data->next;
                }

                if (bdList->_end == currentNode) { // Removing last node in list
                    bdList->_end = bdList->_end->prev;
                }

                freeBDLNode(&currentNode, false);
                --bdList->length;
                return;
            }
        } while ((currentNode = currentNode->next));
    }
}

struct BDLNode *findNodeByDataBDList(BDList *bdList, void *data) {
    if (bdList) {
        BDLNode *currentNode = bdList->data;

        do {
            if (currentNode->data == data) return currentNode;
        } while ((currentNode = currentNode->next));
    }

    return NULL;
}


void mapBDList(BDList *bdList, void (*callback)(void *, size_t index, BDList *bdList)) {
    printf("BDList: mapBDList: Length: %ld\n", bdList->length);
    for (size_t i = 0; i < bdList->length; ++i) {
        printf("BDList: mapBDList: [%ld]: ", i);
        callback((void *) getBDLNodeByIndex(bdList, i)->data, i, bdList);
    }
}
