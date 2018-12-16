
#ifndef UTILS_H
#define UTILS_H

#ifdef _WIN32
#include <conio.h>

#else
#include <stdio.h>

#define clrscr() printf("\e[1;1H\e[2J")

#endif /* _WIN32 */

#endif /* UTILS_H */
