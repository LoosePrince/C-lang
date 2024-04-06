#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    //编写程序数一下 1 到 100 中有几个 9 
    int count = 0; 
    for (int i = 1; i <= 100; i++)
    {
        if (i % 10 == 9)
        {
            count++;
            printf("%d:%d ",count , i);
        }
        if (i / 10 == 9) 
        {
            count++;
            printf("%d:%d ",count, i);
        }
    }
    printf("\n");
    printf("1 到 100 中有 %d 个 9.\n", count);
    system("pause");
    return 0;
}
