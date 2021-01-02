// 有n个人围成一圈，顺序排号。从第一个人开始报数(从1到 3报数)，凡是报到 3的人退出圈子，问最后留下来的是原来的第几位（指针方法处理）。
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void Process(int *, int m, int n);
    int n, m, i;
    int *p;
    printf("请输入人数：");
    scanf("%d", &n);
    printf("请输入报数：");
    scanf("%d", &m);
    // printf("hello world");
    int a[100];
    char b[] = "hello world";
    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    p = a;
    // printf("%s", b);  // 为什么不能在这里加呢。
    Process(p, m, n);
    
    return 0;
}

void Process(int *p, int m, int n)
{
    int i;
    int h = 0;
    int count = 0;
    int sum = 0;

    printf("出局顺序为： \n");
    //以出局的人数作为循环条件
    while (count < n)
    {
        if (*(p + i) != 0)
        {
            sum++;
        }

        if (sum == m)
        {
            
            printf("%2d ", *(p + i)); // 输出出局的人位置
            h++;
            if (h == 10)
            {
                putchar('\n');
                h = 0;
            }

            sum = 0;       // 记数君重新归零
            *(p + i) = 0;  // 出局的人的值设为0，并输出其位置
            count++; // 增加一个出局人数
        }
        i++;

        if (i == n)
        {
            i = 0; //指针到达最后一位的时候返回第一位
        }
    }
    putchar('\n');
    // while (*p == 0) //输出最后一个没有退圈的人
    // {
    //     p++;
    // }
}

// 1 2 3 4 5 6 7 8 9 10
// 1 2 3 4 7 8 10