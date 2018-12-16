
#include "Chars.h"


int charsToInt(const char *chars) {
    int result = 0;
    int prev;

    if (!chars) {
        return result;
    }

    while (*chars) {
        // Alt.: if (*chars >= '0' && *chars <= '9')
        if (isdigit(*chars)) {
            prev = result;
            result *= 10;
            result += *chars++ & 0xF; // OPTIMIZATION: += (*chars - '0')

            // check if would overflow
            if (result < prev) {
                return prev;
            }
        } else { // you decide SKIP or BREAK on invalid digits
            break;
        }
    }

    return result;
}


size_t charsToSizeT(const char *chars) {
    size_t result = 0;
    size_t prev;

    if (!chars) {
        return result;
    }

    while (*chars) {
        // Alt.: if (*chars >= '0' && *chars <= '9')
        if (isdigit(*chars)) {
            prev = result;
            result *= 10;
            result += *chars++ & 0xF; // OPTIMIZATION: += (*chars - '0')

            // check if would overflow
            if (result < prev) {
                return prev;
            }
        } else { // you decide SKIP or BREAK on invalid digits
            break;
        }
    }

    return result;
}


size_t charsLength(const char *chars) {
    size_t length = 0;

    if (chars != NULL) {
        for (; chars[length] != '\0'; ++length);
    }

    return length;
}


char *copyChars(const char *chars) {
    char *newChars = NULL;

    if (chars != NULL) {
        size_t length = charsLength(chars);
        newChars = calloc(length + 1, sizeof(char));
        memcpy(newChars, chars, length);
    }

    return newChars;
}


char *escapeChar(char c) {
    if (c == '\n') return "\\n";
    if (c == '\t') return "\\t";
    char *newC = calloc(1, sizeof(char));
    newC[0] = c;
    return newC;
}
