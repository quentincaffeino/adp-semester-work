
#include "DefaultController.h"


int defaultControllerIndex(Container *container) {
    while (1) {
        printTitle("Index");

        int action = getAction("Actions: 1 - Items", 1);
        switch (action) {
            case 1:
                itemsControllerIndex(container);
                break;

            default:
                return 0;
        }
    }
}
