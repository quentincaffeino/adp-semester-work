
#include "DefaultController.h"


int defaultControllerIndex(Container *container) {
    while (1) {
        printTitle("Dashboard");

        printf(" %-20s", "Items Kinds Total");
        printf(" | %-20s", "Items Total");
        printf(" | %-20s", "Total Price");
        printf(" | %-20s\n", "Avg. Price");
        _printDivider(NULL, '-', width);
        printf("\n");
        printf(" %-20ld", container->state->items->length);

        size_t totalPrice = 0;
        size_t totalEntities = 0;
        for (size_t i = 0; i < container->state->items->length; ++i) {
            Item *item = (Item *) getBDLNodeByIndex(container->state->items, i)->data;
            totalPrice += item->price * item->count;
            totalEntities += item->count;
        }
        printf(" | %-20ld", totalEntities);
        printf(" | %-20.2f", (double) totalPrice / 100.0);
        printf(" | %-20.2f\n", (double) totalPrice / 100.0 / (double) (totalEntities ?: 1));

        int action = getAction("1 - Items", 1);
        switch (action) {
            case 1:
                itemsControllerIndex(container);
                break;

            default:
                return 0;
        }
    }
}
