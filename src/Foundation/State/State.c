
#include "State.h"


State *allocateState() {
    return calloc(1, sizeof(State));
}

void freeState(State **state) {
    free(*state);
    *state = NULL;
}


State *bootstrapState(struct Container *container) {
    State *state = allocateState();
    state->container = container;
    state->items = bootstrapItemList();
    return state;
}

void releaseState(State **state) {
    releaseItemList((*state)->items);
    freeBDList(&(*state)->items);
    freeState(state);
}
