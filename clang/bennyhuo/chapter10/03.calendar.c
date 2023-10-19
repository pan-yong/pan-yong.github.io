
#include <time.h>
#include <stdio.h>

int main() {
    time_t current_time;
    time(&current_time);

    struct tm *calender_time = localtime(&current_time);
    printf("%d-%d-%d %d:%d:%d\n", calender_time->tm_year,calender_time->tm_mon, calender_time->tm_mday,
        calender_time->tm_hour, calender_time->tm_hour, calender_time->tm_sec);

}