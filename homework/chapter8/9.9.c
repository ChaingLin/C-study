// 综合本章例9.9

#include<stdio.h>
#include<stdlib.h>
struct link *Add(struct link *head);
struct link *Delete(struct link *head);
struct link *Addfirst(struct link *head,long a,float b);

struct link{
	long num;
	float scord;
	struct link *next;
};
//void print(struct link*head)
//{
//	struct link*p=head;
//	if(head!=NULL)
//	do{
//		printf("%ld\t%0.2f\n",p->num,p->scord);
//		p=p->next;
//	}while(p->next!=NULL);
//	else
//	printf("空表\n");
//}


void print(struct link *head){        
	struct link *p = head;	
	if(p==NULL)
	printf("链表为空");
	else{
								
	while(p != NULL){		
		printf("%ld\t%0.2f\n",p->num,p->scord);	
		p = p->next;		
		}
	}
	printf("\n");
}
int main()
{
	int a=0,b,c,d,people=0,firs,x=1;
	float y;
	struct link *head = NULL;
	printf("请输入初始数据，0结束\n");
	while(x!=0)
	{
		scanf("%ld.%f",&x,&y);
		if(x==0)break;
		head=Addfirst(head,x,y);
	}
	printf("\n");
	print(head);
	printf("\n");
	while(a==0)
	{
		if(head==NULL)
		{
		printf("1.添加\t");  
		printf("2.退出\t\n"); 
		scanf("%d",&b);
		if(b==1)
		{
			head=Add(head);
			people++;
			print(head);
			
		}
		if(b==2){
		
		a=1;	
			
		}
		}
		else{
		
		printf("1.添加\t"); 
		printf("2.删除\t"); 
		printf("3.退出\t\n"); 
		scanf("%d",&b);
		if(b==1)
		{
			head=Add(head);
			people++;
			print(head);
			
		}
		if(b==2){
			head=Delete(head);
			people--;
			print(head);
			
			
		}
		if(b==3)
		{
			a=1;
		}
		}
	}
	return 0;
}
struct link *Add(struct link *head){    
	struct link *p = NULL,*pr = head,*p1;      
	int num;
	float scord;
	p = (struct link *)malloc(sizeof(struct link)) ; 

	printf("请输入学号.成绩");                   
	scanf("%ld.%f",&num,&scord);
	p->num = num;
	p->scord = scord;
	if(head == NULL)
	{
		head=p;
		p->next = NULL;
	}
	else{
		if(num<head->num)
		{
			head=p;
			p->next=pr;
			
		}
		else{
				
			do
			{
			
				if(pr->next==NULL)break; 
				p1=pr;
				pr = pr->next;			
			}while(pr->num<num);
			if(pr->next==NULL)
			{
				if(pr->num>num)
				{
				p1->next=p;
				p->next=pr;
				}
				else
				{
					pr->next=p;
					p->next=NULL;
				}
			}
			else{
				p->next=p1->next;
				p1->next=p;
			}
		}
	}
	printf("已经添加学号为%ld 成绩为%0.2f\n\n",num,scord);
	return head;			
}
struct link *Delete(struct link *head){    
	struct link *p = NULL,*pr = head,*com;  
	int c=0;    
	int num;
	printf("请输入学号");                   
	scanf("%ld",&num);
	if(pr->num==num)
	{
		head=pr->next;
		free(pr);
		c=1;
	}
	else
	{
		do
		{
			if(pr->num==num)
			{
				com->next=pr->next;
				free(pr);
				c=1;
				break;
			}
			com=pr;
			pr=pr->next;
			
		}while(pr->next!=NULL);
		if(pr->num==num)
		{
				com->next=pr->next;
				free(pr);
				c=1;
		}
		
	}
	if(c==1)printf("已删除%d\n",num);
	else printf("没找到\n");
	return head;			
}

struct link *Addfirst(struct link *head,long a,float b){    
	struct link *p = NULL,*pr = head,*p1;      
	long num;
	float scord;
	p = (struct link *)malloc(sizeof(struct link)) ; 
	num=a;
	scord=b;
	p->num = num;
	p->scord = scord;
	if(head == NULL)
	{
		head=p;
		p->next = NULL;
	}
	else{
		if(num<head->num)
		{
			head=p;
			p->next=pr;
			
		}
		else{
				
			do
			{
			
				if(pr->next==NULL)break; 
				p1=pr;
				pr = pr->next;
				
				
							
			}while(pr->num<num);
			if(pr->next==NULL)
			{
				if(pr->num>num)
				{
				p1->next=p;
				p->next=pr;
				}
				else
				{
					pr->next=p;
					p->next=NULL;
				}
			}
			else{
				p->next=p1->next;
				p1->next=p;
			}
		}
	}
		return head;
	}


