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
    Node *head = (Node *)malloc(sizeof(Node));//这一行是动态创建一个链表节点（头节点），并让 head 指针指向它。
    if (head == NULL)   // 检查分配是否失败
    {
        printf("内存分配失败\n");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    return head;    
}

int insertNode(Node *L, ElemType e, int pos)
{
    Node *p = L;//让指针从头节点出发
    int i = 0;
    while (p != NULL && i < pos)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
    {
        printf("插入位置错误\n");
        return 0;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    if (q == NULL)   // 检查分配是否失败
    {
        printf("内存分配失败\n");
        return 0;
    }
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}
