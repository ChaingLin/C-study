//输入三个字符串，按由小到大的顺序输出。

#include <stdio.h>
#include <string.h>
int main()
{
    void Compare(char *p, char *q, char *r);
    char str1[10], str2[10], str3[10];
    char *p, *q, *r;
    p = str1;
    q = str2;
    r = str3;
    gets(str1);
    gets(str2);
    gets(str3);

    Compare(p, q, r);
    // puts(str1);
    // puts(str2);
    // puts(str3);
    putchar('\n');
    printf("%s < %s < %s\n", p, q, r);
    printf("%s < %s < %s\n", str1, str2, str3);
    printf("%p %p %p\n", p, q, r);

    return 0;
}

void Compare(char *p, char *q, char *r) // strcmp这个函数是完全的复制，原来的一点都不保存。
{
    char t[10];
    if (strcmp(p, q) > 0)
    {
        // t = q;
        // q = p;
        // p = t;

        strcpy(t, q);
        strcpy(q, p);
        strcpy(p, t);
        
    }

    if (strcmp(p, r) > 0)
    {
        strcpy(t, r);
        strcpy(r, p);
        strcpy(p, t);
        
    }


    if (strcmp(q,r) > 0)
    {
        strcpy(t, r);
        strcpy(r, q);
        strcpy(q, t);
    }
}