// 快速排序算法
#include <stdio.h>
#include <stdlib.h>

int qiuckSort(int arry[], int begin, int last)
{
    if (begin > last)
    {
        return 0;
    }
    int a = begin; // 把 第一位置 作为左下标
    int b = last; // 把 最后一个位置 作为右下标
    int pivot = arry[begin]; // 把第一个数当作中心轴
    while (begin < last) // 当左下标和右下标还没有重合时
    {
        while (begin < last && pivot <= arry[last]) // 当左下标和右下标还没有重合时 并且 中心轴的数小于右下标所指的数 // 找到第一个小于中心轴的数
        {
            last--; 
        }

        if (pivot > arry[last]) // 如果中心轴 大于 右下标所代表的数
        {
            arry[begin] = arry[last];  // 把这个数放到中心轴 左边 作为当前第一位
            begin++;
        }

        if (begin == last) // 如果左下标和右下标重合，说明排序完成
        {
            arry[begin] = pivot; // 将中心轴的数放入中心
            break;
        }

        while (begin < last && arry[begin] < pivot) // 找到第一个大于中心轴的数
        {
            begin++;
        }

        if (pivot < arry[begin]) // 把这个数丢到中心轴 右边 作为当前最后一位
        {
            arry[last] = arry[begin];
            last--;
        }
        if (begin == last) // 如果左下标和右下标重合，说明排序完成
        {
            arry[begin] = pivot; // 将中心轴的数放入中心
        }
    }
    // 能运行到这里已经说明一轮已经处理完毕，此时 begin==last 所以分别处理左边和右边
    if (last > a)  // 处理左半部分
    {
        qiuckSort(arry, a, last - 1); // 处理a --- last - 1
    }
    if (b > begin) // 处理右半部分
    {
        qiuckSort(arry, begin + 1, b); // 处理 begin + 1 --- b
    }

    return arry;
}

int main()
{
    int i = 0;
    int n;
    int a[] = {34, 23, 42, 43, 54, 12, 18, 42, 56, 31, 131, 42};
    n = sizeof(a)/ sizeof(a[0]);
    printf("%d\n", n);
    
    qiuckSort(a, 0, n - 1);

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
    return 0;
}