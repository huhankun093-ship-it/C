#include <stdio.h>

struct point 
{
    int x;
    int y;
};

int main(int argc, char *argv[])
{
   struct point p;
   p.x = 5;
   p.y = 10;
   
   struct point *pp = &p; // 指针指向结构体变量 p
   (*pp).x = 10;
   (*pp).y = 5;
   printf("p.x = %d, p.y = %d\n", p.x, p.y); // 直接访问结构体成员
   printf("p.x = %d, p.y = %d\n", pp->x, pp->y); // 使用指针访问结构体成员
}







