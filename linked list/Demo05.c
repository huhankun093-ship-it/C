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
    Node *head = (Node *)malloc(sizeof(Node));////这一行是动态创建一个链表节点（头节点），并让 head 指针指向它。
    if (head == NULL)   // 检查分配是否失败
    {
        printf("内存分配失败\n");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    return head; //交出去地址   
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
    Node *q = p->next;//声明一个 Node 指针 q，把 p->next（p 的下一个节点）赋给 q。
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

// 查找倒数第 k 个节点（快慢指针法）
int findNodeFS(Node *L, int k)
{
    Node *fast = L->next; // 快指针
    Node *slow = L->next; // 慢指针

    if (k <= 0)   // 参数检查：k 必须为正数
    {
        printf("k 必须为正数\n");
        return 0;
    }

    // fast 先走 k 步
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL)   // k 超过链表长度，防止越界
        {
            printf("k 超过链表长度\n");
            return 0;
        }
        fast = fast->next;
    }

    // fast 和 slow 一起走，fast 到末尾(NULL)时 slow 就是倒数第 k 个
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("链表中倒数第 %d 个节点的值为: %d\n", k, slow->data);
    return 1;
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
    insertNode(list, 40, 3);
    insertNode(list, 50, 4);
    listNode(list);
    findNodeFS(list, 2); // 查找链表中倒数第2个节点的值

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
