#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
typedef struct DataNode {
    int data;
    struct DataNode* next;
} DataNode;
  
typedef struct Linklist {
    int count;
    DataNode* head;
} Linklist;
  
DataNode* getNode(int data) {
    DataNode* new = (DataNode*) malloc (sizeof(DataNode));
    new->data = data;
    new->next = NULL;
    return new;
}
  
Linklist* create() {
    Linklist* list = (Linklist*) malloc (sizeof(Linklist));
    list->count = 0;
    list->head = NULL;
    return list;
}
  
void insert_last(Linklist* list,int data) {
    DataNode* new = getNode(data);
    if (list->count == 0) {
        list->head = new;
    }
    else {
        DataNode* ptr = list->head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    list->count++;
}
  
void pop_last(Linklist* list) {
    if (list->count == 0) {
        return;
    }
    DataNode* ptr = list->head;
    DataNode* prev = NULL;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
  
    if (prev == NULL) {
        list->head = NULL;
    } else {
        prev->next = NULL;
    }
      
    printf("%d",ptr->data);
    if (list->head != NULL) {
        printf(" -> ");
    }
    free(ptr);
    list->count--;
}
  
void pop_first(Linklist* list) {
    if (list->count == 0) {
        return;
    }
    DataNode* ptr = list->head;
    if (list->count == 1) {
        list->head = NULL;
    } else {
        list->head = ptr->next;
    }
    printf("%d",ptr->data);
    if (list->head != NULL) {
        printf(" -> ");
    }
    free(ptr);
    list->count--;
}
  
int main() {
    int num,input;
    scanf("%d",&num);
    Linklist* list = create();
    for (int i = 0; i < num; i++) {
        scanf(" %d",&input);
        insert_last(list,input);
    }
  
    pop_last(list);
    while (list->count != 0){
        pop_first(list);
        pop_first(list);
        pop_last(list);
        pop_last(list);
    }
  
    return 0;
}
