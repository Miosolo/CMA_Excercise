#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *pFile = NULL;
    pFile = fopen("C:/Users/mx_028/Dropbox/Programming/C/CMA_Excercise/Report_5/test_3.txt", "r+");

    rewind(pFile);
    fprintf(pFile, "\n\n\n");

    fclose(pFile);

    return 0;
}