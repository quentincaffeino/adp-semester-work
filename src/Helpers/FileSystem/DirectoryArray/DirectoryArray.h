
#ifndef DIRECTORYARRAY_H
#define DIRECTORYARRAY_H

#include <dirent.h>
#include <sys/stat.h>
#include "../Directory/Directory.h"


typedef struct DirectoryArray {
    struct Directory **directories;
    size_t length;
    size_t bufferLength;
} DirectoryArray;


DirectoryArray *allocateDirectoryArray(size_t length);

void freeDirectoryArray(DirectoryArray *directoryArray);

void pushToDirectoryArray(DirectoryArray *directoryArray, struct Directory *directory);

#endif /* DIRECTORYARRAY_H */
