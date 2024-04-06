#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add(int *a, int *b, int *c) // 定义函数,传入指针
{
    for (int i = 0; i < 6; i++)
    {
        *(c + i) = *(a + i) + *(b + i); // 指针指向的元素相加
        // c[i] 等于 a[i] 加 b[i]
    }
}

int main()
{
    int a[6] = {1,2,3,4,5,6};
    int b[6] = {7,8,9,10,11,12};
    int c[6] = {0};
    int *x = a,*y = b,*z = c; //定义指针并传入
    // int *x = &a[0],*y = &b[0],*z = &c[0];
    // 指针指向数组的第一个元素对应的地址
    add(x, y, z); //调用函数，传入指针
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", c[i]);
    }
   return 0;
}
