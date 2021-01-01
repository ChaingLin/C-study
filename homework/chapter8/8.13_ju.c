// 写一个用矩形法和梯形法求定积分的通用函数。 可以输入选择1、sinx 2、cosx 3、e^x 4、exit

#include <stdio.h>
#include <math.h>

int main()
{
    float x0, x1;
    float x, y;
    float jf = 0;
    float dx = 0;
    int num, i;
    
    x0 = 0, x1 = 1;
    num = 1000;
    dx = (x1 - x0) / num;

    for ( x = x0; x < x1; x += dx)
    {
        // y = x;
        y = sin(x);
        // y = cos(x);
        // y = exp(x);
        jf += dx * y;
    }
    printf("%f\n", jf);
    return 0;
}