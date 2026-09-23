#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

void InitList(SeqList *K)
{
    K->length = 0; // Initialize the length of the sequential list to 0
}

int main(int argc, char *argv[])
{
    system("chcp 65001 >nul");
    SeqList L;
    InitList(&L); // Initialize the sequential list
    printf("初始化成功，目前长度占用%d\n", L.length); // Print the current length of the sequential list
    printf("目前占用内存%zu字节\n", sizeof(L.data));

    return 0;
}

int appendElem(SeqList *L,ElemType e)
{
    if(L->length >= MAXSIZE)
    {
        printf("顺序表已满，无法添加元素\n");
        return 0;
    }
    L->data[L->length] = e; // Add the new element to the end of the list
    L->length++; // Increment the length of the list
    return 1; // Return success
}
//遍历
void listElem(SeqList *L)
{
    for(int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]); // Print each element in the list
    }
    printf("\n"); // Print a newline after printing all elements
}
