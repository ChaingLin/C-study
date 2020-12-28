#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
/*

n个人围成一圈，顺序排号，凡报到3的退圈，
既然是n个人围成一圈，那么说明一直按照1、2、3循环报数下去，只剩下1个人。

*/
int main()
{
    int *s;
    int n;
    int count = 0; //退圈人数计数
    int nums = 0;  //改变量用来报数
    printf("请输入n的值:\n");
    scanf("%d", &n);

    s = (int *)calloc(n, sizeof(int)); //开辟动态存储区

    for (int i = 0; i < n; i++)
    {
        *(s + i) = i + 1; //填入数字编号
    }

    int i = 0; //循环记录,避免指针来回移动

    printf("已经初始化n个人围成一圈.:\n");

    //因为i从0开始所以count要小于n-1才行
    while (count < n - 1)
    {
        //开始报数
        if (*(s + i) != 0)
        {
            nums++;
        }
        //每报数到3，将相应位置设置为0，并统计退圈人数
        if (nums == 3)
        {
            *(s + i) = 0;
            nums = 0; //重新1、2、3报数
            count++;
        }
        i++; //当i为n-1是说明当轮遍历结束，此时再加1
        if (i == n)
        {
            i = 0; //继续第二轮遍历,直到只剩下1人为止
        }
    }
    while (*s == 0)
    {
        s++;
    }
    printf("最后剩下的没有退圈的人是第%d人.\n", *s);
    system("pause");
    return 0;
}