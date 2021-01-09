// 写一个函数print， input
#include <stdio.h>
#include <stdlib.h>
#define Len sizeof(struct Student)

struct Student
{
    int num;
    char name[10];
    float score[3];
    struct Student *next;
};
int n;
int i;

struct Student *input(void)
{
    struct Student *head;
    struct Student *p1, *p2;
    n = 0;
    p1 = p2 = (struct Student *)malloc(Len);
    // scanf("%d", "%s", &p1->num, &p1->name);
    scanf("%d", &p1->num);
    scanf("%s", p1->name);

    // for ( i = 0; i < 3; i++)
    // {
    //     scanf("%f", &p1->score[i])
    // }
    scanf("%f,%f,%f", &p1->score[0], &p1->score[1], &p1->score[2]);

    head = NULL;
    while (p1->num != 0)
    {
        n = n + 1;
        if (n == 1)
        {
            head = p1;
        }
        else
        {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (struct Student *)malloc(Len);
        scanf("%d", &p1->num);

        if (p1->num == 0)
        {
            break;
        }
        scanf("%s", p1->name);
        scanf("%f,%f,%f", &p1->score[0], &p1->score[1], &p1->score[2]);
    }
    // for ( n = 1; n < 6; n++)
    // {
        
    //     if (n == 1)
    //     {
    //         head = p1;
    //     }
    //     else
    //     {
    //         p2->next = p1;
    //     }
    //     p2 = p1;
    //     p1 = (struct Student *)malloc(Len);

    //     scanf("%d", &p1->num);
    //     scanf("%s", p1->name);
    //     scanf("%f,%f,%f", &p1->score[0], &p1->score[1], &p1->score[2]);
    // }
    
    p2->next = NULL;
    return (head);
}

void print(struct Student *head)
{
    struct Student *p;
    p = head;
    if (head!= NULL)
    {
        do
        {
            printf("学号：%4d 姓名：%4s\n", p->num, p->name);
            printf("科目1:%4.f 科目2：%4.f 科目3：%4.f\n", p->score[0], p->score[1], p->score[2]);
            putchar('\n');
            p = p->next;
        } while (p != NULL);
    }
}

int main()
{
    struct Student *p;
    p = input();
    print(p);
    return 0;
}