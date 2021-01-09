#include<stdio.h>

int main()
{
    int ly[100000];
    int lr[100000];
    int n;
    scanf("%d", &n);
    int i, j;
    for ( i = 0; i < n; i++)
    {
        scanf("%d %d", &ly[i], &lr[i]);
    }
    int tt = ly[0];
    int kt = 0;
    int pre, k;
    for (j = 0; j < n; j++)
    {
        k = 0;
        for ( i = 0; i < n; i++)
        {
            if (ly[i] >= ly[j])
            {
                pre = 1;
            }
            else
            {
                pre = 0;
            }
            if (pre == lr[i])
            {
                k++;
            }
        }
        if (kt < k)
        {
            kt = k;
            tt = ly[j];
        }
        else if (kt == k)
        {
            kt = k;
            if (ly[j] > tt)
            {
                tt = ly[j];
            }
        }
    }
    printf("%d", tt);
    return 0;
}