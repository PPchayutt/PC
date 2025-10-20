#include <stdio.h>
#include <string.h>

int main()
{
    char current_text[101];
    char new_text[101];

    scanf(" %[^\n]", current_text);

    int string_changed = 1;

    while (string_changed == 1)
    {
        string_changed = 0;
        int length = strlen(current_text);
        int new_index = 0;

        for (int i = 0; i < length; i++)
        {
            if (i + 1 < length && current_text[i] == current_text[i + 1])
            {
                i++;
                string_changed = 1;
            }
            else
            {
                new_text[new_index] = current_text[i];
                new_index++;
            }
        }

        new_text[new_index] = '\0';

        if (string_changed == 1)
        {
            printf("%s\n", new_text);
            strcpy(current_text, new_text);
        }
    }

    return 0;
}
