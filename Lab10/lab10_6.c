#include <stdio.h>
#include <string.h>

int main()
{
    char text[202];
    scanf(" %[^\n]", text);
    int lenght = strlen(text);

    for (int i = 0; i < lenght - 1; i++)
    {
        for (int j = 0; j < lenght - i - 1; j++)
        {
            if (text[j] > text[j + 1])
            {
                char temp = text[j];
                text[j] = text[j + 1];
                text[j + 1] = temp;
            }
        }
    }
    printf("%s\n", text);

    return 0;
}
