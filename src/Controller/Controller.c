
#include "Controller.h"


void printTitle(const char *title) {
    clrscr();
    _printDivider(title, '=', width);
}

int getAction(const char *message, int max) {
    _printDivider(NULL, '=', width);
    printf("\nActions: %s; * - exit: ", message);

    int action = readInt();
    if (action < 0 /* min */ || action > max) {
        printf("Wrong action, please try again.\n");
        return getAction(message, max);
    }

    return action;
}

void _printDivider(const char *title, char divider, int width) {
    if (title) {
        size_t newLength = (width - 22) / 2;

        fputc('\n', stdout);
        _printDivider(NULL, divider, newLength);
        printf(" %-20s ", title);
        _printDivider(NULL, divider, newLength);
        fputc('\n', stdout);
    } else {
        for (size_t i = 0; i < width; ++i) {
            fputc(divider, stdout);
        }
    }
}
