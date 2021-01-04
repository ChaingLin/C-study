// 输入三坐标求三角形面积
#include<stdio.h>
#include<math.h>
int main()
{
	double a[2],b[2],c[2],c1,c2,c3,s,ave;
	printf("请输入三个点的坐标：");
	scanf("%lf%lf",&a[0],&a[1]);
	scanf("%lf%lf",&b[0],&b[1]);
	scanf("%lf%lf",&c[0],&c[1]);
	if(((b[0]-a[0])/(b[1]-a[1]))!=((c[0]-a[0])/(c[1]-a[1])))
	{
		c1=sqrt(pow(b[1]-a[1], 2)+pow(b[0]-a[0],2));

		c2=sqrt(pow(b[1]-c[1], 2)+pow(b[0]-c[0],2));

		c3=sqrt(pow(c[1]-a[1], 2)+pow(c[0]-a[0],2));

		ave=(c1+c2+c3)/2;
		s=sqrt(ave*(ave-c1)*(ave-c2)*(ave-c3));
		printf("面积为%lf",s);
		
	}
	else
		printf("无法构成三角形！");
 } 
