// 双色球彩票

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RMAX 35
#define RN 5
#define BMAX 12
#define BN 2

void init(int a[], int n) // 生成球序号的数组
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
}

void swap(int a[], int i, int j) // 数组中的两个元素交换
{
    int t;          
    t = a[i];  // t = a[21]= 21, a[21] = a[34] = 35 , a[34] = 21
    a[i] = a[j];
    a[j] = t;
}

int myrand(int a[], int n, int m) // 返回一个随机的球
{
    int k;
    k = rand() % (n - m + 1); // 生成一个0至（n-m+1）的随机数
    swap(a, k, n - m); // 返回这个随机数，并把这个随机数与当前最后一个数互换，下一轮就不会再抽中
    return (a[n - m]);
}

void sort(int a[], int n) // 按照从小到大的顺序排序
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            swap(a, i, k);
        }
    }
}

void print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%02d ", a[i]);
    }
}

int main()
{
    int i, j, num, flag, rball[RMAX], bball[BMAX], rblock[RN], bblock[BN];

    srand((unsigned)time(NULL));

    printf("打算买几注？ (1 - 9): ");
    while ((flag = scanf("%d", &num)) != 1 || num < 1 || num > 9)
    {
        if (flag != EOF)
        {
            printf("超出范围！请重新输入：");
            while (getchar() != '\n'){}
        }       
    }

    printf("号码:\n");
    for (i = 1; i <= num; i++)
    {
        init(rball, RMAX);
        init(bball, BMAX);
        printf("(%d) ", i);
        for (j = 0; j < RN; j++)
        {
            rblock[j] = myrand(rball, RMAX, j + 1);
        }
        sort(rblock, RN);
        print(rblock, RN);
        printf("-- ");
        for (j = 0; j < BN; j++)
        {
            bblock[j] = myrand(bball, BMAX, j + 1);
        }
        sort(bblock, BN);
        print(bblock, BN);
        putchar('\n');
        
    }
}