#include <stdio.h>
#include <string.h>
#include <math.h>

void printBorder(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");
}

void printCenteredLine(int boxWidth, const char *text)
{
    float totalPadding = boxWidth - 2 - strlen(text);
    int leftPadding = ceil(totalPadding / 2.0);
    int rightPadding = floor(totalPadding / 2.0);

    printf("*");
    for (int i = 0; i < leftPadding; i++)
    {
        printf(" ");
    }
    printf("%s", text);
    for (int i = 0; i < rightPadding; i++)
    {
        printf(" ");
    }
    printf("*\n");
}

int main()
{
    int width;
    char str1[51];
    char str2[41];

    scanf("%d", &width);

    scanf(" %[^\n]", str1);
    scanf(" %[^\n]", str2);

    printBorder(width);
    printCenteredLine(width, str1);
    printCenteredLine(width, str2);
    printBorder(width);

    return 0;
}
