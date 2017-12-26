#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char ch, *filename = "./test_fopen_out.txt";
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);

    return 0;
}
