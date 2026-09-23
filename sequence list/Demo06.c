#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;
} po;

int main(int argc, char *argv[])
{
    po *p;
    p = (po*)malloc(sizeof(po)); // 动态分配内存
    p->x = 10; // 给动态分配的内存赋值
    p->y = 20;
    printf("动态分配的内存中的值: p->x = %d, p->y = %d\n", p->x, p->y);
    free(p); // 释放动态分配的内存
    return 0;
}
