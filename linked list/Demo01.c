#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
   ElemType data;
   struct node *next;//"next 是一个指针，指向下一个 struct node 类型的节点。"
} Node;

Node *initList()//这个 * 表示：initList 函数返回的是一个指针（指向 Node 的指针）。
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;    
}

int insertHead(Node *L, ElemType e)//准确说：Node *L 是指向"头节点"的指针，不是链表本身。 但因为有了它就能访问整条链，所以习惯上常把它当"链表"来叫
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;//复制头节点的 next 指针到新节点的 next 指针上
    L->next = p;// 让头节点指向新节点，把它接到链表最前面
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
