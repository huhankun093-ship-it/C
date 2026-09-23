#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SeqList;

// 初始化：把顺序表设为空表
void InitList(SeqList *L)
{
    L->length = 0;
}

// 追加：在末尾添加一个元素
int appendElem(SeqList *L, ElemType e)
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满，无法添加元素\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

// 遍历：打印所有元素
void listElem(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 插入：在下标 pos 处插入元素 e
int insertElem(SeqList *L, int pos, ElemType e)
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满，无法插入元素\n");
        return 0;
    }
    if (pos < 0 || pos > L->length)
    {
        printf("插入位置不合法\n");
        return 0;
    }

    for (int i = L->length; i > pos; i--)
    {
        L->data[i] = L->data[i - 1];
    }
    L->data[pos] = e;
    L->length++;
    return 1;
}

// 删除：删除下标 pos 处的元素，用 e 返回被删的值
int deleteElem(SeqList *L, int pos, ElemType *e)
{
    if (L->length == 0)
    {
        printf("顺序表为空，无法删除元素\n");
        return 0;
    }
    if (pos < 0 || pos >= L->length)
    {
        printf("删除位置不合法\n");
        return 0;
    }

    *e = L->data[pos];
    for (int i = pos; i < L->length - 1; i++)
    {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return 1;
}

// 查找：返回元素 e 的位置（从 1 开始），找不到返回 -1
int findElem(SeqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return -1;
}

SeqList* initList()
{
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    if (L == NULL)//NULL 的意思是指针不指向任何有效的内存地址，表示内存分配失败
    {
        printf("内存分配失败\n");
        exit(1);
    }
    L->length = 0;
    return L;
}

int main(void)
{
    system("chcp 65001 >nul");
    SeqList *L = initList();
    printf("初始化成功，目前长度占用%d\n", L->length);
    printf("目前占用内存%zu字节\n", sizeof(L->data));

    appendElem(L, 10);
    appendElem(L, 20);
    listElem(L);

    insertElem(L, 1, 15);
    listElem(L);

    ElemType deletedElem;
    deleteElem(L, 1, &deletedElem);
    printf("删除的元素是: %d\n", deletedElem);
    listElem(L);

    printf("查找元素20的位置: %d\n", findElem(L, 20));
    free(L);   // 释放动态分配的内存
    return 0;
}
