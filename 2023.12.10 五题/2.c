#include <stdio.h>
#include <math.h>

int main()
{
   //����4��4�е�����,ת�ú����
   int a[4][4],b[4][4],i,j;
   printf("������4��4�е�����:\n");
   //����
   for(i=0;i<4;i++)
      for(j=0;j<4;j++)
         scanf("%d",&a[i][j]);
   printf("ת�ú������:\n");
   //ת��
   for(i=0;i<4;i++)
      for(j=0;j<4;j++)
         b[j][i]=a[i][j];
   //���
   for(i=0;i<4;i++)
   {
      for(j=0;j<4;j++)
         printf("%d ",b[i][j]);
      printf("\n");
   }
   return 0;
}
