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
    if (head == NULL)   // 检查分配是否失败
    {
        printf("内存分配失败\n");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    return head;    
}

Node *get_tail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
//尾插法
Node *insertTail(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)   // 检查分配是否失败
    {
        printf("内存分配失败\n");
        return NULL;
    }
    p->data = e;
    p->next = NULL;
    Node *tail = get_tail(L);
    tail->next = p;             // 尾节点接上新节点
    return p;
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

// 释放整个链表（含头节点）
void freeList(Node *L)
{
    Node *p = L;
    while (p != NULL)
    {
        Node *next = p->next;   // 先记下下一个节点
        free(p);                // 释放当前节点
        p = next;               // 移到下一个
    }
}

int main(void)
{
    system("chcp 65001 >nul");
    Node *L = initList();   
    Node *tail = get_tail(L);   // 获取尾节点
    if (L == NULL)   // 检查初始化是否失败
        return 1;
    printf("初始化成功\n");
    insertTail(L, 10);
    insertTail(L, 20);
    insertTail(L, 30);
    listNode(L);
    freeList(L);   // 释放链表，防止内存泄漏
    return 0;
}