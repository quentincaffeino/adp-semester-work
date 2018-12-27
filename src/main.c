
#include "Foundation/Container/Container.h"
#include "Foundation/Globals.h"
#include "Controller/DefaultController/DefaultController.h"


int main(int argc, char **argv) {
    printf("Loading...\n");
    Container *container = bootstrapContainer();
    clrscr();

    int result = defaultControllerIndex(container);

    printf("Exiting...\n");
    releaseContainer(&container);
    clrscr();
    return result;
}
