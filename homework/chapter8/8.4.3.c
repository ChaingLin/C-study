#include <stdio.h>
// 每次向前移动一位，计算需要移动几次的方法，
int main()
{
    void move(int[20], int, int);
    int number[20], n, m, i;

    printf("how many numbers?");
    scanf("%d", &n);

    printf("input %d numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &number[i]);

    printf("how many place you want move?");
    scanf("%d", &m);

    move(number, n, m);

    printf("Now,they are:\n");
    for (i = 0; i < n; i++)
        printf("%d  ", number[i]);
    printf("\n");

    return 0;
}

void move(int array[20], int n, int m)
{
    int *p, array_end;
    array_end = *(array + n - 1);
    
    for (p = array + n - 1; p > array; p--) // p指向数组最后一个元素；p大于arry； p--， 直到第0个元素
        *p = *(p - 1); // 后一位元素，移动到前一位上，整体往后移动一位
    
    *array = array_end; // 最后一位移动到第一位
    
    m--;        // 控制移动次数，移动m次
    if (m > 0)
        move(array, n, m);
}

// 4 5 6 7
//   4 5 6 7