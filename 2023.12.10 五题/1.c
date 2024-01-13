#include <stdio.h>
#include <math.h>

int main()
{
   //四名同学,三科成绩
   int a[4] = {0};
   int temp;
   //输入数据
   for(int i=0; i<4; i++)
   {
      for(int j=0; j<3; j++)
      {
         //直接记录总分
         scanf("%d", &temp);
         a[i] = a[i] + temp;
      }
   }
   //寻找最高分
   int max = a[0];
   for(int i=0; i<4; i++)
   {
      if(a[i] > max)
      {
         max = a[i];
      }
   }
   printf("%d分 为最高分数\n", max);
   //寻找与最高分相同分数
   int same = 0;
   for(int i=0; i<4; i++)
   {
      if(a[i] == max)
      {
         printf("%d同学 ", i + 1);
         same++;
      }
   }
   if (same > 1)
   {
      printf("成绩并列第一\n");
   }
   else
   {
      printf("成绩第一\n");
   }
   return 0;
}



//原本的写法
void a()
{
   //四名同学,三科成绩
   int a[4][3];
   //输入数据
   for(int i=0; i<4; i++)
   {
      for(int j=0; j<3; j++)
      {
         //逐个输入
         scanf("%d", &a[i][j]);
      }
   }
   //逐个记录总分
   int sum1 = a[0][0] + a[0][1] + a[0][2];
   int sum2 = a[1][0] + a[1][1] + a[1][2];
   int sum3 = a[2][0] + a[2][1] + a[2][2];
   int sum4 = a[3][0] + a[3][1] + a[3][2];
   //对比分数大小
   int s = 0;
   if(sum1 >= sum2 && sum1 >= sum3 && sum1 >= sum4)
   {
      printf("1 ");
      s++;
   }
   if (sum2 >= sum3 && sum2 >= sum4 && sum2 >= sum1)
   {
      printf("2 ");
      s++;
   }
   if (sum3 >= sum4 && sum3 >= sum1 && sum3 >= sum2)
   {
      printf("3 ");
      s++;
   }
   if (sum4 >= sum1 && sum4 >= sum2 && sum4 >= sum3)
   {
      printf("4 ");
      s++;
   }
   if (s > 1)
   {
      printf("成绩并列第一\n");
   }
   else
   {
      printf("成绩第一\n");
   }
}
