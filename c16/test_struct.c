#include <stdio.h>

int main(void)
{
    struct birthday
    {
        int year;
        int month;
        int day;
    };

    struct student
    {
        int num;
        char name[20];
        struct birthday date;
    };
    struct student stu1 = {1, "James", 31}, stu2 = stu1;

    printf("%d %s %d", stu1.num, stu1.name, stu1.)
}