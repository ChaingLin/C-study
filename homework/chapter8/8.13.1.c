#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double integral(double (*arry)(double), double a, double b, int n)
{
	double i, s = 0;
	double h = (b-a)/n;
	for(i = a;i <=b;i+=h)
	{
		s += arry(i) * h;//分成n份后，每一份分别相加 
	}
	return(s);
}

int main()
{
	int n = 1000000;
	int m;//定义一个switch的函数名，用来接收函数 
	double a, b;
	while (1)//写一个死循环 
	{
		printf("\n1 sin(x)  2 cos(x)  3 exp(x)  0 exit\n");
		printf("请选择：");
		scanf("%d", &m);
		if(m != 0)
		{
			printf("请输入积分下限和上限：");
			scanf("%lf,%lf", &a,&b);
			switch(m)
			{
				case 1: printf("value = %lf\n", integral(sin, a, b, n)); break;
				case 2: printf("value = %lf\n", integral(cos, a, b, n)); break;
				case 3: printf("value = %lf\n", integral(exp, a, b, n)); break;
	 		}
	 	}
		else if(m == 0)
	 	{
	 		return 0;
		 }
	}
	return 0;
 } 
