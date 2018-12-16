
#include "Foundation/Container/Container.h"
#include "Foundation/Globals.h"
#include "Controller/DefaultController/DefaultController.h"


int main(int argc, char **argv) {
    clrscr();

    Container *container = allocateContainer();
    int result = defaultControllerIndex(container);
    printf("Exiting...\n");
    freeContainer(container);

    return result;
}
