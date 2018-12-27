
#include "Container.h"


Container *allocateContainer() {
    return calloc(1, sizeof(Container));
}

void freeContainer(Container **container) {
    free(*container);
    *container = NULL;
}


Container *bootstrapContainer() {
    Container *container = allocateContainer();
    container->state = bootstrapState(container);
    return container;
}

void releaseContainer(Container **container) {
    releaseState(&(*container)->state);
    freeContainer(container);
}
