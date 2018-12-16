
#include "BiDirList.h"


BDList *allocateBDList() {
    return calloc(1, sizeof(BDList));
}

void freeBDList(BDList *bdList) {
    freeBDLNode(bdList->data, TRUE);
    free(bdList);
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
    if (bdList->length == 0) {
        bdList->data = bdlNode;
        bdList->_end = bdlNode;
    } else {
        insertBDLNodeAfter(bdList->_end, bdlNode);
        bdList->_end = bdlNode;
    }

    ++bdList->length;
}


void mapBDList(BDList *bdList, void (*callback)(void *, size_t index, BDList *bdList)) {
    if (VERBOSE) printf("BDList: mapBDList: Length: %ld\n", bdList->length);
    for (size_t i = 0; i < bdList->length; ++i) {
        if (VERBOSE) printf("BDList: mapBDList: [%ld]: ", i);
        callback((void *) getBDLNodeByIndex(bdList, i)->data, i, bdList);
    }
}
