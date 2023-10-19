#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("CMakeLists.txt", "r");
    if (file) {
        puts("open file success.");
        fclose(file);
    } else {
        printf("%d\n", errno);
        puts(strerror(errno));
    }
}