#include <stdio.h>
#include <string.h>

#define LINE_FILE "Line " TO_STRING(__LINE__) " of file " __FILE__
#define TO_STRING(x) TO_STRING_2(x)
#define TO_STRING_2(x) #x


int main(void)
{
    const char str[] = LINE_FILE;
    printf("%s", str);
}