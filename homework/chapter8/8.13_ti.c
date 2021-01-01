// 写一个用矩形法和梯形法求定积分的通用函数。 可以输入选择1、sinx 2、cosx 3、e^x 4、exit

#include <stdio.h>
#include <math.h>

int main()
{
    float x0, x1;
    float x, y;
    float y1, y2;
    float jf = 0;
    float dx = 0;
    int num, i;
    num = 10000;
    x0 = 0, x1 = 1;
    dx = (x1 - x0) / num;

    float t;
    t = 0;

    for ( x = x0; x < x1; x += dx)
    {

        y1 = t;
        y = x;
        jf += (y1 + y) *dx / 2;
        y = x;
        // 高 dx
        // 上底 y后
        // 下底 y前
        // jf = (y1 + y2) * dx /2;
        
        // jf += dx * y;
        t = x;
    }
    printf("%f\n", jf);
    return 0;
}