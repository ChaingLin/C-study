// copy学习
// 有n个整数,使前面各数顺序向后移m个位置,最后 m个数变成最前面 m个数,写一个函数实现以上功能,在主函数中输入n个整数和输出调整后的n个数。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 看会了。qwq
int main()
{
    void move(int *p, int n, int m);
    int a[30];
    int *p = a;
    int m, n;

    printf("input the n:\n");
    scanf("%d", &n);

    printf("input the num:\n");
    for (p = a; p < a + n;)
        scanf("%d", p++);

    printf("input the m:\n");
    scanf("%d", &m);

    p = a; // 这里不可删除， 让p重新指向a[0]

    move(p, n, m);

    for (p = a; p < a + n;)
        printf("%d ", *p++);
    putchar('\n');
    return 0;
}

void move(int *p, int n, int m)
{
    int i;
    for (i = n - 1; i >= 0; i--) //这个循环是依次往后移动m个位置
    {
        *(p + i + m) = *(p + i);
    }
    for (i = n; i < n + m; i++) //这个循环是把后面m个数移到最开始
    {
        // *p++ = *(p + n); // *p++ 等价于 *(p++), 引用p的值实现*p运算， 然后再使p的值+1
        *p = *(p + n);  // p一开始指向a[0]， 所以现在相当于p指向第一个数， 让第一个数的值先等于第10个数
                            //然后第2个数的值等于第11个数，依次类推，直到移动的最后一个数为止。
        p = p + 1;      
    }
}