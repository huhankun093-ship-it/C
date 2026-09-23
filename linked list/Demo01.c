#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
   ElemType data;
   struct node *next;
} Node;

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;    
}

int insertHead(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

void listNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    system("chcp 65001 >nul");
    Node *L = initList();
    printf("初始化成功\n");
    insertHead(L, 10);
    insertHead(L, 20);
    insertHead(L, 30);
    listNode(L);
    return 0;
}