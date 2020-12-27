// copy学习
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    void move(int *p, int n, int m);
    int a[30];
    int *p = a;
    int m, n;

    printf("input the n:\n");
    scanf("%d", &n);

    printf("input the num:\n");
    for (p = a; p < a + n;)
        scanf("%d", p++);

    printf("input the m:\n");
    scanf("%d", &m);

    p = a;

    move(p, n, m);

    for (p = a; p < a + n;)
        printf("%d", *p++);
}

void move(int *p, int n, int m)
{
    int i;
    for (i = n - 1; i >= 0; i--) //这个循环是依次往后移动m个位置
    {
        *(p + i + m) = *(p + i);
    }
    for (i = n; i < n + m; i++) //这个循环是把后面m个数移到最开始
    {
        *p++ = *(p + n);
    }
}