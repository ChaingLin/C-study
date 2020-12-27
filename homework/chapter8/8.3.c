// 输入10个整数,将其中最小的数与第一个数对换,把最大的数与最后一个数对换。要求用3个函数实现,分别为输入10个数、进行处理、输出10个数。要求使用指针的方法进行处理。

#include <stdio.h>

int i;
int main()
{
    int num[10];
    void input(int *);
    void output(int *);
    void process(int *);

    input(num);
    process(num);
    output(num);
    return 0;
}

void input(int *num)
{
    printf("请输入10个整数\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }
    printf("你输入的数是：\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
    putchar('\n');
}

void output(int *num)
{
    printf("结果是：\n");
    for (i = 0; i < 10; ++i)
    {
        if (i == 9) // 格式控制
        {
            printf("%d\n", num[i]);
        }        
        else
        {
            printf("%d ", num[i]);
        }
    }
}
void process(int *num)
{
    int *min, *max;
    min = max = &num[0]; // min和max两个指针，指向num的第一个元素的地址
    int k, l, t;
    for (i = 0; i < 10; i++)
    {
        if (*max <= num[i]) // max指针所指向的数*max，来和num数组的各项比较
        {
            max = &num[i]; // 指针max，指向当前数组中最大数的地址
            k = i;
        }
        if (*min >= num[i])
        {
            min = &num[i];
            l = i;
        }
    }
    t = num[0];
    num[0] = *min;
    // num[l] = t;
    *min = t;

    t = num[9];
    num[9] = *max; // 将最大的数*max 赋给num[9]
    // num[k] = t;
    *max = t; // *max所指向的地址上的数 的值变为t
}