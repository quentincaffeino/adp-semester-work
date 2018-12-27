
#ifndef CONTAINER_H
#define CONTAINER_H

#include "../State/State.h"


typedef struct Container {
    struct State *state;
} Container;


Container *allocateContainer();

void freeContainer(Container **container);


Container *bootstrapContainer();

void releaseContainer(Container **container);

#endif /* CONTAINER_H */
