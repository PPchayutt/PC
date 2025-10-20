#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char targetChar;
    char text[151];
    int count = 0;

    scanf(" %c", &targetChar);
    scanf(" %[^\n]", text);

    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (tolower(text[i]) == tolower(targetChar))
        {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
