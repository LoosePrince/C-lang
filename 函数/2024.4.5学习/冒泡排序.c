#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++) // 第i趟冒泡排序
    {
        for (int j = 0; j < len - i - 1; j++) // 比较arr[j]和arr[j+1]的值
        {
            if (arr[j] > arr[j + 1]) // 交换arr[j]和arr[j+1]
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[10] = {9, 5, 2, 3, 6, 8, 7, 1, 4, 0};
    sort(arr, 10);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
