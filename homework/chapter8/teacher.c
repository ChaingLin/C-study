// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct teach
{
	int number;
	char name[10];
	char sex[4];
	char unit[10];
	char address[15];
	char phone[11];
	float salary;
	float allowance;
	float life;
	float shouldPay;
	float telBill;
	float waterBill;
	float rent;
	float income_tax;
	float cleanBill;
	float fund;
	float total_deduct;
	float realPay;
	struct teach *next;
} teach;
teach *head = NULL;
FILE *fp;
teach *number();
teach *name();
void show(teach *pr);
void show_all();
void read_file();
void kill(teach *pr);
void save();
void menu();
void add();
void change(teach *pr);
void revise();
void search();
void dele();
int test_number(int a);
int main()
{
	read_file();
	menu();
}
int test_number(int a)
{
	int t = 1, f = 0;
	teach *p;
	if (head == NULL)
	{
		return f;
	}
	else
	{
		p = head;
		while (p->number != a)
		{
			p = p->next;
			if (p == NULL)
				return f;
		}
		printf("教师号已存在,请重新输入\n");
		return t;
	}
}

void save() //存档
{
	char filename[] = "teacher.txt";
	fp = fopen(filename, "w");
	if (head == NULL)
	{
	}
	else
	{
		teach *p = head;
		while (p != NULL)
		{
			fprintf(fp, "%s,%s,%s,%s,%s,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", p->name, p->sex, p->unit, p->address, p->phone, p->number, p->salary, p->allowance, p->life, p->shouldPay, p->telBill, p->waterBill, p->rent, p->income_tax, p->cleanBill, p->fund, p->total_deduct, p->realPay);
			p = p->next;
		}
	}
	fclose(fp);
}
void read_file() //文件读取
{
	char filename[] = "teacher.txt";
	fp = fopen(filename, "r+");

	if (fp == NULL)
	{
		fp = fopen(filename, "w");
		if (fp == NULL)
			printf("\n\t文件创建失败");
	}
	else
	{
		int k, l = 0, c = 0;
		while ((k = fgetc(fp)) != EOF)
		{
			if (k == '\n')
			{
				if (c != 1)
					l++;
			}
			c++;
		}
		int number;
		char name[10];
		char sex[4];
		char unit[10];
		char address[15];
		char phone[11];
		float salary;
		float life;
		float allowance;
		float shouldPay;
		float telBill;
		float waterBill;
		float rent;
		float income_tax;
		float cleanBill;
		float fund;
		float total_deduct;
		float realPay;
		teach *p = (teach *)malloc(sizeof(teach));
		rewind(fp);
		for (int i = 0; i < l; i++)
		{
			fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", name, sex, unit, address, phone, &number, &salary, &allowance, &life, &shouldPay, &telBill, &waterBill, &rent, &income_tax, &cleanBill, &fund, &total_deduct, &realPay);
			teach *pn = (teach *)malloc(sizeof(teach));
			pn->number = number;
			strcpy(pn->name, name);
			strcpy(pn->sex, sex);
			strcpy(pn->unit, unit);
			strcpy(pn->address, address);
			strcpy(pn->phone, phone);
			pn->salary = salary;
			pn->life = life;
			pn->allowance = allowance;
			pn->shouldPay = shouldPay;
			pn->telBill = telBill;
			pn->waterBill = waterBill;
			pn->rent = rent;
			pn->income_tax = income_tax;
			pn->cleanBill = cleanBill;
			pn->fund = fund;
			pn->total_deduct = total_deduct;
			pn->realPay = realPay;
			pn->next = NULL;
			p->next = pn;
			p = pn;
			if (head == NULL)
			{
				head = p;
			}
		}
	}
	fclose(fp);
}

void menu()
{
	system("cls");
	char n;
	int x;
	printf("\t***************欢迎使用教师工资管理系统*****************\n\n");
	printf("\t-----------------------菜单列表-------------------------\n");
	printf("\t------------------[1]添加教师信息-----------------------\n");
	printf("\t------------------[2]修改教师信息-----------------------\n");
	printf("\t------------------[3]删除教师信息-----------------------\n");
	printf("\t------------------[4]查询教师信息-----------------------\n");
	printf("\t------------------[0]退出程序---------------------------\n\n");
	printf("\t***********************welcome**************************\n");
	do
	{
		printf("请选择:");
		n = getchar();
		switch (n)
		{
			x = 0;
		case '1':
			add();
			break;
		case '2':
			revise();
			break;
		case '3':
			dele();
			break;
		case '4':
			search();
			break;
		case '0':
			exit(0);
			break;
		default:
			printf("没有符合您选择的功能，请重新输入!");
			x = 1;
		}
	} while (x == 1);
}
void add() //添加教师信息
{
	system("cls");
	teach *pnew;
	pnew = (teach *)malloc(sizeof(teach));
	printf("\n");
	printf("请输入教师信息:");
	printf("\n");
	do
	{
		printf("请输入教师号:");
		scanf("%d", &pnew->number);
	} while (test_number(pnew->number));
	printf("请输入教师姓名:");
	scanf("%s", &pnew->name);
	printf("请输入教师性别:");
	scanf("%s", &pnew->sex);
	printf("请输入教师单位名称:");
	scanf("%s", &pnew->unit);
	printf("请输入教师家庭住址:");
	scanf("%s", &pnew->address);
	printf("请输入教师的电话号码:");
	scanf("%s", &pnew->phone);
	printf("请输入教师基本工资:");
	scanf("%f", &pnew->salary);
	printf("请输入教师的津贴:");
	scanf("%f", &pnew->allowance);
	printf("请输入教师的生活补贴:");
	scanf("%f", &pnew->life);
	printf("请输入教师的电话费:");
	scanf("%f", &pnew->telBill);
	printf("请输入教师的水电费:");
	scanf("%f", &pnew->waterBill);
	printf("请输入教师的房租:");
	scanf("%f", &pnew->rent);
	printf("请输入教师的所得税:");
	scanf("%f", &pnew->income_tax);
	printf("请输入教师的卫生费:");
	scanf("%f", &pnew->cleanBill);
	printf("请输入教师的公积金:");
	scanf("%f", &pnew->fund);
	pnew->shouldPay = pnew->salary + pnew->allowance + pnew->life;
	pnew->total_deduct = pnew->waterBill + pnew->telBill + pnew->rent + pnew->income_tax + pnew->waterBill + pnew->fund;
	pnew->realPay = pnew->shouldPay - pnew->total_deduct;
	//		printf("教师号\t姓名\t性别\t单位\t家庭住址\t电话号\t基本工资\t津贴\t生活补贴\t电话费\t水电费\t房租\t所得税\t卫生费\t公积金\t应付工资\t合计扣款\t实付工资\n");
	//		printf("%-04d\t %-6s\t %-2s\t %-10s\t %-11s\t %-11s\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t %-.2f\t \n",pnew->number,pnew->name,
	//		pnew->sex,pnew->unit,pnew->address,pnew->phone,pnew->salary,pnew->life,pnew->telBill,pnew->waterBill,pnew->rent,pnew->income_tax,pnew->cleanBill,pnew->fund,pnew->shouldPay,pnew->total_deduct,pnew->realPay);
	printf("\n\t教师号:%d", pnew->number);
	printf("\n\t姓名:%s", pnew->name);
	printf("\n\t性别:%s", pnew->sex);
	printf("\n\t单位名称:%s", pnew->unit);
	printf("\n\t家庭住址:%s", pnew->address);
	printf("\n\t电话号码:%s", pnew->phone);
	printf("\n\t基本工资:%.5f", pnew->salary);
	printf("\n\t津贴:%.5f", pnew->allowance);
	printf("\n\t生活补贴:%.5f", pnew->life);
	printf("\n\t电话费:%.5f", pnew->telBill);
	printf("\n\t水电费:%.5f", pnew->waterBill);
	printf("\n\t房租:%.5f", pnew->rent);
	printf("\n\t所得税:%.5f", pnew->income_tax);
	printf("\n\t卫生费:%.5f", pnew->cleanBill);
	printf("\n\t公积金:%.5f", pnew->fund);
	printf("\n\t应发工资:%.5f", pnew->shouldPay);
	printf("\n\t合计扣款:%.5f", pnew->total_deduct);
	printf("\n\t实发工资:%.5f", pnew->realPay);
	printf("\n确认录入该教师的信息吗?  y/n");
	if (getch() == 'y')
	{
		if (head == NULL)
		{
			head = pnew;
			head->next = NULL;
			printf("录入成功!\n");
			save();
			printf("按任意键回到主菜单");
			getch();
			getchar();
			menu();
			return;
		}
		if (head->number > pnew->number)
		{
			teach *pr = head;
			head = pnew;
			head->next = pr;
		}
		else
		{
			teach *p;
			teach *bf;
			p = head;
			while (p->number < pnew->number)
			{
				bf = p;
				p = p->next;
				if (p == NULL)
				{
					bf->next = pnew;
					pnew->next = NULL;
					printf("录入成功!\n");
					save();
					printf("\n-------按任意键回到主菜单--------");
					getch();
					getchar();
					menu();
					return;
				}
			}
			pnew->next = p;
			bf->next = pnew;
		}
		printf("录入成功!\n");
		save();
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
	}
	else
	{
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
		return;
	}
}
void revise() //修改教师信息
{
	getchar();
	system("cls");
	int x;
	int n;
	printf("\t***************欢迎使用教师工资管理系统*****************\n\n");
	printf("\t-----------------------菜单列表-------------------------\n");
	printf("\t------------------[1]根据教师号修改---------------------\n");
	printf("\t------------------[2]根据教师姓名修改-------------------\n");
	printf("\t------------------[3]回到主菜单-------------------------\n");
	printf("\t------------------[0]退出程序---------------------------\n\n");
	printf("\t***********************welcome**************************\n");
	do
	{
		printf("请选择:");
		n = getchar();
		getchar();
		switch (n)
		{
			teach *find;
			x = 0;
		case '1':
			find = number();
			if (find != NULL)
				change(find);
			break;
		case '2':
			find = name();
			if (find != NULL)
				change(find);
			break;
		case '3':
			menu();
			break;
		case '0':
			exit(0);
			break;
		default:
			printf("没有符合您选择的功能，请重新输入!");
			x = 1;
		}
	} while (x == 1);
}
teach *number() //教师号查询
{
	int a;
	printf("请输入教师号:\n");
	scanf("%d", &a);
	if (head == NULL)
	{
		printf("系统中没有该教师号的信息\n");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
		return NULL;
	}
	else
	{
		teach *p = head;
		while (a != p->number)
		{
			p = p->next;
			if (p == NULL)
			{
				printf("系统中没有该教师号的信息\n");
				printf("\n-------按任意键回到主菜单--------");
				getch();
				getchar();
				menu();
				return NULL;
			}
		}
		return p;
	}
}
teach *name() //教师姓名查询
{
	char id[10] = "\0";
	printf("请输入教师姓名:\n");
	gets(id);
	if (head == NULL)
	{
		printf("系统中没有找到此教师\n");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
		return NULL;
	}
	else
	{
		teach *p = head;
		while ((strcmp(id, p->name)) != 0)
		{
			p = p->next;
			if (p == NULL)
			{
				printf("系统中没有找到此教师\n");
				printf("\n-------按任意键回到主菜单--------");
				getch();
				getchar();
				menu();
				return NULL;
			}
		}
		return p;
	}
}
void change(teach *pr)
{
	teach *p;
	printf("\n\t******以下是你要修改的教师工资信息******\n");

	printf("\n\t教师号:%d", pr->number);
	printf("\n\t姓名:%s", pr->name);
	printf("\n\t性别:%s", pr->sex);
	printf("\n\t单位名称:%s", pr->unit);
	printf("\n\t家庭住址:%s", pr->address);
	printf("\n\t电话号码:%s", pr->phone);
	printf("\n\t基本工资:%.5f", pr->salary);
	printf("\n\t津贴:%.5f", pr->allowance);
	printf("\n\t生活补贴:%.5f", pr->life);
	printf("\n\t电话费:%.5f", pr->telBill);
	printf("\n\t水电费:%.5f", pr->waterBill);
	printf("\n\t房租:%.5f", pr->rent);
	printf("\n\t所得税:%.5f", pr->income_tax);
	printf("\n\t卫生费:%.5f", pr->cleanBill);
	printf("\n\t公积金:%.5f", pr->fund);
	printf("\n\t应发工资:%.5f", pr->shouldPay);
	printf("\n\t合计扣款:%.5f", pr->total_deduct);
	printf("\n\t实发工资:%.5f", pr->realPay);
	printf("\n\t\t是否修改？(y/n)");
	if (getch() == 'y')
	{
		printf("\n\t请重新输入以下信息:\n");
		printf("请输入教师姓名:");
		scanf("%s", &pr->name);
		printf("请输入教师性别:");
		scanf("%s", &pr->sex);
		printf("请输入教师单位名称:");
		scanf("%s", &pr->unit);
		printf("请输入教师家庭住址:");
		scanf("%s", &pr->address);
		printf("请输入教师的电话号码:");
		scanf("%s", &pr->phone);
		printf("请输入教师基本工资:");
		scanf("%f", &pr->salary);
		printf("请输入教师的津贴:");
		scanf("%f", &pr->allowance);
		printf("请输入教师的生活补贴:");
		scanf("%f", &pr->life);
		printf("请输入教师的电话费:");
		scanf("%f", &pr->telBill);
		printf("请输入教师的水电费:");
		scanf("%f", &pr->waterBill);
		printf("请输入教师的房租:");
		scanf("%f", &pr->rent);
		printf("请输入教师的所得税:");
		scanf("%f", &pr->income_tax);
		printf("请输入教师的卫生费:");
		scanf("%f", &pr->cleanBill);
		printf("请输入教师的公积金:");
		scanf("%f", &pr->fund);
		pr->shouldPay = pr->salary + pr->allowance + pr->life;
		pr->total_deduct = pr->waterBill + pr->telBill + pr->rent + pr->income_tax + pr->waterBill + pr->fund;
		pr->realPay = pr->shouldPay - pr->total_deduct;
		pr->number = pr->number;

		save();
		printf("--------修改成功!-------");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
	}
	else
	{
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
	}
}
void dele()
{
	getchar();
	system("cls");
	int x;
	char n;
	printf("\t***************欢迎使用教师工资管理系统*****************\n\n");
	printf("\t-----------------------菜单列表-------------------------\n");
	printf("\t------------------[1]根据教师号删除---------------------\n");
	printf("\t------------------[2]根据教师姓名删除-------------------\n");
	printf("\t------------------[3]回到主菜单-------------------------\n");
	printf("\t------------------[0]退出程序---------------------------\n\n");
	printf("\t***********************welcome**************************\n");
	do
	{
		printf("请选择:");
		n = getchar();
		getchar();
		switch (n)
		{
			teach *find;
			x = 0;
		case '1':
			find = number();
			if (find != NULL)
				kill(find);
			break;
		case '2':
			find = name();
			if (find != NULL)
				kill(find);
			break;
		case '3':
			menu();
			break;
		case '0':
			exit(0);
			break;
		default:
			printf("没有符合您选择的功能，请重新输入!");
			x = 1;
		}
	} while (x == 1);
}
void kill(teach *pr)
{
	printf("\n\t******以下是你要删除的教师工资信息******\n");

	printf("\n\t教师号:%d", pr->number);
	printf("\n\t姓名:%s", pr->name);
	printf("\n\t性别:%s", pr->sex);
	printf("\n\t单位名称:%s", pr->unit);
	printf("\n\t家庭住址:%s", pr->address);
	printf("\n\t电话号码:%s", pr->phone);
	printf("\n\t基本工资:%.5f", pr->salary);
	printf("\n\t津贴:%.5f", pr->allowance);
	printf("\n\t生活补贴:%.5f", pr->life);
	printf("\n\t电话费:%.5f", pr->telBill);
	printf("\n\t水电费:%.5f", pr->waterBill);
	printf("\n\t房租:%.5f", pr->rent);
	printf("\n\t所得税:%.5f", pr->income_tax);
	printf("\n\t卫生费:%.5f", pr->cleanBill);
	printf("\n\t公积金:%.5f", pr->fund);
	printf("\n\t应发工资:%.5f", pr->shouldPay);
	printf("\n\t合计扣款:%.5f", pr->total_deduct);
	printf("\n\t实发工资:%.5f", pr->realPay);
	printf("\n\t\t是否删除？(y/n)");
	if (getch() == 'y')
	{
		if (pr->number == head->number)
		{
			head = head->next;
			free(pr);
		}
		else if (pr->next == NULL)
		{
			teach *k;
			k = head;
			while (k->next != pr)
			{
				k = k->next;
			}
			k->next = NULL;
		}
		else
		{
			teach *d = head;
			while (d->next != pr)
			{
				d = d->next;
			}
			d->next = pr->next;
		}
		save();
		printf("\n---------删除成功!---------------");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		menu();
		return;
	}
	else
	{
		printf("\n-------按任意键回到主菜单--------");
		getch();
		menu();
		return;
	}
}
void search()
{
	getchar();
	system("cls");
	int x;
	int n;
	printf("\t***************欢迎使用教师工资管理系统*****************\n\n");
	printf("\t-----------------------菜单列表-------------------------\n");
	printf("\t------------------[1]根据教师号查询---------------------\n");
	printf("\t------------------[2]根据教师姓名查询-------------------\n");
	printf("\t------------------[3]显示所有教师信息-------------------\n");
	printf("\t------------------[4]回到主菜单-------------------------\n");
	printf("\t------------------[0]退出程序---------------------------\n\n");
	printf("\t***********************welcome**************************\n");
	do
	{
		printf("请选择:");
		n = getchar();
		getchar();
		switch (n)
		{
			teach *find;
			x = 0;
		case '1':
			find = number();
			if (find != NULL)
				show(find);
			break;
		case '2':
			find = name();
			if (find != NULL)
				show(find);
			break;
		case '3':
			show_all();
			break;
		case '4':
			menu();
			break;
		case '0':
			exit(0);
			break;
		default:
			printf("没有符合您选择的功能，请重新输入!");
			x = 1;
		}
	} while (x == 1);
}
void show(teach *pr)
{
	printf("\n\t******以下是你要查询的教师工资信息******\n");

	printf("\n\t教师号:%d", pr->number);
	printf("\n\t姓名:%s", pr->name);
	printf("\n\t性别:%s", pr->sex);
	printf("\n\t单位名称:%s", pr->unit);
	printf("\n\t家庭住址:%s", pr->address);
	printf("\n\t电话号码:%s", pr->phone);
	printf("\n\t基本工资:%.5f", pr->salary);
	printf("\n\t津贴:%.5f", pr->allowance);
	printf("\n\t生活补贴:%.5f", pr->life);
	printf("\n\t电话费:%.5f", pr->telBill);
	printf("\n\t水电费:%.5f", pr->waterBill);
	printf("\n\t房租:%.5f", pr->rent);
	printf("\n\t所得税:%.5f", pr->income_tax);
	printf("\n\t卫生费:%.5f", pr->cleanBill);
	printf("\n\t公积金:%.5f", pr->fund);
	printf("\n\t应发工资:%.5f", pr->shouldPay);
	printf("\n\t合计扣款:%.5f", pr->total_deduct);
	printf("\n\t实发工资:%.5f", pr->realPay);
	printf("\n-------按任意键回到主菜单--------");
	getch();
	getchar();
	menu();
}
void show_all()
{
	teach *pnew;
	pnew = head;
	if (head == NULL)
	{
		printf("系统中没有录入教师的数据\n");
	}
	while (pnew != NULL)
	{
		printf("教师号\t姓名\t性别\t单位\t家庭住址    电话号\t基本工资    津贴    生活补贴\t电话费\t水电费\t房租\t所得税\t  卫生费\t公积金\t应付工资    合计扣款    实付工资\n");
		printf("%-04d\t%-6s\t%-2s\t%-6s\t%-6s      %-6s\t%-.1f\t    %-.1f    %-.1f\t%-.1f\t%-.1f\t%-.1f\t %-.1f\t  %-.1f\t%-.1f\t%-.1f\t    %-.1f\t%-.1f\t\n", pnew->number, pnew->name,
			   pnew->sex, pnew->unit, pnew->address, pnew->phone, pnew->salary, pnew->allowance, pnew->life, pnew->telBill, pnew->waterBill, pnew->rent, pnew->income_tax, pnew->cleanBill, pnew->fund, pnew->shouldPay, pnew->total_deduct, pnew->realPay);
		pnew = pnew->next;
	}
	printf("\n-------按任意键回到主菜单--------");
	getch();
	menu();
}
