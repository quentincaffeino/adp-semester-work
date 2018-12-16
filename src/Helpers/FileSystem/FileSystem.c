
#include "FileSystem.h"


Directory *ls(char *path) {
    Directory *directory = allocateDirectory();
    DIR *dir = opendir(path);
    struct dirent *dent;

    if (dir != NULL) {
        while ((dent = readdir(dir))) {
//            printf("%s\n", dent->d_name);
            FILE *file = fopen(dent->d_name, "r");
            if (file != NULL) {
                pushToFileArray(directory->files, createFile(dent->d_name));
            }
            fclose(file);

            // struct stat st;
            // lstat(dent->d_name, &st);
            // if (!S_ISDIR(st.st_mode)) {
            //     pushToFileArray(directory->files, createFile(dent->d_name));
            // }
        }
        closedir(dir);
    } else {
        if (VERBOSE) printf("ERR: FileSystem: ls: Failed to open directory (%s).\n", path);
    }

    return directory;
}
