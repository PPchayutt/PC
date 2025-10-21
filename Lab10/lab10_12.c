#include <stdio.h>
#include <string.h>

struct Book
{
    char id[13];
    char name[100];
    char author[100];
};

int main()
{
    int num_books;
    scanf("%d", &num_books);

    char search_id[13];
    scanf(" %s", search_id);

    struct Book bookshelf[num_books];

    for (int i = 0; i < num_books; i++)
    {
        scanf(" %s %s %s",
              bookshelf[i].id,
              bookshelf[i].name,
              bookshelf[i].author);
    }

    for (int i = 0; i < num_books; i++)
    {

        if (strcmp(bookshelf[i].id, search_id) == 0)
        {

            printf("%s %s %s",
                   bookshelf[i].id,
                   bookshelf[i].name,
                   bookshelf[i].author);

            return 0;
        }
    }

    printf("Not Found");

    return 0;
}