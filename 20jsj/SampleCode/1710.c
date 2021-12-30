#include<stdio.h>
int main()
{
    int a[501], n, k, i, x;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", a+i);
    while(k--)
    {
        scanf("%d", &x);
        int find = -1;
        for (i = n-1; i >= 0; i--)
            if (a[i] == x){
                find = i;break;
            }
        printf("%d ", find);
    }
    printf("\n");
    return 0;
}