#include <stdio.h>
#include <string.h>

int main()
{
    char full_name[201];
    scanf(" %[^\n]", full_name);
    int name_length = strlen(full_name);

    for (int i = 1; i < name_length; i++)
    {
        if (full_name[i] == ' ')
        {
            printf("%c.", full_name[0]);
            printf("%c.", full_name[i + 1]);
            break;
        }
    }

    return 0;
}
