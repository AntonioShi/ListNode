#include <stdio.h>
#include <malloc.h>

/**六大操作步骤
 * 初始化
 * 取值
 * 长度
 * 插入
 * 删除
 * 撤销
 */

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

    if(j != i - 1){

        printf("参数错误\n") ;
    }

    //连接
    q = (SLNode *)malloc(sizeof(SLNode)) ;
    q->next = p->next ;

    p->next = q ;
    q->data = s ;

    return 1 ;
}

int ListDelete(SLNode *head, int i, DataType *s){
    SLNode *p, *q ;
    int j = -1 ;

    p = head ;
    while(p != NULL && j < i - 1){
        p = p->next ;
        j ++ ;
    }

    if(j != i - 1){

        printf("参数错误\n") ;
    }

    q = p->next ;
    *s = p->data ;
    p->next = p->next->next ;
    free(q) ;

    return 1 ;
}

int ListGet(SLNode *head, int i, DataType *s){
    SLNode *p ;
    int j = -1;

    p = head ;
    while(p != NULL && j < i - 1){
        p = p ->next ;
        j ++ ;
    }

    if(j != i - 1){

        printf("参数错误\n") ;
    }

    *s = p->data ;

    return 1 ;

}

void Destroy(SLNode **head){
    SLNode *p,*q ;
    p = (*head) ;
    while(p != NULL){
        q = p ;
        p = p->next ;
        free(q) ;
    }

    *head = NULL  ;//头指针 = 空
    return ;
}

int main(void) {

    printf("Hello, World!123\n");

    SLNode *head ;
    ListInitiate(&head) ;

    int i, s ;
    for (i = 0; i < 10; ++i) {
        ListInsert(head, i, (i + 1)) ;

    }

    //ListDelete(head, 4, &s) ;

    int n = ListLength(head) ;
    printf("n = %4d\n", n) ;
    for (i = 0; ListLength(head) > i; ++i) {
        ListGet(head, i, &s) ;
        printf("%d ", s) ;
    }
    printf("\n") ;
    ListDelete(head, 4, &s) ;

    n = ListLength(head) ;
    printf("n = %4d\n", n) ;

    for (i = 0; ListLength(head) > i; ++i) {
        ListGet(head, i, &s) ;
        printf("%d ", s) ;
    }
    printf("\n") ;

    Destroy(&head) ;

    return 0;
}
