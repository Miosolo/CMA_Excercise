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
#define CSV_PATH "C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/GoodInfo.csv"

//---------structs-------------
struct Info
{
    int id;
    char name[MAX_NAME_LENGTH + 1];
    double price;
    double discount;
    int amount;
    int remain;
};
struct Info GoodInfo[MAX_GOODS_KIND];

//----------prototypes----------

void load_data(FILE *);

int main(void)
{
    FILE *ptable;
    if ((ptable = fopen(CSV_PATH, "r+")) == NULL)
        return 0;
    load_data(ptable);

/*    //----------use functions------------
    bool leave_system = false;
    while (!leave_system)
    {
        switch (choose_function())
        {
        case ALTER:
            alter();
            break;
        case SEARCH:
            search();
            break;
        case DELETE:
            delete ();
            break;
        case INSERT:
            insert();
            break;
        default:
            quit_system();
            break;
        }
    }

    //-----------shut down the system-----------
*/
    return 0;
}

void load_data(FILE *pfile)
{
    struct Info *current_good = GoodInfo;
    char *buffer = (char *)malloc(MAX_DATA_LINE_LENGTH + 1);

    rewind(pfile);
    fgets(buffer, MAX_DATA_LINE_LENGTH, pfile);//skip the fist line (headers)
    while ((current_good < &GoodInfo[200]) && (fgets(buffer, MAX_DATA_LINE_LENGTH, pfile) != NULL))
    {
        for (int i = 0; i < 6; i++) //a kind of good has 6 properties
        {
            switch (i)
            {
                case 0:
                    (*current_good).id = atoi(strtok(buffer, CSV_SEPARATOR));
                    break;
                case 1:
                    strcpy((*current_good).name, strtok(NULL, CSV_SEPARATOR));
                    break;
                case 2:
                    (*current_good).price = atof(strtok(NULL, CSV_SEPARATOR));
                    break;
                case 3:
                    (*current_good).discount = atof(strtok(NULL, CSV_SEPARATOR));
                    break;
                case 4:
                    (*current_good).amount = atoi(strtok(NULL, CSV_SEPARATOR));
                    break;
                case 5:
                    (*current_good).remain = atoi(strtok(NULL, CSV_SEPARATOR));
                    break;
            }
        }
        current_good++;
    }

    return;
}
