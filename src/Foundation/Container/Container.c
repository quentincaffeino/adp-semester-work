
#include "Container.h"


Container *allocateContainer() {
	Container *container = calloc(1, sizeof(Container));
	container->state = allocateState(container);
	return container;
}

void freeContainer(Container *container) {
	freeState(container->state);
	free(container);
}
