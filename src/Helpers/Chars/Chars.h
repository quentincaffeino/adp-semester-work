
#ifndef CHARS_H
#define CHARS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int charsToInt(const char *chars);

size_t charsToSizeT(const char *chars);

size_t charsLength(const char *chars);

char *copyChars(const char *chars);

char *escapeChar(char c);

#endif /* CHARS_H */
