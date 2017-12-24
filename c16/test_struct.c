#include <stdio.h>

int main(void)
{
    student stu1, stu2;
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
}