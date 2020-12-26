// 输入10个整数,将其中最小的数与第一个数对换,把最大的数与最后一个数对换。要求用3个函数实现,分别为输入10个数、进行处理、输出10个数。要求使用指针的方法进行处理。
 跑不出来的一版
 #include<stdio.h>

int i;
int main()
{
    int a[10];
    void input(int *num);
    void output(int *num);
    void process(int *num);

    input(a);
    process(a);
    output(a);
    return 0;
}

void input(int *num)
{
    printf("请输入10个整数\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }
}

void output(int *num)
{
    for ( i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
}

void process(int *num)
{
    int min, max;
    min = max = num[0];
    int k, l, t;
    for (i = 0; i < 10; i++)
    {
        if (max <= num[i])
        {
            max = num[i];
            k = i;
        }
        if (min >= num[i])
        {
            min = num[i];
            l = i;
        }
    }
    t = num[0];
    num[0] = num[l];
    num[l] = t;

    k = num[9];
    num[9] = num[k];
    num[k] = t;
}