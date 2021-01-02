#include <stdio.h>
#include <string.h>

int main()
{
    void count_digit(char *str);

    char a[100] = {0};

    printf("输入一串字符串：\n");
    gets(a);

    count_digit(a);
    
    printf("\n");
    return 0;
}

void count_digit(char *str)
{
    int digit[100];
    int count = 0;
    int i = 0;
    int str_len = strlen(str);

    char *ptr;
    ptr = str;

    while (i < str_len)
    {
        if (*(ptr + i) >= '0' && *(ptr + i) <= '9') // 这边因为用的是字符数组，所以数字必须要写成字符的形式‘0’，而不能写成 0 
        {
            int len = 1;
            while (*(ptr + i + len) >= '0' && *(ptr + i + len) <= '9' && (i + len) < str_len)
            {
                len++;
            }

            int sum = *(ptr + i + len - 1) - 48;  // 直接储存第个位数
            // 因为字符数组实际上存储的是ASCII码，0的ASCII码是48，所以这边指针获取到的其实是ascii的值，要想变成可计算的数所以要减去48

            int unit = 1;
            for (int j = len - 2; j >= 0; j--) // 从十位开始累加
            {
                unit = 10 * unit;
                sum += (*(ptr + i + j) - 48) * unit;
                
            }
            digit[count++] = sum;
            i += len;
        }
        i++;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d ", digit[i]);
    }
    return;
}