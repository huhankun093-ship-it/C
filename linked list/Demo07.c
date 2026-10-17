#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// ==================== 链表部分 ====================
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    return head;
}

// 获取链表尾节点
Node *getTail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
        p = p->next;
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

// ==================== 哈希表部分 ====================
// 桶的数量：取一个质数，能让 key 分散得更均匀、减少冲突
#define TABLE_SIZE 101

// 哈希桶节点（链地址法：每个桶本身是一条小链表）
typedef struct HashNode
{
    int key;                 // 存放"绝对值"
    struct HashNode *next;
} HashNode;

// 哈希表：一个桶数组
typedef struct HashTable
{
    HashNode *buckets[TABLE_SIZE];//buckets是一个有 101 个格子的数组,每个格子里放一个门牌号
} HashTable;

// 哈希函数：key 对桶数取模，把任意大小的 key 映射到 0 ~ TABLE_SIZE-1
int hashFunc(int key)
{
    return key % TABLE_SIZE;
}

// 初始化哈希表：所有桶置空
void hashInit(HashTable *ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
        ht->buckets[i] = NULL;
}

// 把 key 插入哈希表；返回 1 表示 key 已存在，返回 0 表示新插入
int hashInsert(HashTable *ht, int key)
{
    int idx = hashFunc(key);
    HashNode *cur = ht->buckets[idx];
    while (cur != NULL)              // 沿着桶里的链表找
    {
        if (cur->key == key)
        {
            return 1;   
        }             // 已经存在
        cur = cur->next;
    }
    // 没找到，头插进桶里
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    if (node == NULL)
    {
        printf("内存分配失败\n");
        return 1;                    // 分配失败，按"已存在"处理，避免继续出错
    }
    node->key = key;
    node->next = ht->buckets[idx];
    ht->buckets[idx] = node;
    return 0;                        // 新插入
}

// 释放哈希表的所有节点
void hashFree(HashTable *ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashNode *cur = ht->buckets[i];
        while (cur != NULL)
        {
            HashNode *next = cur->next;
            free(cur);
            cur = next;
        }
    }
}

// ==================== 用哈希表删除绝对值重复的节点 ====================
// 相比 Demo06 的固定数组，这里不再需要传 n，任意大小的绝对值都能处理
void deleteNodeAbs(Node *L)
{
    HashTable ht;
    hashInit(&ht);

    Node *p = L;
    while (p->next != NULL)
    {
        int key = abs(p->next->data);       // 取绝对值作为 key
        if (hashInsert(&ht, key) == 0)      // 第一次出现，保留
        {
            p = p->next;
        }
        else                                 // 已存在，删除
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    hashFree(&ht);
}

// ==================== 主函数 ====================
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
    deleteNodeAbs(List);
    listNode(List);

    // 释放整个链表，防止内存泄漏
    Node *cur = List;
    while (cur != NULL)
    {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    return 0;
}
