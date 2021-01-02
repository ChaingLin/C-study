#include <stdio.h>
#include <string.h>
void main()
{
    char b[] = "a123x456 17960?";

    int a[20] = {0}, len = strlen(b), i, j = 1, k = -1;

    for (i = 0; i <= len; i++)
        printf("%d: ", a[i]);
        
    for (i = 0; i <= len - 1; i++)
    {
        if (b[i] < 58 && b[i] >= 48)
        {
            a[k] = a[k] * 10 + b[i] - 48;
        }
        else
        {
            k++;
        }
    }
    k = 20;
    for (i = 0; i < 20; i++)
        if (a[i] == 0)
        {
            for (j = i; j < 20; j++)
                a[i] = a[i + 1];
            k--;
        }
    for (i = 0; i < k; i++)
        printf("%d\n", a[i]);
}