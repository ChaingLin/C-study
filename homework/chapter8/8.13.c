// 写一个用矩形法和梯形法求定积分的通用函数。 可以输入选择1、sinx 2、cosx 3、e^x 4、exit

#include <math.h>
#include <stdio.h>

int main()
{
    double fun(double x1, double x0, double (*fun)(double));
    double x0, x1;
    // sin cos e^x 函数库中自带就不用定义了。

    // // 输入数字以选择函数
    // int n;
    // printf("请输入1：sinx  2：cosx  3：e^x  4：exit\n");
    // scanf("%d", &n);
    // if (n == 4)
    // {
    //     return 0;
    // }

    // // 输入上限，下限x0， x1
    // double x0, x1;
    // printf("请输入积分上限和下限:\n");
    // scanf("%lf, %lf", &x0, &x1);

    // // 将上下限代入函数计算
    // if (n == 1)
    // {
    //     fun(x0, x1, sin);
    // }
    // else if (n == 2)
    // {
    //     fun(x0, x1, cos);
    // }
    // else if (n == 3)
    // {
    //     fun(x0, x1, exp);
    // }
    // else if (n == 4)
    // {
    //     //退出
    //     return 0;
    // }
    // return 0;

    while (1)
    {
        int n;
        printf("请输入1：sinx  2：cosx  3：e^x  4：exit\n");
        scanf("%d", &n);

        if (n == 4)
            break;
        if (n != 1 && n != 2 && n != 3)
        {
            printf("输入的数字不正确,请重新输入\n");
            putchar('\n');
        }
        else
        {
            // 输入下限x0，上限x1 ,下a<b
            printf("请输入积分上限和下限:\n");
            scanf("%lf,%lf", &x1, &x0);
            if (x0 > x1)
            {
                printf("下限不能大于上限\n");
                putchar('\n');
            }
            else
            {
                switch (n)
                {
                case 1:
                    fun(x1, x0, sin);
                    break;
                case 2:
                    fun(x1, x0, cos);
                    break;
                case 3:
                    fun(x1, x0, exp);
                    break;

                default:
                    printf("输入的数字不正确\n");
                }
            }
        }
    }
    return 0;
}

double fun(double x1, double x0, double (*f)(double))
{
    int num;
    double x, y, dx, y1, t;
    double jf;
    num = 1000;
    dx = (x1 - x0) / num;

    // 矩形
    // for (x = x0; x < x1; x += dx)
    // {
    //     y = (*f)(x);
    //     jf += dx * y;
    // }
    // 梯形
    for ( x = x0; x < x1; x += dx)
    {

        // 高 dx
        // 上底 y后
        // 下底 y前
        // jf = (y1 + y2) * dx /2;
        y1 = t;
        y = x;
        jf += (y1 + y) *dx / 2;
        y = x;
        t = x;
    }
    printf("该函数的积分为：%lf\n", jf);
    putchar('\n');
    return 0;
}