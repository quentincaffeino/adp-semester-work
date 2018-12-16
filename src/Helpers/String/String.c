
#include "String.h"


String *allocateString() {
    return calloc(1, sizeof(String));
}

String *allocateSizedString(size_t bufferLength) {
    String *string = allocateString();
    string->buffer = calloc(bufferLength, sizeof(char));
    string->bufferLength = bufferLength;
    return string;
}

void reallocString(String *string, size_t newSize) {
    if (newSize != string->bufferLength) {
        string->bufferLength = newSize;
        string->buffer = realloc(string->buffer, string->bufferLength);
    }
}

void freeString(String **string) {
    free((*string)->buffer);
    free(*string);
    *string = NULL;
}

String *charsToString(const char *chars) {
    String *string = allocateString();
    string->buffer = copyChars(chars);
    string->bufferLength = charsLength(chars) + 1;
    return string;
}

String *cloneString(String *string) {
    return charsToString(string->buffer);
}


void printString(String *string) {
    printf("%s", string->buffer);
}

String *subString(String *string, size_t beginning, size_t end) {
    long long int length = end - beginning;

    // if (VERBOSE) {
    //     printc("String: subString: ", NULL);
    //     printf("string: `%s`(%ld); beginning: %lu; end: %lu; length: %lld\n", string->buffer, string->bufferLength,
    //            beginning, end, length);
    // }

    if (length > 0) {
        String *newSubString = allocateSizedString((size_t) length + 1);

        for (size_t j = 0, i = beginning; i < end && i < string->bufferLength; ++j, ++i) {
            newSubString->buffer[j] = string->buffer[i];
        }

        return newSubString;
    }

    return string;
}

bool beginsWith(String *string, const char *chars, size_t offset) {
    size_t charsLen = charsLength(chars);
    size_t i = 0;

//    if (VERBOSE) {
//        printc("String: beginsWith: ", NULL);
//        printf("string: `%s`(%ld); chars: `%s`(%ld); offset: %lu\n", string->buffer, string->bufferLength, chars,
//               charsLen, offset);
//    }

    while (i < charsLen && i < string->bufferLength - offset) {
        // if (VERBOSE) {
        //     printc("String: beginsWith: ", NULL);
        //     printf("while: `%c`[%ld] == `%c`[%ld]\n", string->buffer[offset + i], offset + i, chars[i], i);
        // }

        if (string->buffer[offset + i] == chars[i]) {
            ++i;
        } else {
            break;
        }
    }

    return i == charsLen;
}

long long int indexOf(String *string, const char *chars, size_t offset) {
    size_t i = offset;

    while (i < string->bufferLength) {
        if (beginsWith(string, chars, i)) {
            return i;
        }

        ++i;
    }

    return -1;
}

struct BDList *split(String *string, const char *separator, size_t limit) {
    struct BDList *bdList = allocateBDList();
    size_t beginning = 0;
    size_t end = 0;
    size_t tmpEnd = 0;
    size_t separatorLength = charsLength(separator);

    if (VERBOSE) {
        printc("String: split: ", NULL);
        printf("string: `%s`(%ld); separator: `%s`(%ld)\n", string->buffer, string->bufferLength, separator,
               separatorLength);
    }

    while (end >= 0 && end < string->bufferLength - separatorLength) {
        if (bdList->length < limit - 1 && (tmpEnd = indexOf(string, separator, end)) >= 0 &&
            tmpEnd < string->bufferLength - separatorLength) {
            end = tmpEnd;
            if (VERBOSE) {
                printc("String: split: ", NULL);
                printf("while: beginning: %ld; end: %ld\n", beginning, end);
            }

            appendToBDList(bdList, allocateBDLNode(subString(string, beginning, end), &freeString));

            end += separatorLength;
            beginning = end;
        } else {
            appendToBDList(bdList, allocateBDLNode(subString(string, end, string->bufferLength),
                                                   &freeString));
            break;
        }
    }

    return bdList;
}


String *readStringLine(void *from) {
    String *line = NULL;

    if (from) {
        line = allocateString();
        line->buffer = readCharsLine(from);
        line->bufferLength = charsLength(line->buffer) + 1;
    }

    return line;
}

int readInt() {
    int x = 0;
    String *string = readStringLine(stdin);

    if (string) {
        x = charsToInt(string->buffer);
        freeString(&string);
    }

    return x;
}

void printc(char *chars, char *color) {
    if (color == NULL) {
        color = "\033[0;31m";
    }

    printf("%s", color);
    printf("%s", chars);
    printf("\033[0m");
}
