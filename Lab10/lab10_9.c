#include <stdio.h>
#include <string.h>

int main()
{
    char one_line[451];
    int total_chars = 0;
    int total_words = 0;
    int total_lines = 0;

    while (scanf(" %[^\n]", one_line) == 1)
    {
        if (strcmp(one_line, ".") == 0)
        {
            break;
        }

        total_lines++;

        char line_copy[451];
        strcpy(line_copy, one_line);

        char *separator = " ";
        char *one_word = strtok(line_copy, separator);

        while (one_word != NULL)
        {
            total_words++;
            one_word = strtok(NULL, separator);
        }

        int length = strlen(one_line);
        for (int i = 0; i < length; i++)
        {
            if (one_line[i] != ' ')
            {
                total_chars++;
            }
        }
    }

    printf("Char = %d, word = %d, line = %d\n", total_chars, total_words, total_lines);

    return 0;
}
