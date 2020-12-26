//求逆序、位数、依次输出
#include<stdio.h>
#include<math.h>
int main()
{
    int start, start2;
    int chu;
    int yu;
    int base;
    int bit = 0;
    int ni = 0;

    printf("请输入一个正整数：");
    scanf("%d", &start);
    start2 = start;
    printf("他的逆序为：");
    while (start != 0)
    {
        yu = start % 10;
        printf("%d", yu);
        start = start / 10;
        ni = ni * 10 + yu;
        bit++;
    }
    putchar('\n');
    printf("它是%d位数\n", bit);
    printf("它的各位数字为：");
    while (bit != 0)
    {
        bit--;
        base = (int) pow(10,(bit));
        chu = start2 / base;
        yu = start2 % base;
        printf("%d ", chu);
        start2 = yu;
    }
    putchar('\n');
    return 0;
}