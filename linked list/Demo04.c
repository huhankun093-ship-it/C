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

int insertNode(Node *L, ElemType e, int pos)
{
    Node *p = L;
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
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

int deleteNode(Node *L, int pos)
{
    Node *p = L;
    int i = 0;
    while (p->next != NULL && i < pos)
    {
        p = p->next;
        i++;
    }
    if (p->next == NULL)
    {
        printf("删除位置错误\n");
        return 0;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

// 遍历打印链表
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
    Node *list = initList();
    if (list == NULL)   // 检查初始化是否失败
        return 1;

    insertNode(list, 10, 0); // 在位置0插入10
    insertNode(list, 20, 1);
    insertNode(list, 30, 2);
    printf("删除前: ");
    listNode(list);

    deleteNode(list, 1); // 删除位置1的节点（即20）
    printf("删除后: ");
    listNode(list);

    // 释放整个链表，防止内存泄漏
    Node *p = list;
    while (p != NULL)
    {
        Node *next = p->next;
        free(p);
        p = next;
    }
    return 0;
}
