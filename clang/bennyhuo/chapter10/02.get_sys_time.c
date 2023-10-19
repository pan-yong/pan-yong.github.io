#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main() {
    time_t current_time;
    time(&current_time);
    printf("%ld\n", current_time);

    // get millisecond 
    struct timeval time_value;
    gettimeofday(&time_value, NULL);
    printf("%ld %ld\n", time_value.tv_sec,time_value.tv_usec);


}