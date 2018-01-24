#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int deleteArray(char s[], int n)
{
    int len = strlen(s);

    if (n > len)
    {
        return EXIT_FAILURE;
    }
    else if (n < len)
    {
        char *p = s + n;
        do
        {
            *p = *(p + 1);
            p++;
        } while (*p);
    }
    return EXIT_SUCCESS;
}

int insertArray(char s1[], char s2[], int offset)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    
    if (offset > len1)
    {
        return EXIT_FAILURE;
    }
    else
    {
        char *p = s1 + len1 + len2;

        do
        {
            *p = *(p - len2);
            p--;
        } while ((p - len2) >= (s1 + offset));

        for (int i = 0; i < len2; i++)
        {
            s1[offset + i] = s2[i];
        }
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    char sa[50] = "fj;lkrouqwrfn", sb[] = "750984-12049568";
    int n, offset;

    printf("sa: %s, enter the index n: ", sa);
    scanf("%d", &n);
    deleteArray(sa, n);
    printf("Now sa: %s\n", sa);

    printf("sb: %s, enter the index offset: ", sb);
    scanf("%d", &offset);

    int lenA = strlen(sa), lenB = strlen(sb);
    if (lenA + lenB >= sizeof(sa) / sizeof(sa[0]))
    {
        printf("Array overflow, cannot insert.\n");
    }
    else
    {
        insertArray(sa, sb, offset);
        printf("Now sa: %s\n", sa);
    }

    return 0;
}