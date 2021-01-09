
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j = 0, cun = 0;
    int r, n, k = 0;
    scanf("%d", &n);
    int *a, *b;
    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (i = 0; i < n; i++)
    {
        k = 0;
        for (j = 0; j < n; j++)
        {
            if (a[i] > a[j] && b[j] == 0)
            {
                k++;
            }
            else if (a[i] <= a[j] && b[j] == 1)
            {
                k++;
            }
        }
        if (k > cun)
        {
            cun = k;
            r = a[i];
        }
        else if (k == cun)
        {
            if (a[i] > r)
                r = a[i];
        }
    }
    printf("%d", r);
    return 0;
}