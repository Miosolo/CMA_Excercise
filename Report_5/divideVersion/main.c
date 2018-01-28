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
#define SYS_ERROR_MSG "System error, please try again.\n"
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
int readCsv(FILE *pFile);
int chooseFunction(void);
int searchPort(void);
int writeCsv(FILE *pFile);
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

int main(void)
{
    FILE *pTable;
    if ((pTable = fopen(CSV_PATH, "r")) == NULL)
    {
        printf("Error: cannot find the .Csv file.\n");
        printPause();
        return 0;
    }

    if (readCsv(pTable) == EXIT_SUCCESS)
        ;
    else
    {
        return 0;
    }

    //----------use functions------------
    printf("\nSupermarket Commodity Management System\n\n");
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
    if (writeCsv(pTable) == EXIT_SUCCESS)
        ;
    else
    {
        printf("Severe error: cannot save your changes.\n");
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
            printf("Severe error: cannot save your changes.\n");
            printPause();
            return 0;
        }
    }
    else
    {
        printf("Severe error: cannot save your changes.\n");
        printPause();
        return 0;
    }

    printf("You've successfully exit the system.\n");
    printPause();

    return 0;
}

int readCsv(FILE *pFile)
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
        "Please choose the opreation for items.\n"
        "1: Edit\n"
        "2: Search\n"
        "3: Delete\n"
        "4: Insert\n"
        "5: Show all\n"
        "Otherwise: Save changes and exit.\n" SEPARATE_RULE
        "Please enter your choice: ");
    fflush(stdin);
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
        "\nPlease decide the searching mode\n"
        "1: ID\n"
        "2: Name\n"
        "Please enter your choice: ");
    scanf("%d", &mode);

    if (mode == 1)
    {
        long targetId;

        printf("\nEnter the ID: ");
        scanf("%ld", &targetId);
        if ((targetGoods = searchId(targetId)) != MAX_GOODS_KIND)
            ;
        else
        {
            printf("Item not found.\n");
            printPause();
            return MAX_GOODS_KIND;
        }
    }
    else if (mode == 2)
    {
        char targetName[MAX_NAME_LENGTH + 1];
        printf("\nEnter the entire name: ");
        scanf("%s", targetName);
        if ((targetGoods = searchName(targetName)) != MAX_GOODS_KIND)
            ;
        else
        {
            printf("Item not found.\n");
            printPause();
            return MAX_GOODS_KIND;
        }
    }
    else
    {
        printf("Please enter the right choice.\n");
    }

    return targetGoods;
}

void printPause(void)
{
    printf("\nPress any key to continue.\n");
    fflush(stdin);
    getchar();

    return;
}

void printGoods(int printTarget)
{
    printf(
        SEPARATE_RULE
        "\nItem Details: \n\n"
        "ID: %ld\t\tName: %s\n"
        "MSRP: %.3f\t\tDiscount: %.0f%%\n"
        "Current Price: %.3f\n"
        "Stock: %d\t\tRemain: %d\n\n" SEPARATE_RULE,
        goodsInfo[printTarget]->id, goodsInfo[printTarget]->name, goodsInfo[printTarget]->price,
        goodsInfo[printTarget]->discount, goodsInfo[printTarget]->price * (1 - goodsInfo[printTarget]->discount / 100),
        goodsInfo[printTarget]->amount, goodsInfo[printTarget]->remain);

    return;
}

void printGoodsLine(int printTarget)
{
    printf(
        "%ld\t%s\t\t%.3f\t%.3f\t\t%.3f\t\t%d\t%d\n",
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

    printf("Please enter the new information, or press enter key to skip.\n");

    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("ID: ");
            fflush(stdin);
            gets(buffer);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->id = atol(buffer);
            break;

        case 1:
            printf("Name: ");
            fflush(stdin);
            gets(buffer);
            if (*buffer == '\0')
                break;
            else
                strcpy(goodsInfo[editTarget]->name, buffer);
            break;

        case 2:
            printf("MSRP: ");
            fflush(stdin);
            gets(buffer);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->price = atof(buffer);
            break;

        case 3:
            printf("Discount(%%): ");
            fflush(stdin);
            gets(buffer);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->discount = atof(buffer);
            break;

        case 4:
            printf("Stock: ");
            fflush(stdin);
            gets(buffer);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->amount = atoi(buffer);
            break;

        case 5:
            printf("Remain: ");
            fflush(stdin);
            gets(buffer);
            if (*buffer == '\0')
                break;
            else
                goodsInfo[editTarget]->remain = atoi(buffer);
            break;
        }
    }

    free(buffer);
    buffer = NULL;

    printf("Successfully updated the information.\n");
    printPause();
    return;
}

void deleteGoods(void)
{
    int deleteTarget = searchPort();

    if (deleteTarget != MAX_GOODS_KIND)
    {
        printf("Are you sure to delete this item: %s, ID: %ld? (Enter Y/y to confirm) ", goodsInfo[deleteTarget]->name, goodsInfo[deleteTarget]->id);
        char choice;
        fflush(stdin);
        choice = getchar();
        if (choice == 'Y' || choice == 'y')
        {
            free(goodsInfo[deleteTarget]);
            goodsInfo[deleteTarget] = NULL;
            printf("Successfully deleted.\n");
        }
        else
        {
            printf("Opreation cancelled.\n");
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
            printf("Severe error: item library is full.\n");
            printPause();
            return;
        }
        else
            ;
    }
    goodsInfo[insertTarget] = (struct info *)malloc((long)sizeof(struct info));

    printf("Please enter the information of the new item: \n");
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf("ID: ");
            scanf("%ld", &(goodsInfo[insertTarget]->id));
            break;

        case 1:
            printf("Name: ");
            fflush(stdin);
            char *buffer = (char *)malloc((long)MAX_NAME_LENGTH * sizeof(char));

            gets(buffer);
            strcpy(goodsInfo[insertTarget]->name, buffer);
            free(buffer);
            buffer = NULL;
            break;

        case 2:
            printf("MSRP: ");
            scanf("%lf", &(goodsInfo[insertTarget]->price));
            break;

        case 3:
            printf("Discount(%%): ");
            double discountTmp;
            scanf("%lf", &discountTmp);
            if (discountTmp > 100)
            {
                printf("Please check out your input, discount rate can't be larger than 100%%.\n");
                i--;
            }
            break;

        case 4:
            printf("Stock: ");
            scanf("%d", &(goodsInfo[insertTarget]->amount));
            break;

        case 5:
            printf("Remain: ");
            int remainTmp;
            scanf("%d", &remainTmp);
            if (remainTmp > goodsInfo[insertTarget]->amount)
            {
                printf("Please check out your input, remain can't be larger than stock(%d).\n", goodsInfo[insertTarget]->amount);
                i--;
            }
            break;
        }
    }

    printf("New item added.\n");
    printPause();
    return;
}

int writeCsv(FILE *pFile)
{
    FILE *pTmp = fopen(TMP_CSV_PATH, "w");
    if (pTmp == NULL)
    {
        printf("Error: cannot write the new file.\n");
        printPause();
        return EXIT_FAILURE;
    }

    rewind(pTmp);

    fprintf(pTmp, "ID,Name,MSRP,Discount(%%),Stock,Remain\n");
    for (int kind = 0; kind < MAX_GOODS_KIND && goodsInfo[kind] != NULL; kind++)
    {
        fprintf(pTmp, "%ld,%s,%.3f,%.3f,%d,%d\n", goodsInfo[kind]->id, goodsInfo[kind]->name,
                goodsInfo[kind]->price, goodsInfo[kind]->discount, goodsInfo[kind]->amount, goodsInfo[kind]->remain);

        free(goodsInfo[kind]);
        goodsInfo[kind] = NULL;
    }

    if (fclose(pTmp) == EXIT_FAILURE)
    {
        printf("Error: cannot save the new file.\n");
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
} * priceOrder[MAX_GOODS_KIND] = {NULL};

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
        "Item Details (sorted by MSRP)\n" SEPARATE_RULE
        "ID\tName\t\tMSRP\tDiscount(%%)\tCurrent Price\tStock\tRemain\n");
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

    int unsorted = goodsAmount - 1; //behind priceOrder[unsorted] is sorted.
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