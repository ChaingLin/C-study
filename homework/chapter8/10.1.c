// 生成数据，10个5门课 数据（学号、5个课成绩）写到 “stud.dat"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct student
{
    long num;
    int scord[5];
    int sum;

} student[10];
int main()
{
    int i = 0, x, sum = 0;
    long n = 2002000;
    FILE *fp = fopen("./stud.dat", "wb");
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
    {
        sum = 0;
        student[i].num = n++;
        for (x = 0; x < 5; x++)
        {
            student[i].scord[x] = (rand() % 101);
            sum = sum + student[i].scord[x];
        }
        student[i].sum = sum;
        printf("%ld\t", student[i].num);
        printf("%d\n", sum / 5);
    }
    for (i = 0; i < 10; i++)
        fwrite(&student[i], sizeof(struct student), 1, fp);
    fclose(fp);
    return 0;
}
