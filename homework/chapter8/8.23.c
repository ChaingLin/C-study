#include <stdio.h>
#include <string.h>

/*void sort(char *p[],int n)
{
	int i,j,k;
	char *t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(strcmp(p[j],p[k])<0) k=j;
		if(k!=i)
		{
			t=p[k];
			p[k]=p[i];
			p[i]=t;
		}
	}
}*/

int partition(char *p[], int left, int right)
{
    int i = left, j = right;
    char *temp = p[left];
    while (i < j)
    {
        while (i < j && strcmp(p[j], temp) >= 0)
            j--;
        p[i] = p[j];
        while (i < j && strcmp(p[i], temp) <= 0)
            i++;
        p[j] = p[i];
    }
    p[i] = temp;
    return (i);
}

void quicksort(char *p[], int left, int right)
{
    int pos;
    if (left < right)
    {
        pos = partition(p, left, right);
        quicksort(p, left, pos - 1);
        quicksort(p, pos + 1, right);
    }
}

int main()
{
    int i, j;
    char *p[5] = {"CHN", "USA", "RUS", "AUS", "JAP"};
    printf("原顺序为：");
    for (i = 0; i < 5; i++)
        printf("%s  ", p[i]);
    putchar('\n');
    quicksort(p, 0, 4);
    printf("排序后为：");
    for (i = 0; i < 5; i++)
        printf("%s  ", p[i]);
    putchar('\n');
    return (0);
}
