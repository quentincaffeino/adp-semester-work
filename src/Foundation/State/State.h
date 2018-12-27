
#ifndef STATE_H
#define STATE_H

#include "../Container/Container.h"
#include "../../Helpers/Item/ItemList/ItemList.h"
#include "../../Helpers/BiDirList/BiDirList.h"


typedef struct State {
    struct Container *container;
    struct BDList *items;
} State;


State *allocateState();

void freeState(State **state);


State *bootstrapState(struct Container *container);

void releaseState(State **state);

#endif /* STATE_H */
