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

//删除绝对值相同的的节点
void deleteNodeAbs(Node *L,int n)
{
    Node *p = L;
    int index = 0;
    int *q = (int *)malloc(sizeof(int) * (n + 1)); //int *q 不是指针，是一个整形数组的首地址
    for (int i = 0; i <= n; i++)
    {
       *(q + i) = 0;//*(q + i) = q[i] = 0;  //初始化数组
    }
    while (p->next != NULL)
    {
        index = abs(p->next->data);
        if (*(q + index) == 0)
        {
            *(q + index) = 1;
            p = p->next;
        }
        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}

// 获取链表尾节点
Node *getTail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

// 在尾节点后插入新节点，返回新尾节点
Node *insertTail(Node *tail, ElemType e)
{
    Node *q = (Node *)malloc(sizeof(Node));
    if (q == NULL)
    {
        printf("内存分配失败\n");
        return tail;
    }
    q->data = e;
    q->next = NULL;
    tail->next = q;
    return q;
}

int main(int argc, char const *argv[])
{
    system("chcp 65001 >nul");
    Node *List = initList();
    Node *tail = getTail(List);

    tail = insertTail(tail, 21);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, 15);
    tail = insertTail(tail, 8);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, -7);
    listNode(List);
    deleteNodeAbs(List, 21);//21是链表中绝对值最大的数
    listNode(List);
    return 0;
}
