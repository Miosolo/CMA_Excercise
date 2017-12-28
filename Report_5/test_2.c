#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------define--------------
#define MAX_GOODS_KIND 200
#define MAX_NAME_LENGTH 30
#define MAX_DATA_LINE_LENGTH 100
#define CSV_SEPARATOR ","
#define ALTER 1
#define DELETE 2
#define SEARCH 3
#define INSERT 4
#define CSV_PATH "C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/goodsInfo.csv" //最后改成相对路径

//---------structs-------------
struct info
{
    int id;
    char name[MAX_NAME_LENGTH + 1];
    double price;
    double discount;
    int amount;
    int remain;
};
struct info *goodsInfo[MAX_GOODS_KIND] = {NULL};

int main(void)
{
    goodsInfo[0] = (struct info *)malloc((long)sizeof(struct info));
    strcpy(goodsInfo[0]->name, "Apple");

    printf("%s", goodsInfo[0]->name);

    return 0;
}