#include <stdio.h>
#include <malloc.h>

int main(int argc, char *argv[])
{
    char *a = NULL;
    a = (char *)malloc(10 * sizeof(char));//(char *)强制类型转化  // 10 * sizeof(char)申请10倍sizeof(char)的空间
    if(a == NULL)
    {
        return 0;
    }

    free(a);//释放a指向的动态内存

    return 0;
}