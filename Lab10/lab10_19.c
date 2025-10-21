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

DataNode *createDataNode(char *data_input);
SinglyLinkedList *createSinglyLinkedList();
void insert_last(SinglyLinkedList *list, char *data);
DataNode *getNodeAtIndex(SinglyLinkedList *list, int index);
void freeList(SinglyLinkedList *list);

int main()
{
    SinglyLinkedList *mylist = createSinglyLinkedList();
    if (mylist == NULL)
    {
        return 1;
    }

    char *input_buffer = (char *)malloc(21 * sizeof(char));
    if (input_buffer == NULL)
    {
        printf("Memory allocation failed for input buffer!\n");
        freeList(mylist);
        return 1;
    }

    while (1)
    {
        if (scanf("%20s", input_buffer) != 1)
        {
            break;
        }
        if (strcmp(input_buffer, "Last") == 0)
        {
            break;
        }
        insert_last(mylist, input_buffer);
    }

    free(input_buffer);

    int target_index;
    getchar();
    if (scanf("%d", &target_index) != 1)
    {
        printf("Error\n");
        freeList(mylist);
        return 1;
    }

    DataNode *found_node = getNodeAtIndex(mylist, target_index);

    if (found_node == NULL)
    {
        printf("Error\n");
    }
    else
    {
        printf("%s\n", found_node->data);
    }

    freeList(mylist);

    return 0;
}

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

void insert_last(SinglyLinkedList *list, char *data)
{
    DataNode *new_node = createDataNode(data);
    if (new_node == NULL)
    {
        return;
    }
    if (list->head == NULL)
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

DataNode *getNodeAtIndex(SinglyLinkedList *list, int index)
{
    if (list->head == NULL || list->count == 0)
    {
        return NULL;
    }
    int positive_index;
    if (index >= 0)
    {
        if (index >= list->count)
        {
            return NULL;
        }
        positive_index = index;
    }
    else
    {
        if (index < -(int)list->count)
        {
            return NULL;
        }
        positive_index = list->count + index;
    }
    DataNode *current_node = list->head;
    for (int i = 0; i < positive_index; i++)
    {
        if (current_node == NULL)
            return NULL;
        current_node = current_node->next;
    }
    return current_node;
}

void freeList(SinglyLinkedList *list)
{
    DataNode *current_node = list->head;
    DataNode *temp_node;
    while (current_node != NULL)
    {
        free(current_node->data);
        temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    free(list);
}
