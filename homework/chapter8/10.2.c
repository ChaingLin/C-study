// 从“stud.dat读出，按平均成绩由高到低打印出来”

#include <stdio.h>
struct student
{
    long num;
    int scord[5];
    int sum;

} student[10], swap;
//void swap(struct student a , struct student b)
//{
//	long num;
//	int scord[5];
//	int sum;
//	num=a.num;
//	a.num=b.num;
//	b.num=num;
//	sum=a.sum;
//	a.sum=b.sum;
//	b.sum=sum;
//};
int main()
{
    int i, x, n = 9;

    FILE *fp = fopen("./stud.dat", "rb");
    if (fp == NULL)
        printf("can not open");
    for (i = 0; i < 10; i++)
    {
        fread(&student[i], sizeof(struct student), 1, fp);
    }

    for (i = 0; i < 10; i++)
    {
        for (x = 0; x < n; x++)
        {
            if (student[x].sum < student[x + 1].sum)
            {
                swap = student[x];
                student[x] = student[x + 1];
                student[x + 1] = swap;
            }
        }
        n--;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%ld\t", student[i].num);
        for (x = 0; x < 5; x++)
        {
            printf("%d\t", student[i].scord[x]);
        }
        printf("%d\n", student[i].sum / 5);
    }

    fclose(fp);
    return 0;
}
