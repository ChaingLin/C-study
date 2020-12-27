#include<stdio.h>
// 每次移动一位，计算需要移动几次的方法

void exchange(int *, int, int);

int main(void)
{

    int m, n, i;

    printf("input length and number:\n");

    scanf("%d,%d", &n, &m);

    int a[n];

    printf("input array:\n");

    for (i = 0; i < n; ++i)

        scanf("%d", &a[i]);

    printf("new array:\n");

    exchange(a, n, m);

    for (i = 0; i < n; i++)

        printf("%d ", a[i]);

    return 0;
}

void exchange(int *a, int n, int m)

{

    int i, j, temp;

    for (i = 0; i < m; ++i)
    {

        temp = a[0]; // 选储存第一个元素

        for (j = 0; j < n - 1; ++j) // 然后依次把每一位元素往""前""移动一位，直到第10位元素

            a[j] = a[j + 1];  // 前一位元素的值等于后一位

        a[n - 1] = temp; // 第10个元素直接等于第一个元素，相当于第一个元素往前移，移动至第10个
    }
}