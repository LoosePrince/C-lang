#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

void guessTheNumber(int number)
{
    int guess;
    printf("��������Ϸ��ʼ!\n");
    while (1)
    {
        printf("��������Ĳ²�:");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("�´���!\n"); 
        }
        else if (guess < number)
        {
            printf("��С��!\n");
        }
        else
        {
            printf("�¶���!\n");
            break;
        }
    }
}

int main()
{
    // ����һ�����������Ϊ�²�Ĵ�
    srand((unsigned)time(NULL)); // ���������
    int num = rand() % 10 + 1; 
    // guessTheNumber(num);
    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 3 + 1;
        printf("%d ", num);
    }

    // �������򣬵ȴ��û�����������˳�
    system("pause");
    return 0;
}
