#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// "${default}"

int maxsum(int *p) // ����ָ��
{
   int sum = *p; // ָ��ָ���Ԫ��
   for (int i = 0; i < 6; i++)
   {
      if (*(p + i) > sum) // �Ƚ�ָ��ָ���Ԫ�غ�sum
      {
         sum = *(p + i); // ָ��ָ���Ԫ�ظ�ֵ��sum
      }
   }
   // printf("%d", sum);
   return sum; // ����sum
}

int main()
{
   int a[6] = {0};
   int *p = a;
   printf("������6������\n");
   for (int i = 0; i < 6; i++)
   {
      scanf("%d", p + i);
   }
   printf("�������%d",maxsum(p));
   return 0;
}
