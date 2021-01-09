// 建立一个基本的动态链表
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student) // LEN代表struct Student类型数据的长度

struct Student
{
    long num;
    float score;
    struct Student *next;
};

int n; // 结点个数。

// 定义一个craet函数，这是一个指针类型的函数，即此函数返回一个指针值
// 它指向一个struct Student 的类型数据。实际上此creat函数带回一个链表的起始地址。
struct Student *creat(void) 
{
    struct Student *head;
    struct Student *p1, *p2;
    n = 0;

    // malloc(LEN)开辟一个长度为LEN的内存区，malloc带回的数据是 不带 任何类型 数据的 指针(void *)
    p1 = p2 = (struct Student *)malloc(LEN); 
    
    // p1->num 的意思是(*p1).num ，即p1是指向struct Student结构体变量的指针，p1->num表示p1指向该结构体中num成员（而不是地址）
    scanf("%ld, %f", &p1->num, &p1->score); 
    
    head = NULL;
    while (p1->num != 0) // 当输入的num不等于0时
    {
        n = n + 1;
        if (n == 1)
        {
            head = p1; // head指向第一个结点
        }
        else
        {
            p2->next = p1; // p1指向新开辟的结点，p2指向链表中最后一个结点，把p1所指向的结点连接到p2所指向的结点的后面
        }
        p2 = p1; // p2也指向p1 同一结点， p2 比 p1慢半拍，因为p2指向的是前一个结点，而且要使这个结点的next指向新开辟的p1
        p1 = (struct Student *)malloc(LEN);
        scanf("%ld, %f", &p1->num, &p1->score);
    }
    p2->next = NULL;

    // 返回链表第一个结点的地址，并在主函数中赋值给指针变量pt
    return (head); 
}

void print(struct Student *head) // 增加打印功能
{
    struct Student *p;
    p = head;
    if (head != NULL)
    {
        do
        {
            printf("\nnum:%ld\nscore:%5.lf\n", p->num, p->score);
            p = p->next;
        } while (p != NULL);
    }
    
}
int main()
{
    struct Student *head;
    head = creat();
    print(head);
    return 0;
}
