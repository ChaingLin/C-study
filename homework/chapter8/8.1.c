//终于舒服了，可以开始stdudy了，qwq
//输入三个整数，按由小到大的顺序输出。

#include <stdio.h>


int main()
{
    void Findmax(int *p, int *q, int *w);
    int a, b, c, t;
    int *p, *q, *w;
    scanf("%d,%d,%d", &a, &b, &c);
    p = &a;
    q = &b;
    w = &c;
    Findmax(p, q, w);

    // if (a > b)
    // {
    //     t = b;
    //     b = a;
    //     a = t;
    // }

    // if (a > c)  
    // {
    //     t = c;
    //     c = a;
    //     a = t;
    // }

    // if (b > c)
    // {
    //     t = c;
    //     c = b;
    //     b = t;
    // }

    printf("这3个数由小到大的排列顺序为%d,%d,%d\n", *p, *q, *w);
    printf("这3个数由小到大的排列顺序为%d,%d,%d\n", a, b, c);
    
    return 0;
}

void Findmax(int *p, int *q, int *w)
{
    int t;
    // 如果*p大于*q，那么*q和*p互换
    if (*p > *q)
    {
        t = *q;
        *q = *p;
        *p = t;
    }

    // 如果*p大于*w， 那么*p和*q互换
    if (*p > *w)
    {       
        t = *w;
        *w = *p;
        *p = t;
    }
    
    // 如果*q大于*w， 那么*q和*w互换
    if (*q > *w)
    {
        t = *w;
        *w = *q;
        *q = t;
    }

    

    



}