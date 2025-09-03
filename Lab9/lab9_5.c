#include<stdio.h>
#include<stdlib.h>

int main() {
    char *text = (char*) malloc(101*sizeof(char));
    scanf("%[^\n]", text);
    char *end = text;

    while (*end != '\0')
        end++;

    end--;

    while (end >= text)
        printf("%c", *end--);

    free(text);

    return 0;
}
