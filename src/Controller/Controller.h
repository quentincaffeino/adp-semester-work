
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include "../Foundation/Container/Container.h"

static int width = 160;


void printTitle(const char *title);

int getAction(const char *message, int max);

void _printDivider(const char *title, char divider, int width);

#endif /* CONTROLLER_H */
