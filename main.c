#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main() {
    struct stat info;
    if (stat("main.c", &info) < 0) {
        printf("errno: %d\nERROR: %s", errno, strerror(errno));
    }
    printf("Size of file (in bytes): %ld B\n\n", info.st_size);
    printf("Last accessed: %s", ctime(&info.st_atime));
    printf("Last modified: %s\n", ctime(&info.st_mtime));
    // for some reason, this isn't working EXACTLY as how i intended
    int chmod = info.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    printf("permissions: %d\n", chmod);

    printf("other byte representations:\n%f GB\n%f MB\n%f KB\n%ld B\n", info.st_size / 1000000000.0, info.st_size / 1000000.0, info.st_size / 1000.0, info.st_size);


}
