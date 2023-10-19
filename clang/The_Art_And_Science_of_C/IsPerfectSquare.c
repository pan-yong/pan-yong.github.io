#include <stdio.h>
#include <math.h>

int IsPerfectSquare(int n)
{
    int r = (int)sqrt(n);
    return (r*r) == n;
}

int main()
{
    if (IsPerfectSquare(121))
        printf("yes");
    else 
        printf("no");
}