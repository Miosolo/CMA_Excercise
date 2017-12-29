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
#define CSV_PATH "C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/goodsInfo.csv"//最后改成相对路径
#define TMP_CSV_PATH "C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/goodsInfoTmp.csv"//最后改成相对路径
#define SYS_ERROR_MSG "System error, please try again.\n"

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
void delete (void);
void insert(void);
void searchGoods(void);
void printPause(void);

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
    printf("Supermarket Commodity Management System\n");
    bool StayIn = true;
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
        "**********************************************\n"
        "Please choose what to do with the information of goods:\n"
        "1: Edit\n"
        "2: Delete\n"
        "3: Search\n"
        "4: Insert new\n"
        "Otherwise: Exit the system\n"
        "**********************************************\n"
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
        printf("\nEnter the name: ");
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
    printf("Press any key to continue.\n");
    fflush(stdin);
    getchar();

    return;
}

void printGoods(int printTarget)
{
    printf(
        "***********************************"
        "\nItem details:\n\n"
        "Name: %s\t\tID: %ld\n"
        "Original Price: %.3f\tDiscount:%.0f%%\n"
        "Current Price: %.3f\n"
        "Amount: %d\t\tRemain: %d\n\n"
        "**********************************\n",
        goodsInfo[printTarget]->name, goodsInfo[printTarget]->id, goodsInfo[printTarget]->price, goodsInfo[printTarget]->discount, goodsInfo[printTarget]->price * (1 - goodsInfo[printTarget]->discount / 100),
        goodsInfo[printTarget]->amount, goodsInfo[printTarget]->remain);

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

void delete (void)
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

void insert(void)
{
    int insertTarget = -1;
    while(goodsInfo[++insertTarget] != NULL)
        ;
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
            printf("Discount: ");
            scanf("%lf", &(goodsInfo[insertTarget]->discount));
            break;

        case 4:
            printf("Amount: ");
            scanf("%d", &(goodsInfo[insertTarget]->amount));
            break;

        case 5:
            printf("Remain: ");
            scanf("%d", &(goodsInfo[insertTarget]->remain));
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