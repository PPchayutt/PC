#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char sentence[2001];
    char *target_word = "cat";

    scanf(" %[^\n]", sentence);

    int length = strlen(sentence);
    for (int i = 0; i < length; i++)
    {
        sentence[i] = tolower(sentence[i]);
    }

    char *current_search_pos = sentence;
    int is_first_match = 1;

    while (1)
    {
        char *found_location = strstr(current_search_pos, target_word);

        if (found_location == NULL)
        {
            break;
        }

        int position_0_based = (found_location - sentence);

        if (is_first_match == 1)
        {
            is_first_match = 0;
        }
        else
        {
            printf(", ");
        }

        printf("%d", position_0_based);

        current_search_pos = found_location + 1;
    }

    printf("\n");

    return 0;
}
