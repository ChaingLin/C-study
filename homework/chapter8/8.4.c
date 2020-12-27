// 有n个整数,使前面各数顺序向后移m个位置,最后 m个数变成最前面 m个数,写一个函数实现以上功能,在主函数中输入n个整数和输出调整后的n个数。
// 啰嗦的初版本
#include<stdio.h>
int main()
{
    int num[20];
    int i = 0;
    int *p;
    p = &num[0];
    void Process(int *p, int num[]);
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }

    Process(p, num);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }


    return 0;
}

void Process(int *p, int num[])
{
    int m, n, i;
    int *t, *q;
    i = 0;
    m = 3;
    n = 20;
    // 第0个换到第3个；
    t = &num[3];
    num[3] = num[0];
    // 第3个换到第6个；
    q = &num[6];
    num[6] = *t;
    // 第6个换到第9个；
    t = &num[9];
    num[9] = *q;
    // 第9个换到第2个；
    q = &num[2];
    num[2] = *t;
    // 第2个换到第5个；
    t = &num[5];
    num[5] = *q;
    // 第5个换到第8个；
    q = &num[8];
    num[8] = *t;
    // 第8个换到第1个；
    t = &num[1];
    num[1] = *q;
    // 第1个换到第4个；
    q = &num[4];
    num[4] = *t;
    // 第4个换到第7个；
    t = &num[7];
    num[7] = *q;
    // 第7个换到第0个；
    q = &num[0];
    num[0] = *t;
}
