#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    //��д������һ�� 1 �� 100 ���м��� 9 
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
    printf("1 �� 100 ���� %d �� 9.\n", count);
    system("pause");
    return 0;
}
