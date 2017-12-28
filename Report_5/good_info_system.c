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

//----------prototypes----------
int readCvs(FILE *pFile);
int chooseFunction(void);
void searchGoods(void);
int writeCvs(FILE *pFile);

int main(void)
{
    FILE *pTable;
    if ((pTable = fopen(CSV_PATH, "r+")) == NULL)
    {
        printf("错误：找不到所需的cvs文件\n");
        return 0;
    }

    if (readCvs(pTable) == EXIT_FAILURE)
    {
        printf("程序启动失败\n");
        return 0;
    }

    //----------use functions------------
    printf("超市商品管理系统\n");
    /*bool StayIn = true;
    while (StayIn)
    {
        switch (chooseFunction())
        {
        case ALTER:
            editGoods();
            break;
        case SEARCH:
            searchGoods();
            break;
        case DELETE:
            delete ();
            break;
        case INSERT:
            insert();
            break;
        default:
            StayIn = false;
            break;
        }
    }
    */
    //-----------shut down the system-----------
    if (writeCvs(pTable) == EXIT_FAILURE)
    {
        printf("保存数据失败\n");
        return 0;
    }

    if (fclose(pTable) == EXIT_SUCCESS)
        printf("成功退出系统\n");

    return 0;
}

int readCvs(FILE *pFile)
{
    char *buffer = (char *)malloc((long)MAX_DATA_LINE_LENGTH * sizeof(char));
    if (buffer == NULL)
        return EXIT_FAILURE;

    rewind(pFile);
    fgets(buffer, MAX_DATA_LINE_LENGTH, pFile); //skip the fist line (headers)
    for (int i = 0; i < MAX_GOODS_KIND && fgets(buffer, MAX_DATA_LINE_LENGTH, pFile) != NULL; i++)
    {
        goodsInfo[i] = (struct info *)malloc((long)sizeof(struct info));
        if (goodsInfo[i] == NULL)
            return EXIT_FAILURE;

        for (int i = 0; i < 6; i++) //every kind of goods has 6 properties
        {
            switch (i)
            {
            case 0:
                goodsInfo[i]->id = atoi(strtok(buffer, CSV_SEPARATOR));
                break;
            case 1:
                //strcpy(goodsInfo[i]->name, strtok(NULL, CSV_SEPARATOR));
                strcpy(goodsInfo[i]->name, "Apple");
                break;
            case 2:
                goodsInfo[i]->price = atof(strtok(NULL, CSV_SEPARATOR));
                break;
            case 3:
                goodsInfo[i]->discount = atof(strtok(NULL, CSV_SEPARATOR));
                break;
            case 4:
                goodsInfo[i]->amount = atoi(strtok(NULL, CSV_SEPARATOR));
                break;
            case 5:
                goodsInfo[i]->remain = atoi(strtok(NULL, CSV_SEPARATOR));
                break;
            }
        }
    }

    free(buffer);
    buffer = NULL;

    return EXIT_SUCCESS;
}

int chooseFunction(void)
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

void searchGoods(void)
{
    return;
}

int writeCvs(FILE *pFile)
{
    char *buffer = (char *)malloc((long)MAX_DATA_LINE_LENGTH * sizeof(char));
    if (buffer == NULL)
        return EXIT_FAILURE;

    rewind(pFile);
    fgets(buffer, MAX_DATA_LINE_LENGTH, pFile); //skip the fist line (headers)

    for (int i = 0; i < MAX_GOODS_KIND && goodsInfo[i] != NULL; i++)
    {
        fprintf(pFile, "%d,%s,%.2f,%.2f,%d,%d\n", goodsInfo[i]->id, goodsInfo[i]->name, goodsInfo[i]->price,
                goodsInfo[i]->discount, goodsInfo[i]->amount, goodsInfo[i]->remain);

        free(goodsInfo[i]);
        goodsInfo[i] = NULL;
    }

    free(buffer);
    buffer = NULL;

    return EXIT_SUCCESS;
}