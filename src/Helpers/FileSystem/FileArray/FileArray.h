
#ifndef FILEARRAY_H
#define FILEARRAY_H

#include <stdlib.h>
#include "../File/File.h"


typedef struct FileArray {
    File **files;
    size_t length;
    size_t bufferLength;
} FileArray;


FileArray *allocateFileArray(size_t length);

void freeFileArray(FileArray *fileArray);

void pushToFileArray(FileArray *fileArray, File *file);

#endif /* FILEARRAY_H */
