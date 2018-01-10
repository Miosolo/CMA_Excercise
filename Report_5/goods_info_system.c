#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------define--------------
#define MAX_GOODS_KIND 200
#define MAX_NAME_LENGTH 50
#define MAX_DATA_LINE_LENGTH 200
#define CSV_SEPARATOR ","
#define CSV_PATH "./goodsInfo.csv"
#define TMP_CSV_PATH "./goodsInfoTmp.csv"
#define SYS_ERROR_MSG "系统出错，请重试\n"
#define SEPARATE_RULE "*************************************************************************************\n"

//---------structs-------------
struct info
{
    long id;
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
int searchPort(void);
int writeCvs(FILE *pFile);
void printGoods(int printTarget);
int searchId(long Id);
int searchName(char *name);
void editGoods(void);
void deleteGoods(void);
void insertGoods(void);
void searchGoods(void);
void printPause(void);
void showAllGoods(void);
void bubbleSort(void);
void swapStruct(int a, int b);
void printGoodsLine(int printTarget);
void clearInput(void);

int main(void)
{
    FILE *pTable;
    if ((pTable = fopen(CSV_PATH, "r")) == NULL)
    {
        printf("错误：找不到所需的cvs表格\n");
        printPause();
        return 0;
    }

    if (readCvs(pTable) == EXIT_SUCCESS)
        ;
    else
    {
        return 0;
    }

    //----------use functions------------
    printf("\n超市商品管理系统\n\n");
    bool StayIn = true;
    while (StayIn)
    {
        switch (chooseFunction())
        {
        case 1:
            editGoods();
            break;
        case 2:
            searchGoods();
            break;
        case 3:
            deleteGoods();
            break;
        case 4:
            insertGoods();
            break;
        case 5:
            showAllGoods();
            break;
        default:
            StayIn = false;
            break;
        }
    }

    //-----------shut down the system-----------
    if (writeCvs(pTable) == EXIT_SUCCESS)
        ;
    else
    {
        printf("出现严重错误，无法保存您的数据\n");
        printPause();
        return 0;
    }

    fclose(pTable);
    pTable = NULL;

    //----------replace the old fie---------
    if (remove(CSV_PATH) == EXIT_SUCCESS)
    {
        if (rename(TMP_CSV_PATH, CSV_PATH) == EXIT_SUCCESS)
            ;
        else
        {
            printf("出现严重错误，无法保存您的数据\n");
            printPause();
            return 0;
        }
    }
    else
    {
        printf("出现严重错误，无法保存您的数据\n");
        printPause();
        return 0;
    }

    printf("您已顺利退出系统\n");
    printPause();

    return 0;
}

int readCvs(FILE *pFile)
{
    char *buffer = (char *)malloc((long)MAX_DATA_LINE_LENGTH * sizeof(char));

    rewind(pFile);
    fgets(buffer, MAX_DATA_LINE_LENGTH, pFile); //skip the fist line (headers)
    for (int kind = 0; kind < MAX_GOODS_KIND && fgets(buffer, MAX_DATA_LINE_LENGTH, pFile) != NULL; kind++)
    {
        goodsInfo[kind] = (struct info *)malloc((long)sizeof(struct info));

        for (int i = 0; i < 6; i++) //every kind of goods has 6 properties
        {
            switch (i)
            {
            case 0:
                goodsInfo[kind]->id = atoi(strtok(buffer, CSV_SEPARATOR));
                break;
            case 1:
                strcpy(goodsInfo[kind]->name, strtok(NULL, CSV_SEPARATOR));
                break;
            case 2:
                goodsInfo[kind]->price = atof(strtok(NULL, CSV_SEPARATOR));
                break;
            case 3:
                goodsInfo[kind]->discount = atof(strtok(NULL, CSV_SEPARATOR));
                break;
            case 4:
                goodsInfo[kind]->amount = atoi(strtok(NULL, CSV_SEPARATOR));
                break;
            case 5:
                goodsInfo[kind]->remain = atoi(strtok(NULL, CSV_SEPARATOR));
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
        SEPARATE_RULE
        "请选择您想要执行的功能\n"
        "1：编辑商品信息\n"
        "2：搜索商品信息\n"
        "3：删除商品信息\n"
        "4：插入商品信息\n"
        "5：显示所有商品信息\n"
        "其他：保存数据并退出系统\n"
        SEPARATE_RULE
        "请输入您的选择：");
    scanf("%d", &choice);

    return choice;
}

void searchGoods(void)
{
    int targetGoods = searchPort();

    if (targetGoods != MAX_GOODS_KIND)
    {
        printGoods(targetGoods);
        printPause();
    }

    return;
}

int searchPort(void)
{
    int targetGoods = MAX_GOODS_KIND, mode;

    printf(
        "\n请选择搜索依据：\n"
        "1：商品ID\n"
        "2：商品名称\n"
        "请输入您的选择：");
    scanf("%d", &mode);

    if (mode == 1)
    {
        long targetId;

        printf("\n请输入商品ID：");
        scanf("%ld", &targetId);
        if ((targetGoods = searchId(targetId)) != MAX_GOODS_KIND)
            ;
        else
        {
            printf("找不到相应商品\n");
            printPause();
            return MAX_GOODS_KIND;
        }
    }
    else if (mode == 2)
    {
        char targetName[MAX_NAME_LENGTH + 1];
        printf("\n请输入商品名称：");
        scanf("%s", targetName);
        if ((targetGoods = searchName(targetName)) != MAX_GOODS_KIND)
            ;
        else
        {
            printf("找不到相应商品\n");
            printPause();
            return MAX_GOODS_KIND;
        }
    }
    else
    {
        printf("请输入正确的选项\n");
    }

    return targetGoods;
}

void printPause(void)
{
    printf("\n按任意键继续\n");
    clearInput();
    getchar();

    return;
}

void printGoods(int printTarget)
{
    printf(
        SEPARATE_RULE
        "\n商品信息：\n\n"
        "ID: %ld\t\t名称：%s\n"
        "原价：%.3f\t\t折扣：%.0f%%\n"
        "现价：%.3f\n"
        "总库存：%d\t\t剩余库存：%d\n\n" SEPARATE_RULE,
        goodsInfo[printTarget]->id, goodsInfo[printTarget]->name, goodsInfo[printTarget]->price,
        goodsInfo[printTarget]->discount, goodsInfo[printTarget]->price * (1 - goodsInfo[printTarget]->discount / 100),
        goodsInfo[printTarget]->amount, goodsInfo[printTarget]->remain);

    return;
}

void printGoodsLine(int printTarget)
{
    printf(
        "%ld\t%s\t%.3f\t%.3f\t%.3f\t%d\t%d\n",
        goodsInfo[printTarget]->id, goodsInfo[printTarget]->name, goodsInfo[printTarget]->price,
        goodsInfo[printTarget]->discount, goodsInfo[printTarget]->price * (1 - goodsInfo[printTarget]->discount / 100), goodsInfo[printTarget]->amount, goodsInfo[printTarget]->remain);

    return;
}

int searchId(long Id)
{
    for (int i = 0; i < MAX_GOODS_KIND && goodsInfo[i] != NULL; i++)
    {
        if (goodsInfo[i]->id == Id)
        {
            return i;
        }
    }

    return MAX_GOODS_KIND;
}

int searchName(char *name)
{
    for (int i = 0; i < MAX_GOODS_KIND && goodsInfo[i] != NULL; i++)
    {
        if (strcmp(goodsInfo[i]->name, name) == 0)
        {
            return i;
        }
    }

    return MAX_GOODS_KIND;
}

void editGoods(void)
{
    int editTarget = searchPort();
    if (editTarget == MAX_GOODS_KIND)
        return;
    printGoods(editTarget);

    char *buffer = malloc((long)MAX_NAME_LENGTH * sizeof(char));

    printf("请输入新的信息，或按回车键跳过此项\n");

    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("ID: ");
            clearInput();
            fgets(buffer, sizeof(char) * MAX_NAME_LENGTH, stdin);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->id = atol(buffer);
            break;

        case 1:
            printf("商品名称：");
            clearInput();
            fgets(buffer, sizeof(char) * MAX_NAME_LENGTH, stdin);
            if (*buffer == '\0')
                break;
            else
                strcpy(goodsInfo[editTarget]->name, buffer);
            break;

        case 2:
            printf("原价：");
            clearInput();
            fgets(buffer, sizeof(char) * MAX_NAME_LENGTH, stdin);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->price = atof(buffer);
            break;

        case 3:
            printf("折扣(%%): ");
            clearInput();
            fgets(buffer, sizeof(char) * MAX_NAME_LENGTH, stdin);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->discount = atof(buffer);
            break;

        case 4:
            printf("总库存：");
            clearInput();
            fgets(buffer, sizeof(char) * MAX_NAME_LENGTH, stdin);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->amount = atoi(buffer);
            break;

        case 5:
            printf("剩余库存：");
            clearInput();
            fgets(buffer, sizeof(char) * MAX_NAME_LENGTH, stdin);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->remain = atoi(buffer);
            break;
        }
    }

    free(buffer);
    buffer = NULL;

    printf("成功更新商品信息\n");
    printPause();
    return;
}

void deleteGoods(void)
{
    int deleteTarget = searchPort();

    if (deleteTarget != MAX_GOODS_KIND)
    {
        printf("确定要删除这个商品的信息：%s, ID: %ld？（键入Y或y以确认）\n", goodsInfo[deleteTarget]->name, goodsInfo[deleteTarget]->id);
        char choice;
        clearInput();
        choice = getchar();
        if (choice == 'Y' || choice == 'y')
        {
            free(goodsInfo[deleteTarget]);
            goodsInfo[deleteTarget] = NULL;
            printf("删除成功\n");
        }
        else
        {
            printf("已取消删除\n");
        }

        printPause();
    }

    return;
}

void insertGoods(void)
{
    int insertTarget = -1;
    while (goodsInfo[++insertTarget] != NULL)
    {
        if (insertTarget == MAX_GOODS_KIND)
        {
            printf("严重错误：商品信息库已满\n");
            printPause();
            return;
        }
        else
            ;
    }
    goodsInfo[insertTarget] = (struct info *)malloc((long)sizeof(struct info));

    printf("输入新商品的信息：\n");
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("ID: ");
            scanf("%ld", &(goodsInfo[insertTarget]->id));
            break;

        case 1:
            printf("名称：");
            clearInput();
            char *buffer = (char *)malloc((long)MAX_NAME_LENGTH * sizeof(char));

            fgets(buffer, sizeof(char) * MAX_NAME_LENGTH, stdin);
            strcpy(goodsInfo[insertTarget]->name, buffer);
            free(buffer);
            buffer = NULL;
            break;

        case 2:
            printf("原价：");
            scanf("%lf", &(goodsInfo[insertTarget]->price));
            break;

        case 3:
            printf("折扣(%%): ");
            double discountTmp;
            scanf("%lf", &discountTmp);
            if (discountTmp > 100)
            {
                printf("请检查您的输入，折扣不能超过100%%.\n");
                i--;
            }
            break;

        case 4:
            printf("总库存：");
            scanf("%d", &(goodsInfo[insertTarget]->amount));
            break;

        case 5:
            printf("剩余库存：");
            int remainTmp;
            scanf("%d", &remainTmp);
            if (remainTmp > goodsInfo[insertTarget]->amount)
            {
                printf("请检查您的输入，剩余库存不能超过总库存 (%d).\n", goodsInfo[insertTarget]->amount);
                i--;
            }
            break;
        }
    }

    printf("新商品已添加\n");
    printPause();
    return;
}

int writeCvs(FILE *pFile)
{
    FILE *pTmp = fopen(TMP_CSV_PATH, "w");
    if (pTmp == NULL)
    {
        printf("错误：无法写入文件\n");
        printPause();
        return EXIT_FAILURE;
    }

    rewind(pTmp);

    fprintf(pTmp, "ID,名称,原价,折扣(%%),总库存,剩余库存\n");
    for (int kind = 0; kind < MAX_GOODS_KIND && goodsInfo[kind] != NULL; kind++)
    {
        fprintf(pTmp, "%ld,%s,%.3f,%.3f,%d,%d\n", goodsInfo[kind]->id, goodsInfo[kind]->name,
                goodsInfo[kind]->price, goodsInfo[kind]->discount, goodsInfo[kind]->amount, goodsInfo[kind]->remain);

        free(goodsInfo[kind]);
        goodsInfo[kind] = NULL;
    }

    if (fclose(pTmp) == EXIT_FAILURE)
    {
        printf("错误：不能保存新文件\n");
        pTmp = NULL;
        printPause();
        return EXIT_FAILURE;
    }

    pTmp = NULL;
    return EXIT_SUCCESS;
}
//------------declare a struct here-------------
struct shortInfo
{
    int arrPosition;
    double price;
} *priceOrder[MAX_GOODS_KIND] = {NULL};

void showAllGoods(void)
{
    int kindAmount;
    for (kindAmount = 0; kindAmount < MAX_GOODS_KIND && goodsInfo[kindAmount] != NULL; kindAmount++)
    {
        priceOrder[kindAmount] = (struct shortInfo *)malloc((long)sizeof(struct shortInfo));
        priceOrder[kindAmount]->price = goodsInfo[kindAmount]->price;
        priceOrder[kindAmount]->arrPosition = kindAmount;
    }

    bubbleSort();

    printf(
        "商品信息（按照价格升序）\n" SEPARATE_RULE
        "ID\t名称\t原价\t折扣(%%)\t现价\t总库存\t剩余库存\n");
    for (int i = 0; i < kindAmount; i++)
    {
        printGoodsLine(priceOrder[i]->arrPosition);
    }
    printPause();

    for (int i = 0; i < kindAmount; i++)
    {
        free(priceOrder[i]);
        priceOrder[i] = NULL;
    }

    return;
}

void bubbleSort(void)
{
    int goodsAmount;
    for (goodsAmount = 0; priceOrder[goodsAmount] != NULL; goodsAmount++)
        ;

    int unsorted = goodsAmount - 1;//behind priceOrder[unsorted] is sorted.
    for (int i = 1; i < goodsAmount; i++)
	{
        int limit = unsorted;
        for (int j = 0; j <= limit - 1; j++)
		{
			if (priceOrder[j]->price > priceOrder[j + 1]->price)
			{
                swapStruct(j, j + 1);
                unsorted = j;
            }
		}
	}
}

void swapStruct(int a, int b)
{
    struct shortInfo *ps;

    ps = priceOrder[a];
    priceOrder[a] = priceOrder[b];
    priceOrder[b] = ps;

    return;
}

void clearInput(void)
{
    char c;
    while((c = getchar()) != '\n' && c != EOF)
        ;

    return;
}