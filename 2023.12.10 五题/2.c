#include <stdio.h>
#include <math.h>

int main()
{
   //输入4行4列的数组,转置后输出
   int a[4][4],b[4][4],i,j;
   printf("请输入4行4列的数组:\n");
   //输入
   for(i=0;i<4;i++)
      for(j=0;j<4;j++)
         scanf("%d",&a[i][j]);
   printf("转置后的数组:\n");
   //转置
   for(i=0;i<4;i++)
      for(j=0;j<4;j++)
         b[j][i]=a[i][j];
   //输出
   for(i=0;i<4;i++)
   {
      for(j=0;j<4;j++)
         printf("%d ",b[i][j]);
      printf("\n");
   }
   return 0;
}
