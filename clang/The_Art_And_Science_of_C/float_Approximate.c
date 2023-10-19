
#include <math.h>
#include <stdio.h>

#define PRECISION  0.000001

int ApproximatelyEqual(float x, float y)
{
    return (fabs(x-y) < PRECISION);
}

// page 140
int ApproximatelyEqual2(float x, float y)
{
    float a = fabs(x-y);
    float b = fabs(x) < fabs(y) ? fabs(x) : fabs(y);

    return (a / b) < PRECISION;
}

int main() {
    float x;

    for(x = 1.0; ; x += 0.1) {
        printf("%.1f\n", x);
        if (ApproximatelyEqual(x, 2.0) ) break;
    }
        
    
}