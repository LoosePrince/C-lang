#include <stdio.h>
#include <math.h>


int main()
{
    int x;
    char txt;
    scanf("%d", &x);
    scanf(" %c", &txt);
    for (int i = 1; i < x * 2; i++) // 假设x=5,第一遍x*2=10
    {
        if (i <= x)
        {
            // 空格循环，第一遍x-i=4
            for (int a = 0; a < x - i; a++)
            {
                printf("  "); // 空格
            }
            // 字符循环，第一遍i=1
            for (int a = 0; a < i; a++)
            {
                // 字符
                printf(" %c", txt);
            }
        }
        else if (i > x)
        {
            // 空格循环，第一遍i=6，i-x=1
            for (int a = 0; a < i - x; a++)
            {
                // 空格
                printf("  ");
            }
            // 字符循环，第一遍x*2-i=4
            for (int a = 0; a < x * 2 - i; a++)
            {
                // 字符
                printf(" %c", txt);
            }
        }
        printf("\n");
    }
    return 0;
}
