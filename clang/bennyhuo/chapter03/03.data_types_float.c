// It takes 10 minutes.
// 3.14     double
// 3.14f    float
// 1.23e4   scientific counting
// float money = 3.14f    Don't use float numbers to describe money.

#include<stdio.h>
int main() {

    float lat = 39.90815f;
    int lat06 = (int)(lat * 1e6);
    printf("%f", 39.90816f - lat);

    float money = 3.14f; // error  Don't use float numbers to describe money.
}