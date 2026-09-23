#include <stdio.h>
#include "main.h"

void hello(void)
{
    printf("Hello, kk!\n");
}

int main()
{
    hello();
    arr();
    printf("Hello, World!\n");
    
    const int a = 10; //const means can not be modified
    int b = 20;
    int c = a + b;
    printf("c = %d\n", c);

    enum Color { RED, GREEN, BLUE };
    enum Color color;
    color = RED;
    printf("color = %d\n", color);
    color = GREEN;
    printf("color = %d\n", color);
    color = BLUE;
    printf("color = %d\n", color);
    char str[] = "Hello, World!";
    printf("str = %s\n", str); //%s is a placeholder for a string. 

    char arr1 [] = "abcdef";
    char arr2 [] = {'a','b','c','d','e','f','\0'};//You need to actively add /0 to make it stop.
    //char arr2 [] = "abcdef";                    //Otherwise, he will not stop reading and will read the next character in memory until he finds /0.
    printf("arr1 = %s\n", arr1);
    printf("arr2 = %s\n", arr2);

    return 0;
}

void arr(void) 
{
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}




