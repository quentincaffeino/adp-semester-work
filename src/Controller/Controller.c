
#include "Controller.h"


void printTitle(const char *title) {
    printf("\n======== %-20s ========\n", title);
}

int getAction(const char *message, int max) {
    printf("%s; * - exit: ", message);

    int action = readInt();
    if (action < 0 /* min */ || action > max) {
        printf("Wrong action, please try again.\n");
        return getAction(message, max);
    }

    return action;
}
