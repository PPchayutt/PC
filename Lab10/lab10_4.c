#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char sentence[151];
    char *all_words[50];
    int word_count = 0;

    scanf(" %[^\n]", sentence);

    char *separator = " ";
    char *one_word = strtok(sentence, separator);

    while (one_word != NULL)
    {
        all_words[word_count] = one_word;
        word_count++;
        one_word = strtok(NULL, separator);
    }

    printf("%d words\n", word_count);
    printf("----\n");

    for (int i = 0; i < word_count; i++)
    {
        for (int j = 0; all_words[i][j]; j++)
        {
            all_words[i][j] = tolower(all_words[i][j]);
        }

        printf("%s : %zu\n", all_words[i], strlen(all_words[i]));
    }

    return 0;
}
