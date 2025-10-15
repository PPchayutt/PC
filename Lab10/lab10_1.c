#include <stdio.h>
#include <string.h>

int main()
{
    char text[151];
    int j = 0;

    scanf(" %[^\n]s", &text);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != ' ')
        {
            text[j++] = text[i];
        }
    }

    text[j] = '\0';

    printf("%s", text);

    return 0;
}
