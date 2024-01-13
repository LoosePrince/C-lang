#include <stdio.h>
#include <math.h>

int main()
{
   // 输入十个整数,输出两数之差
   int a[10], b[9];
   for (int i = 0; i < 10; i++)
      scanf("%d", &a[i]);
   for (int i = 0; i < 9; i++)
   {
      b[i] = a[i] - a[i + 1];
      printf("%d ", b[i]);
   }
   return 0;
}