
#include "Directory.h"


Directory *allocateDirectory() {
    Directory *directory = calloc(1, sizeof(Directory));
    directory->directories = allocateDirectoryArray(0);
    directory->files = allocateFileArray(0);
    return directory;
}

void freeDirectory(Directory *directory) {
    freeFileArray(directory->files);
    freeDirectoryArray(directory->directories);
    free(directory);
}
