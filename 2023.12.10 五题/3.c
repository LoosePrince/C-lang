#include <stdio.h>
#include <math.h>

int main()
{
   // 输入行数,输出指定行数的杨辉三角
   int n;
   printf("请输入行数:");
   scanf("%d", &n);
   int arr[n][n];
   for (int i = 0; i < n; i++) //i是列
   {
      for (int j = 0; j <= i; j++) //j是行
      {
         if (j == 0 || j == i)
         {
            arr[i][j] = 1;
         }
         else
         {
            //左上角和对角之和
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]; 
         }
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }
   return 0;
}
