#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode
{
    char *data;
    struct DataNode *next;
} DataNode;

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

int main()
{
    char input_data[101];
    scanf(" %[^\n]", input_data);
    DataNode *pNew = createDataNode(input_data);
    if (pNew != NULL)
    {
        printf("%s\n", pNew->data);
        printf("%p\n", (void *)pNew->next);

        free(pNew->data);
        free(pNew);
    }

    return 0;
}
