
#include<stdio.h>
#include<time.h>

void DoHardWord() {
    // do nothing
}
int main() {
    clock_t start = clock();
    DoHardWord();
    clock_t end = clock();

    printf("%f\n", (end - start) * 1.0 / CLOCKS_PER_SEC);
}
