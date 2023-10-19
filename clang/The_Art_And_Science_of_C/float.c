#include <stdio.h>
#include <math.h>s

int main() {
    float x;
    for(x = 1.0; x <= 2.0; x += 0.1)
        printf("%.1f\n", x);
    
    printf("after out of loop , the x value is %.7f\n", x);

    if(x == 2.0)
        printf("yes, x equal 2.0.\n");
    else 
        printf("no, x do not equal 2.0.\n");

    #define PRECISION  0.000001
    if(fabs(x-2.0) < PRECISION)
        printf("x equal 2.0\n");
    else 
        printf("x do not equal 2.0.\n");
}

/*

(1) The result is :

1.0
1.1
1.2
1.3
1.4
1.5
1.6
1.7
1.8
1.9
after out of loop, the x value is 2.0000002


(2) Why doesn't output the value 2.0 ?
Becase the value of float x is 2.0000002, it is not the exact value 2.0.
if the x type is double, the value will be 2.00000000000000088818, not the exact value 2.0 too.
so remember that the float value is not the exact value.

(3) how compare two float value ?

    #define PRECISION  0.000001
    if(fabs(x-2.0) < PRECISION)
        printf("x equal 2.0\n");
    else 
        printf("x do not equal 2.0.\n");


    or, 

    int a = x * 1e6;
    int b = 2.0*1e6;
        if(a == b)
        printf("x equal 2.0\n");
    else 
        printf("x do not equal 2.0.\n");

*/
