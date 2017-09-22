#include <stdio.h>
#include <malloc.h>

typedef int DataType ;
typedef struct Node{
    struct Node *next ;
    DataType data ;
}SLNode;

void ListInitiate(SLNode **head){
    *head = (SLNode *)malloc(sizeof(SLNode)) ;
    (*head)->next = NULL ;
}

int ListLength(SLNode *head){
    SLNode *p = head ;
    int size = 0 ;
    while (p != NULL){
        p = p->next ;
        size ++ ;
    }
    return size ;
}

int ListInsert(SLNode *head, int i, DataType s){
    SLNode *p, *q ;
    int j = -1 ;

    p = head ;
    while(p->next != NULL && j < i - 1){
        p = p->next ;
        j ++ ;
    }

    //,,,,,,,,
    p = p->next ;
    q = (SLNode *)malloc(sizeof(SLNode)) ;
    q->next = p->next ;
    p->next = q ;
    q->data = s ;

    return 1 ;
}




int main(void) {

    printf("Hello, World!123\n");

    return 0;
}