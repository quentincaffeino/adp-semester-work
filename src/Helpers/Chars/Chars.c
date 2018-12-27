
#include "Chars.h"


char *readCharsLine(void *from) {
    char *chars = NULL;

    if (from) {
        fflush(from);
        size_t bufferLength = CHARS_BUFFER_SIZE;
        chars = calloc(bufferLength, sizeof(char));

        char ch;
        size_t i = 0;
        while ((ch = fgetc(from)) && ch != '\n' && ch != EOF) {
            if (i >= bufferLength) {
                bufferLength += CHARS_BUFFER_SIZE;
                chars = realloc(chars, bufferLength);
            }

            chars[i] = ch;
            ++i;
        }

        chars = realloc(chars, i + 1);
        chars[i] = '\0';
    }

    return chars;
}

char *copyChars(const char *chars) {
    char *newChars = NULL;

    if (chars != NULL) {
        size_t length = strlen(chars);
        newChars = calloc(length + 1, sizeof(char));
        memcpy(newChars, chars, length);
    }

    return newChars;
}


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

char *sizeTToChars(size_t number) {
    char *chars = calloc(CHARS_BUFFER_SIZE, sizeof(char));
    sprintf(chars, "%ld", number);
    return chars;
}
