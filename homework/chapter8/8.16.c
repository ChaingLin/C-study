/* 输入一个字符串，内有数字和非数字字符，例如： A123x456 17960？302tab5876
将其中连续的数字作为一个整数，依次存放到一数组a中。例如，123存放在a[0]，456存放在a[1]....
统计共有多少个整数，并输出这些数。 */

#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char str[30];
    // 输入
    printf("请输入一串字符：");
    gets(str);

    // 定义数字
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a[30];
    int num;

    /* 处理
    for ( i = 0; i < strlen(str); i++)
    {
        if (str[i] in num)
        {
            
        }
        
    } */

    // for ( i = 0; i < strlen(str); i++)
    // {
    //     if (str[i] in num)
    //     {               
         
    //     }
        
    // }
    






    putchar('\n');
    return 0;
}