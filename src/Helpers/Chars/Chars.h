
#ifndef CHARS_H
#define CHARS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHARS_BUFFER_SIZE 9


char *readCharsLine(void *from);

char *copyChars(const char *chars);


int charsToInt(const char *chars);

size_t charsToSizeT(const char *chars);

char *sizeTToChars(size_t number);

#endif /* CHARS_H */
