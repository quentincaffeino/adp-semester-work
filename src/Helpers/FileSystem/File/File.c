
#include "File.h"


File *allocateFile() {
    return calloc(1, sizeof(File));
}

void freeFile(File *file) {
    if (file->path != 0 && file->path != NULL) {
        freeString(file->path);
    }
    if (file->text != 0 && file->text != NULL) {
        freeString(file->text);
    }
    closeFile(file);
    free(file);
}

File *createFile(const char *path) {
    File *file = allocateFile();
    file->path = charsToString(path);
    return file;
}

File *openFile(const char *path, const char *mode) {
    File *file = createFile(path);
    _openFile(file, mode);
    return file;
}

void _openFile(File *file, const char *mode) {
    file->pFile = fopen(file->path->buffer, mode);
    if (file->pFile != 0 && file->pFile != NULL) {
        file->isOpen = TRUE;
    }
}

void closeFile(File *file) {
    if (file->isOpen) {
        file->isOpen = FALSE;
        if (file->pFile != 0) {
            fclose(file->pFile);
        }
        file->pFile = 0;
    }
}

void readFile(File *file) {
    if (file->isOpen) {
        size_t size = _getFileSize(file->pFile);
        file->text = allocateSizedString(size + 1);
        fread(file->text->buffer, size, 1, file->pFile);
    }
}

size_t _getFileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    return fileSize;
}

void printFile(File *file) {
    if (file->path != 0 && file->path != NULL) {
        printf("Path: %s\n", file->path->buffer);
    }
    printf("Is open: %s\n", file->isOpen ? "TRUE" : "FALSE");
    if (file->text != 0 && file->text != NULL) {
        printf("Text:\n%s\n", file->text->buffer);
    }

}
