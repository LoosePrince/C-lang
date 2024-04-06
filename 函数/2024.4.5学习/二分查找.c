#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_search(int *arr, int left, int right, int key)
{
    int mid = (left + right) / 2;
    if (left <= right)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binary_search(arr, left, mid - 1, key); // 递归左半部分
        }
        else if (arr[mid] < key)
        {
            return binary_search(arr, mid + 1, right, key); // 递归右半部分
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 0;
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]);
    printf("请输入要查找的数字\n");
    scanf("%d", &key);
    int pos = binary_search(arr, left, right, key);
    if (pos == -1)
    {
        printf("未找到\n");
    }
    else
    {
        printf("找到，位置为arr[%d] 内存地址:%p\n", pos, &arr[pos]);
    }
    system("pause");
    return 0;
}
