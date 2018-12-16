
#include "FileArray.h"


FileArray *allocateFileArray(size_t length) {
    FileArray *fileArray = calloc(1, sizeof(FileArray));
    if (length == 0) length = DEFAULT_BUFFER_SIZE;
    fileArray->bufferLength = length;
    fileArray->files = calloc(length, sizeof(File));
    return fileArray;
}

void freeFileArray(FileArray *fileArray) {
    for (size_t i = 0; i < fileArray->bufferLength; ++i) {
        freeFile(fileArray->files[i]);
    }
    free(fileArray->files);
    free(fileArray);
}

void pushToFileArray(FileArray *fileArray, File *file) {
    if (fileArray->length + 1 >= fileArray->bufferLength) {
        fileArray->bufferLength += DEFAULT_BUFFER_SIZE;
        fileArray->files = realloc(fileArray->files, fileArray->bufferLength);
        if (VERBOSE) printf("ERR: FileArray: push: Failed to reallocate `File **files`.\n");
        return;
    }

    fileArray->files[fileArray->length] = file;
    ++fileArray->length;
}
