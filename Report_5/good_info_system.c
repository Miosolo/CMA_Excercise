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
#define CSV_PATH "C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/GoodsInfo.csv"

//---------structs-------------
struct Info
{
    int id;
    char name[MAX_NAME_LENGTH + 1];
    double price;
    double discount;
    int amount;
    int remain;
}*GoodsInfo[MAX_GOODS_KIND];

//----------prototypes----------

void read_cvs(FILE *);

int main(void)
{
    FILE *ptable;
    if ((ptable = fopen(CSV_PATH, "r+")) == NULL)
    {   
        printf("错误：找不到所需的cvs文件\n")
        return 0;
    }

    read_cvs(ptable);

    //----------use functions------------
    printf("超市商品管理系统\n");
    bool stay_in = true;
    while (stay_in)
    {
        switch (choose_function())
        {
        case ALTER:
            edit_goods();
            break;
        case SEARCH:
            search_goods();
            break;
        case DELETE:
            delete ();
            break;
        case INSERT:
            insert();
            break;
        default:
            stay_in = false;
            break;
        }
    }

    //-----------shut down the system-----------
    write_cvs(ptable);
    if (fclose(ptable) == EXIT_SUCCESS)
        printf("成功退出系统\n");
    return 0;
}

void read_cvs(FILE *pfile)
{
    struct Info *current_goods = GoodsInfo;
    char *buffer = (char *)malloc(MAX_DATA_LINE_LENGTH + 1);

    rewind(pfile);
    fgets(buffer, MAX_DATA_LINE_LENGTH, pfile);//skip the fist line (headers)
    while ((current_goods < &GoodsInfo[200]) && (fgets(buffer, MAX_DATA_LINE_LENGTH, pfile) != NULL))
    {
        *current_goods = malloc
        for (int i = 0; i < 6; i++) //a kind of goods has 6 properties
        {
            switch (i)
            {
                case 0:
                    (*current_goods).id = atoi(strtok(buffer, CSV_SEPARATOR));
                    break;
                case 1:
                    strcpy((*current_goods).name, strtok(NULL, CSV_SEPARATOR));
                    break;
                case 2:
                    (*current_goods).price = atof(strtok(NULL, CSV_SEPARATOR));
                    break;
                case 3:
                    (*current_goods).discount = atof(strtok(NULL, CSV_SEPARATOR));
                    break;
                case 4:
                    (*current_goods).amount = atoi(strtok(NULL, CSV_SEPARATOR));
                    break;
                case 5:
                    (*current_goods).remain = atoi(strtok(NULL, CSV_SEPARATOR));
                    break;
            }
        }
        current_goods++;
    }

    free(buffer);
    return;
}

int choose_function(void)
{
    int choice;

    printf(
        "**********************************************\n"
        "1.商品信息的修改:\n"
        "2.删除某个商品的信息:\n"
        "3.查找商品信息:\n"
        "4.插入某个商品的信息:\n"
        "其他.退出系统:\n"
        "**********************************************\n"
        "输入您的选择:");
    scanf("%d", &choice);

    return choice;
}

void search_goods(void)
{
    return;
}

void write_cvs(FILE *pfile)
{
    char *buffer = (char *)malloc(MAX_DATA_LINE_LENGTH + 1);
    rewind(pfile);
    fgets(buffer, MAX_DATA_LINE_LENGTH, pfile);//skip the fist line (headers)

    struct Info *current_goods;
    for (current_goods = GoodsInfo; (*current_goods).name[0];current_goods++)
    {
        fprintf(pfile, "%d,%s,%.2f,%.2f,%d,%d\n", (*current_goods).id, (*current_goods).name, (*current_goods).price, (*current_goods).discount, (*current_goods).amount, (*current_goods).remain);
    }

    free(buffer);
    return;
}