#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Book
{
    int isbn;
    char bookName[50];
    double price;
};

int main(int argc, char *argv[])
{
    system("chcp 65001 >nul");   // 切换控制台到 UTF-8，解决中文乱码
    struct Book b;
    b.isbn = 123456;
    strcpy(b.bookName, "C语言程序设计");
    b.price = 59.8;
    printf("isbn: %d\n", b.isbn);
    printf("bookName: %s\n", b.bookName);
    printf("price: %.2f\n", b.price);
    return 0;
}



