#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------define--------------
#define MAX_GOODS_KIND 2000
#define MAX_NAME_LENGTH 50
#define MAX_DATA_LINE_LENGTH 200
#define CSV_SEPARATOR ","
#define CSV_PATH "C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/goodsInfo.csv"//最后改成相对路径
#define TMP_CSV_PATH "C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/goodsInfoTmp.csv"//最后改成相对路径
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
void swapP(int a, int b);
int mediumP(int a, int b, int c);
void quickSortP(int left, int right);
void printGoodsLine(int printTarget);

int main(void)
{
    FILE *pTable;
    if ((pTable = fopen(CSV_PATH, "r")) == NULL)
    {
        printf("Error: Cannot find the .cvs file.\n");
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
    if (writeCvs(pTable) == EXIT_SUCCESS)
        ;
    else
    {
        printf("Severe Error: Cannot save your changes.\n");
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
            printf("Severe Error: Cannot save your changes.\n");
            printPause();
            return 0;
        }
    }

    else
    {
        printf("Severe Error: Cannot save your changes.\n");
        printPause();
        return 0;
    }
    printf("Successfully exit the system.\n");

    return 0;
}

int readCvs(FILE *pFile)
{
    char *buffer = (char *)malloc((long)MAX_DATA_LINE_LENGTH * sizeof(char));
    if (buffer != NULL)
        ;
    else
    {
        printf(SYS_ERROR_MSG);
        printPause();
        return EXIT_FAILURE;
    }

    rewind(pFile);
    fgets(buffer, MAX_DATA_LINE_LENGTH, pFile); //skip the fist line (headers)
    for (int kind = 0; kind < MAX_GOODS_KIND && fgets(buffer, MAX_DATA_LINE_LENGTH, pFile) != NULL; kind++)
    {
        goodsInfo[kind] = (struct info *)malloc((long)sizeof(struct info));
        if (goodsInfo[kind] != NULL)
            ;
        else
        {
            printf(SYS_ERROR_MSG);
            printPause();
            return EXIT_FAILURE;
        }

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
        "Please choose what to do with the information of goods:\n"
        "1: Edit\n"
        "2: Delete\n"
        "3: Search\n"
        "4: Insert new\n"
        "5: Show all\n"
        "Otherwise: Exit the system\n"
        SEPARATE_RULE
        "Enter your choice: ");
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
        "\nChoose the searching mode:\n"
        "1: Item ID\n"
        "2: Item name\n"
        "Enter your choice: ");
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
            printf("No result found.\n");
            printPause();
            return MAX_GOODS_KIND;
        }
    }
    else if (mode == 2)
    {
        char targetName[MAX_NAME_LENGTH + 1];
        printf("\nEnter the concret name: ");
        scanf("%s", targetName);
        if ((targetGoods = searchName(targetName)) != MAX_GOODS_KIND)
            ;
        else
        {
            printf("No result found.\n");
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
        "\nItem details:\n\n"
        "ID: %ld\t\tName: %s\n"
        "Original Price: %.3f\tDiscount:%.0f%%\n"
        "Current Price: %.3f\n"
        "Amount: %d\t\tRemain: %d\n\n"
        SEPARATE_RULE,
        goodsInfo[printTarget]->id, goodsInfo[printTarget]->name, goodsInfo[printTarget]->price, 
        goodsInfo[printTarget]->discount, goodsInfo[printTarget]->price * (1 - goodsInfo[printTarget]->discount / 100),
        goodsInfo[printTarget]->amount, goodsInfo[printTarget]->remain);

    return;
}

void printGoodsLine(int printTarget)
{
    printf(
        "%ld\t%s\t%f\t%f\t%f\t%d\t%d\n",
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
    if (buffer != NULL)
        ;
    else
    {
        printf(SYS_ERROR_MSG);
        printPause();
        return;
    }

    printf("Enter the new value, press enter key to skip.\n");

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
            printf("Price: ");
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
            printf("Amount: ");
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
        printf("Are you sure to delete this item: %s, ID: %ld? (Y/y to confirm)\n", goodsInfo[deleteTarget]->name, goodsInfo[deleteTarget]->id);
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
            printf("Delete opreation canceled.\n");
        }

        printPause();
    }

    return;
}

void insertGoods(void)
{
    int insertTarget = -1;
    while(goodsInfo[++insertTarget] != NULL)
    {
        if (insertTarget == MAX_GOODS_KIND)
        {
            printf("Severe Error: Goods library is full.\n");
            printPause();
            return;
        }
        else
            ;
    }
    goodsInfo[insertTarget] = (struct info *)malloc((long)sizeof(struct info));
    if (goodsInfo[insertTarget] != NULL)
        ;
    else
    {
        printf(SYS_ERROR_MSG);
        printPause();
        return;
    }

    printf("Insert new data: \n");
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
            if (buffer != NULL)
                ;
            else
            {
                printf(SYS_ERROR_MSG);
                printPause();
                free(buffer);
                buffer = NULL;
                free(goodsInfo[insertTarget]);
                goodsInfo[insertTarget] = NULL;
                
                return;
            }
            gets(buffer);
            strcpy(goodsInfo[insertTarget]->name, buffer);
            free(buffer);
            buffer = NULL;
            break;
        
        case 2:
            printf("Price: ");
            scanf("%lf", &(goodsInfo[insertTarget]->price));
            break;

        case 3:
            printf("Discount(%%): ");
            double discountTmp;
            scanf("%lf", &discountTmp);
            if (discountTmp >100)
            {
                printf("Please check out your input, the discount rate can't be larger than 100%%.\n");
                i--;
            }
            break;

        case 4:
            printf("Amount: ");
            scanf("%d", &(goodsInfo[insertTarget]->amount));
            break;

        case 5:
            printf("Remain: ");
            int remainTmp;
            scanf("%d", &remainTmp);
            if (remainTmp > goodsInfo[insertTarget]->amount)
            {
                printf("Please check out your input, the number of remain can't be larger than the amount (%d).\n", goodsInfo[insertTarget]->amount);
                i--;
            }
            break;
        }
    }

    printf("Successfully added the new item.\n");
    printPause();
    return;
}

int writeCvs(FILE *pFile)
{
    FILE *pTmp = fopen(TMP_CSV_PATH, "w");
    if (pTmp == NULL)
    {
        printf("Error: Cannot write the new file.\n");
        printPause();
        return EXIT_FAILURE;
    }

    rewind(pTmp);

    fprintf(pTmp, "ID,Name,Price,Discount(%%),Amount,Remain\n");
    for (int kind = 0; kind < MAX_GOODS_KIND && goodsInfo[kind] != NULL; kind++)
    {
        fprintf(pTmp, "%ld,%s,%.3f,%.3f,%d,%d\n", goodsInfo[kind]->id, goodsInfo[kind]->name, 
                goodsInfo[kind]->price, goodsInfo[kind]->discount, goodsInfo[kind]->amount, goodsInfo[kind]->remain);

        free(goodsInfo[kind]);
        goodsInfo[kind] = NULL;
    }

    if (fclose(pTmp) == EXIT_FAILURE)
    {
        printf("Error: Cannot save the new file.\n");
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
}*priceOrder[MAX_GOODS_KIND] = {NULL};

void showAllGoods(void)
{
    int kindAmount;
    for (kindAmount = 0; kindAmount < MAX_GOODS_KIND && goodsInfo[kindAmount] != NULL; kindAmount++)
    {
        priceOrder[kindAmount] = (struct shortInfo *)malloc((long)sizeof(struct shortInfo));
        if (priceOrder[kindAmount] != NULL)
            ;
        else
        {
            printf("Error: Sorting process interupted.\n");
            printPause();
            goto freeStruct;
        }
        priceOrder[kindAmount]->price = goodsInfo[kindAmount]->price;
        priceOrder[kindAmount]->arrPosition = kindAmount;
    }

    quickSortP(0, kindAmount - 1);

    printf
    (
        "Goods details (sorted by original price)\n"
        SEPARATE_RULE
        "ID\tName\tOrigianal Price\tDiscount(%%)\tCurrent Price\tAmount\tRemain\n"
    );
    for (int i = 0; i < kindAmount; i++)
    {
        printGoodsLine(priceOrder[i]->arrPosition);
    }
    printPause();

    freeStruct:
        for (int i = 0; i < kindAmount; i++)
        {
            free(priceOrder[i]);
            priceOrder[i] = NULL;
        }

    return;
}

void swapP(int a, int b)
{
    struct shortInfo *ps;

    ps = priceOrder[a];
    priceOrder[a] = priceOrder[b];
    priceOrder[b] = ps;

    return;
}

int mediumP(int a, int b, int c)
{
    double aPrice = priceOrder[a]->price, bPrice = priceOrder[b]->price, cPrice = priceOrder[c]->price;

    if ((aPrice - bPrice) * (bPrice - cPrice) >= 0)
		return b;
	else
		return bPrice > cPrice ? (aPrice > cPrice ? a : c) : (aPrice > cPrice ? c : a);
}

void quickSortP(int left, int right)
{	
	//if 1 number
	if (right - left == 0)
		return;

	//if 2 numbers(quicksort cannot solve)
	if (right - left == 1)
	{
		if (priceOrder[left]->price > priceOrder[right]->price)
		{
			swapP(left, right);
			return;
		}
		else
			return;
	}

	//my quicksort could arrange >=3 numbers
	//initialize
    double pivotPrice;
    int start = left, end = right, gap = right - left;
	bool next_round = false;

    pivotPrice = priceOrder[mediumP(left, right, (left + right) / 2)]->price;

    //find numbers out of range
	while (!next_round)
	{	while (gap > 0 && priceOrder[left]->price <= pivotPrice)
		{
			left++;
			gap--;
		}
		while (gap > 0 && priceOrder[right]->price >= pivotPrice)
		{
			right--;
			gap--;
		}

		if (gap == 0)
		{
			left--;
			next_round = true;
		}

		if (!next_round)
		{
			swapP(left, right);
		}

	}

	quickSortP(start, left);
	quickSortP(right, end);

	return;
}

