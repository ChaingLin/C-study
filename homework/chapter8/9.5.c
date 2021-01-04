// 有10个学生，每个学生的数据包括学号、姓名、3门课程的成绩，从键盘输入10个学生数据，要求输出3门课程的总平均成绩，以及最高分的学生的数据。（包括学号、姓名、3门课程成绩、平均分数）

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float pu1(float a[], int b)
{
    float c = 0;
    int i;
    for (i = 0; i < b; i++)
        c = c + a[i];
    c = c / b;
    return (c);
}
int main()
{
    int m = 3;
    // float a[3][5] = {{70, 70, 70, 70, 70}, {70, 70, 70, 70, 70}, {70, 70, 70, 70, 70}};

    float b[5];
    float c[m];
    int i, x, z = 0, positionx, positiony;

    float a[m][5];
    int r, p;
    time_t t;
    p = 15;
    srand((unsigned)time(&t));
    for (i = 0; i < 3; i++)
    {
        for (x = 0; x < 5; x++)
        {
            a[i][x] = (rand() % 41 + 60);
        }
    }

    float bx, sum;
    printf("学生成绩为:\n");
    for (i = 0; i < m; i++)
    {
        for (x = 0; x < 5; x++)
        {

            printf("%0.2f ", a[i][x]);
        }
        printf("\n");
    }
    printf("学生的平均成绩:");
    for (i = 0; i < m; i++)
    {
        printf("%.2f ", pu1(a[i], 5));
        c[i] = pu1(a[i], 5);
    }
    printf("\n每门课的平均成绩:");
    for (x = 0; x < 5; x++)
    {
        sum = 0;
        for (i = 0; i < m; i++)
        {
            sum = sum + a[i][x];
        }
        b[x] = sum / m;
        printf("%.2f ", b[x]);
    }
    for (x = 0; x < 5; x++)
    {
        for (i = 0; i < m; i++)
        {
            if (a[i][x] > z)
            {
                z = a[i][x];
                positionx = i + 1;
                positiony = x + 1;
            }
        }
    }
    printf("\n最好成绩位置在%d,%d\n", positionx, positiony);
    for (i = 0; i < m; i++)
    {
        bx += c[i];
    }
    bx = bx / m;
    sum = 0;
    for (i = 0; i < m; i++)
    {
        sum = sum + c[i] * c[i];
    }
    sum = sum / m;
    printf("平均分方差为:%.2f", sum - bx * bx);
}
