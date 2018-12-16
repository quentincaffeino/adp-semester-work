
#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../Foundation/Globals.h"
#include "../Chars/Chars.h"
#include "../BiDirList/BiDirList.h"

#define STRING_BUFFER_SIZE 9


typedef struct String {
    char *buffer;
    size_t bufferLength;
} String;


size_t askForStringLength();

String *allocateString();

String *allocateSizedString(size_t bufferLength);

void freeString(String *string);

String *charsToString(const char *chars);

String *cloneString(String *string);


unsigned short int readString(String *string);

int readInt();


void printString(String *string);

String *subString(String *string, size_t beginning, size_t end);

unsigned short int beginsWith(String *string, const char *chars, size_t offset);

long long int indexOf(String *string, const char *chars, size_t offset);

struct BDList *split(String *string, const char *separator, size_t limit);


void printc(char *chars, char *color);

#endif /* STRING_H */
