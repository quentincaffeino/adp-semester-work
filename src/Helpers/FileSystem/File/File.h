
#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../String/String.h"


typedef struct File {
    String *path;
    String *text;
    FILE *pFile;
    int isOpen;
} File;


File *allocateFile();

void freeFile(File **file);

File *createFile(const char *path);

File *openFile(const char *path, const char *mode);

void _openFile(File *file, const char *mode);

void closeFile(File *file);

void readFile(File *file);

size_t _getFileSize(FILE *file);

void printFile(File *file);

#endif /* FILE_H */
