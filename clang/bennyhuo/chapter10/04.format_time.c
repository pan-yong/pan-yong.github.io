
#include <time.h>
#include <stdio.h>

int main() {
    time_t current_time;
    time(&current_time);
    struct tm *calender_time = localtime(&current_time);

    // 1
    puts(asctime(calender_time));

    // 2
    char current_time_s[20];
    strftime(current_time_s, 20, "%Y-%m-%d %H:%M:%S", calender_time);
    puts(current_time_s);


}