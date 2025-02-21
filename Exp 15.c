#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIRS 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
} File;

typedef struct {
    char name[NAME_LENGTH];
    File files[MAX_FILES];
    int fileCount;
} Directory;

typedef struct {
    Directory directories[MAX_DIRS];
    int dirCount;
} FileSystem;

void addDirectory(FileSystem *fs, const char *dirName) {
    if (fs->dirCount < MAX_DIRS) {
        strcpy(fs->directories[fs->dirCount++].name, dirName);
    }
}

void addFileToDirectory(FileSystem *fs, const char *dirName, const char *fileName) {
    for (int i = 0; i < fs->dirCount; i++) {
        if (strcmp(fs->directories[i].name, dirName) == 0) {
            if (fs->directories[i].fileCount < MAX_FILES) {
                strcpy(fs->directories[i].files[fs->directories[i].fileCount++].name, fileName);
            }
            return;
        }
    }
}

void displayFileSystem(FileSystem *fs) {
    for (int i = 0; i < fs->dirCount; i++) {
        printf("Directory: %s\n", fs->directories[i].name);
        for (int j = 0; j < fs->directories[i].fileCount; j++) {
            printf("  File: %s\n", fs->directories[i].files[j].name);
        }
    }
}

int main() {
    FileSystem fs = {0};
    addDirectory(&fs, "Documents");
    addFileToDirectory(&fs, "Documents", "Resume.docx");
    addFileToDirectory(&fs, "Documents", "CoverLetter.docx");
    addDirectory(&fs, "Pictures");
    addFileToDirectory(&fs, "Pictures", "Vacation.jpg");

    displayFileSystem(&fs);
    return 0;
}
