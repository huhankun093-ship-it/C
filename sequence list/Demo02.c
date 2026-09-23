#include <stdio.h>
#include <stdlib.h>

/*int main(int argc, char *argv[])
{
    system("chcp 65001 >nul");   // 把控制台切换到 UTF-8，解决中文乱码
    // argc = 命令行参数的个数（含程序名本身）
    printf("参数个数 argc = %d\n", argc);

    // 遍历打印每一个参数
    for (int i = 0; i < argc; i++) 
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // 演示：把字符串参数转成整数（atoi）
    if (argc > 2) 
    {
        int n = atoi(argv[2]);       // 把第 2 个参数当数字解析
        printf("第2个参数作为数字 = %d\n", n);
    }

    return 0;
}
    */
int main(int argc, char *argv[])
{
    int a[] = {1,2,3,4,5};
    for (int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
   {
       printf("%d\n",a[i]);
   }
}


