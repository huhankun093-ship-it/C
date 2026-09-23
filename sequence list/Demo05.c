#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *p;
    p = (int *)malloc(sizeof(int)); // 动态分配内存
    *p = 10; // 给动态分配的内存赋值
    printf("动态分配的内存中的值: %d\n", *p);
    free(p); // 释放动态分配的内存
    return 0;
}









