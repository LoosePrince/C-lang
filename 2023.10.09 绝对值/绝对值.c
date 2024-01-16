#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,x;
    printf("输入两个数以计算绝对值：");
    scanf("%d%d",&m,&n);
    x=m-n;
    if (x<0)
    {
        printf("相差:%d",-x);
    }
    else
    {
        printf("相差:%d",x);
    }

    return 0;
}
