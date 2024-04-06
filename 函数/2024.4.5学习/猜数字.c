#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

void guessTheNumber(int number)
{
    int guess;
    printf("猜数字游戏开始!\n");
    while (1)
    {
        printf("请输入你的猜测:");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("猜大了!\n"); 
        }
        else if (guess < number)
        {
            printf("猜小了!\n");
        }
        else
        {
            printf("猜对了!\n");
            break;
        }
    }
}

int main()
{
    // 生成一个随机数，作为猜测的答案
    srand((unsigned)time(NULL)); // 随机数种子
    int num = rand() % 10 + 1; 
    // guessTheNumber(num);
    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 3 + 1;
        printf("%d ", num);
    }

    // 结束程序，等待用户输入任意键退出
    system("pause");
    return 0;
}
