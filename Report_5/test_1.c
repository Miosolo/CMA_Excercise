#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_PATH "C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/GoodInfo.csv"

int main(void)
{
    FILE *ptable;
    if ((ptable = fopen(CSV_PATH, "r+")) == NULL)
        printf("Fail");
    else
        printf("Success!");
    return 0;
}