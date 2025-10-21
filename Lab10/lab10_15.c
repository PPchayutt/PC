#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode
{
    char *data;
    struct DataNode *next;
} DataNode;

typedef struct SinglyLinkedList
{
    unsigned int count;
    DataNode *head;
} SinglyLinkedList;

DataNode *createDataNode(char *data_input)
{
    DataNode *new_node = (DataNode *)malloc(sizeof(DataNode));
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->data = (char *)malloc(strlen(data_input) + 1);
    if (new_node->data == NULL)
    {
        free(new_node);
        return NULL;
    }
    strcpy(new_node->data, data_input);
    new_node->next = NULL;
    return new_node;
}

SinglyLinkedList *createSinglyLinkedList()
{
    SinglyLinkedList *new_list = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    if (new_list == NULL)
    {
        return NULL;
    }
    new_list->count = 0;
    new_list->head = NULL;
    return new_list;
}

void traverse(SinglyLinkedList *list)
{
    if (list->count == 0 || list->head == NULL)
    {
        printf("This is an empty list.\n");
        return;
    }
    DataNode *current_node = list->head;
    while (current_node != NULL)
    {
        printf("%s", current_node->data);
        if (current_node->next != NULL)
        {
            printf(" -> ");
        }
        current_node = current_node->next;
    }
    printf("\n");
}

void insert_last(SinglyLinkedList *list, char *data)
{
    DataNode *new_node = createDataNode(data);
    if (new_node == NULL)
    {
        return;
    }
    if (list->count == 0 || list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        DataNode *current_node = list->head;
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    list->count++;
}

void insert_front(SinglyLinkedList *list, char *data)
{
    DataNode *new_node = createDataNode(data);
    if (new_node == NULL)
    {
        return;
    }
    new_node->next = list->head;
    list->head = new_node;
    list->count++;
}

int main()
{
    SinglyLinkedList *mylist = createSinglyLinkedList();
    if (mylist == NULL)
    {
        return 1;
    }
    int num_command;
    char command_char;
    char command_data[101];
    scanf("%d", &num_command);

    for (int i = 0; i < num_command; i++)
    {
        if (scanf(" %c: %[^\n]s", &command_char, command_data) == 2)
        {

            if (command_char == 'F')
            {
                insert_front(mylist, command_data);
            }
            else if (command_char == 'L')
            {
                insert_last(mylist, command_data);
            }
            else
            {
                printf("Invalid Condition: %c\n", command_char);
            }
        }
        else
        {
            printf("Warning: Skipping invalid input line %d\n", i + 1);
        }
    }

    traverse(mylist);
    DataNode *current_node = mylist->head;
    DataNode *temp_node;
    while (current_node != NULL)
    {
        free(current_node->data);
        temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    free(mylist);

    return 0;
}
