
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <dirent.h>
#include <sys/stat.h>
#include "../FileArray/FileArray.h"
#include "../DirectoryArray/DirectoryArray.h"


typedef struct Directory {
    char *path;
    DIR *pDir;
    struct DirectoryArray *directories;
    FileArray *files;
} Directory;


Directory *allocateDirectory();

void freeDirectory(Directory *directory);

#endif /* DIRECTORY_H */
