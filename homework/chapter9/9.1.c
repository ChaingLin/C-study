// 定义一个结构体变量（包括年月日）。计算该日在本年中是第几天，注意闰年问题。
#include <stdio.h>

struct Date
{
    int yyyy;
    int mm;
    int dd;
};
int monthp[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int i;

int main()
{
    int thisYearDay(struct Date day);
    int runYear(int year);
    int da1, da2, thisYear, days = 0;

    struct Date day1, day2;
    scanf("%d %d %d", &day1.yyyy, &day1.mm, &day1.dd);
    scanf("%d %d %d", &day2.yyyy, &day2.mm, &day2.dd);

    thisYear = runYear(day1.yyyy);
    da1 = thisYear - thisYearDay(day1);
    da2 = thisYearDay(day2);

    for (int year = day1.yyyy + 1; year < day2.yyyy; year++)
    {
        thisYear = runYear(year);
        days += thisYear;
    }

    days = days + da1 + da2;

    printf("%d\n", days);
    return 0;
}

int thisYearDay(struct Date day)
{
    int days = 0;
    int thisYear;
    if (day.yyyy % 4 == 0 || day.yyyy % 400 == 0)
    {
        for (i = 0; i < day.mm - 1; i++)
        {
            days += monthr[i];
        }
    }
    else
    {
        for (i = 0; i < day.mm - 1; i++)
        {
            days += monthp[i];
        }
    }
    days += day.dd;
    // return (thisYear - days);
    return (days);
}

int runYear(int year)
{
    int thisYear;
    if (year % 4 == 0 || year % 400 == 0)
    {
        thisYear = 366;
    }
    else
    {
        thisYear = 365;
    }
    return (thisYear);
}