#include <stdio.h>
#include <string.h>

int main()
{
    char str[50], *pstr;                    //字符指针和指向字符指针的数组
    int a[10], *pa, i, j, k, sum, num, e10; //存放数字的数组a，指向a的指针pa，数字num，数字总数sum，位数所乘因子e10
    printf("please enter a string ");
    gets(str);
    pstr = &str[0];
    pa = &a[0];
    num = 0;
    i = 0;
    j = 0;
    sum = 0, e10 = 1;
    while ((*pstr + i) != '\0') //遍历字符串
    {
        if ((*(pstr + i) <= '0') && (*(pstr + i) >= '9'))
            j++; //统计连续的数字个数
        else
        {
            if (j > 0)
            {                                  //将个位赋予num
                num = (*(pstr + i - 1) - '0'); //变量保存的是字符而非整数，故减去‘0’，或减去48
                k = 1;
                while (k < j)
                {
                    e10 = e10 * 10;                                //e10代表该位数所应乘的因子
                    num = num + (*(pstr + i - 1 - k) - '0') * e10; //将该位数累加于num
                    k++;                                           //位数k自增
                }
                *pa = num; //指针pa指向a数组下一个元素
                sum++;
                pa++;
                j = 0;
            }
        }
    }
    if (j > 0) //如果以数字结尾，扫描到最后一位j不等于0，而扫描已结束，该字符没有取出，所以再加一次循环
    {
        num = (*(pstr + i - 1) - '0');
        k = 1;
        while (k < j)
        {
            e10 = e10 * 10;
            num = num + (*(pstr + i - 1 - k) - '0') * e10;
            k++;
        }
        *pa = num;
        sum++;
        j = 0;
    }
    printf("there are %d numbers in this line,they are:\n", sum);
    j = 0;
    pa = &a[0];
    for (j = 0; j < sum; j++)
    {
        printf("%d", *(pa + j));
    }
    printf("\n");
    return 0;
}