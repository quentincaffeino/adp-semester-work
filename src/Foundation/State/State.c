
#include "State.h"


State *allocateState(struct Container *container) {
	State *state = calloc(1, sizeof(State));
	state->container = container;
	state->items = bootstrapItemList();
	return state;
}

void freeState(State *state) {
	freeBDList(&state->items);
	free(state);
}
