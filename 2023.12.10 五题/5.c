#include <stdio.h>
#include <math.h>

int main()
{
   //输入8个整数,统计每个数出现的次数
   int a[8],b[8]={0};
   int num,count,i,j;
   for (int i = 0; i < 8; i++)
      scanf("%d", &a[i]);

   for (i = 1, b[0] = a[0], num = 1; i < 8; i++)
   {
      for (j = 0; j < num; j++)
         if (b[j] == a[i])
            break;
      if (j == num)
      {
         b[num] = a[i];
         num++;
      }
   }
   
   for (i = 0; i < num; i++)
   {
      for (j = 0, count = 0; j < 8; j++)
         if (b[i] == a[j])
            count++;
      printf("%d:%d\n", b[i], count);
   }
   return 0;
}
