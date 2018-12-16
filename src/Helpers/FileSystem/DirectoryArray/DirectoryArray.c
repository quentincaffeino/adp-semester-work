
#include "DirectoryArray.h"


DirectoryArray *allocateDirectoryArray(size_t length) {
    DirectoryArray *directoryArray = calloc(1, sizeof(DirectoryArray));
    if (length == 0) length = DEFAULT_BUFFER_SIZE;
    directoryArray->bufferLength = length;
    return directoryArray;
}

void freeDirectoryArray(DirectoryArray *directoryArray) {
    free(directoryArray);
}

void pushToDirectoryArray(DirectoryArray *directoryArray, struct Directory *directory) {

}
