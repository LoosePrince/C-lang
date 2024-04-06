#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// "${default}"

int maxsum(int *p) // 传入指针
{
   int sum = *p; // 指针指向的元素
   for (int i = 0; i < 6; i++)
   {
      if (*(p + i) > sum) // 比较指针指向的元素和sum
      {
         sum = *(p + i); // 指针指向的元素赋值给sum
      }
   }
   // printf("%d", sum);
   return sum; // 返回sum
}

int main()
{
   int a[6] = {0};
   int *p = a;
   printf("请输入6个整数\n");
   for (int i = 0; i < 6; i++)
   {
      scanf("%d", p + i);
   }
   printf("最大数：%d",maxsum(p));
   return 0;
}
