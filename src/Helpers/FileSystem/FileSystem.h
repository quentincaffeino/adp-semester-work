
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <dirent.h>
#include <sys/stat.h>
#include "Directory/Directory.h"


Directory *ls(char *path);

#endif /* FILESYSTEM_H */
