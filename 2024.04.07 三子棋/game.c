#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// #include "test.h"
#define ROW 9 // �������̵�����
#define COL 9 // �������̵�����
#define length 5 // �������ɳ���

char board[ROW][COL];

void init()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = ' '; // �������ϵ�ÿ��λ�ö���ʼ��Ϊ�ո�
        }
    }
}

void print_board()
{
    system("cls"); // ����
    printf("����: ���Ӱɣ���Ӯ�����ҵ� �d(�R���Q*)o\n�ǵ�Ŷ����Ҫ�������̣�ͬʱ������ %d �Ӳ�Ȼ������� []~(������)~*\n\n", length);
    printf("   |");
    for (int j = 0; j < COL; j++)
    {
        printf(" %d ", j + 1);
        if (j < COL - 1)
        {
            printf("|");
        }
    }
    printf("\n---|");
    for (int j = 0; j < COL; j++)
    {
        printf("---"); // ��ӡ�ָ���
        if (j < COL - 1)
        {
            printf("|");
        }
    }
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        printf(" %d |", i + 1);
        for (int j = 0; j < COL; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < COL - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < COL - 1)
        {
            printf("---|");
        }
        for (int j = 0; j < COL; j++)
        {
            if (i < ROW - 1)
            {
                printf("---"); // ��ӡ�ָ���
                if (j < COL - 1)
                {
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}

//����
int play(int row, int col, char player)
{
    if (board[row][col] == ' ' && row >= 0 && row < ROW && col >= 0 && col < COL)
    {
        board[row][col] = player;
        return 1;
    }
    else
    {
        return 0; // ����ʧ�ܣ�����0
    }
}

int check_win(int row, int col, char player)
{
    int count = 1; // �ں�����ʼʱ����count����
    // ������
    for (int i = col - 1; i >= 0 && board[row][i] == player; i--)
    {
        count++;
    }
    for (int i = col + 1; i < COL && board[row][i] == player; i++)
    {
        count++;
    }
    if (count >= length)
    {
        return 1;
    }

    count = 1; // ����count�����������¶���
    // �������
    for (int i = row - 1; i >= 0 && board[i][col] == player; i--)
    {
        count++;
    }
    for (int i = row + 1; i < ROW && board[i][col] == player; i++)
    {
        count++;
    }
    if (count >= length)
    {
        return 1;
    }

    count = 1; // ����count
    // ������Խ���
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 && board[i][j] == player; i--, j--)
    {
        count++;
    }
    for (int i = row + 1, j = col + 1; i < ROW && j < COL && board[i][j] == player; i++, j++)
    {
        count++;
    }
    if (count >= length)
    {
        return 1;
    }

    count = 1; // ����count
    // ��鷴�Խ���
    for (int i = row - 1, j = col + 1; i >= 0 && j < COL && board[i][j] == player; i--, j++)
    {
        count++;
    }
    for (int i = row + 1, j = col - 1; i < ROW && j >= 0 && board[i][j] == player; i++, j--)
    {
        count++;
    }
    if (count >= length)
    {
        return 1;
    }
    
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0; // û��ƽ�֣�����
            }
        }
    }

    return -1; //ƽ�֣�����-1
}

//��������
int computer_play()
{
    while (1)
    {
        int row = rand() % ROW;
        int col = rand() % COL;
        if (play(row, col, 'O'))
        {
            print_board();
            int fail = check_win(row, col, 'O');
            if (fail == 1)
            {
                // printf("����Ӯ��!\n");
                printf("�������� %d �ӣ����������ˣ����� �d(�R���Q*)o��\n", length);
                printf("\n");
                system("pause");
                return 1;
            }
            else if (fail == -1)
            {
                // printf("ƽ��!\n");
                printf("��ϲ��Ӯ�ˣ������� (�ЩЩn�Щ�)��\n");
                return 1;
            }
            return 0;
        }
    }
}

void game()
{
    init();
    print_board();
    // �������
    while (1) 
    {
        int row, col;
        printf("�����������������(��/��):");
        scanf("%d%d", &row, &col);
        row--;
        col--;
        if (play(row, col, 'X'))
        {
            print_board();
            int fail = check_win(row, col, 'X');
            if (fail == 1)
            {
                // printf("��Ӯ��!\n");
                printf("�������� %d �ӣ����������ˣ����� �d(�R���Q*)o��\n", length);
                printf("\n");
                system("pause");
                break;
            }
            else if (fail == -1)
            {
                // printf("ƽ��!\n");
                printf("��ϲ��Ӯ�ˣ������� (�ЩЩn�Щ�)��\n");
                break;
            }
            else
            {
                if(computer_play()) // ��������
                {
                    break;
                }
            } 
        }
        else
        {
            printf("����ʧ�ܣ�����������!\n");
        }
    }

    // ��������
    // while (1)
    // {
    //     if (computer_play()) // ��������
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         int row, col;
    //         printf("�����������������(��/��):");
    //         scanf("%d%d", &col, &row);
    //         row--;
    //         col--;
    //         if (play(row, col, 'X'))
    //         {
    //             print_board();
    //             if (check_win(row, col, 'X'))
    //             {
    //                 printf("��Ӯ��!\n");
    //                 printf("\n");
    //                 system("pause");
    //                 break;
    //             }
    //         }
    //         else
    //         {
    //             printf("����ʧ�ܣ�����������!\n");
    //         }
    //     }
    // }
}

int main()
{
    srand((unsigned)time(NULL)); // ���������
    while (1)
    {
        system("cls"); // ����
        printf("��ӭ���������� �ҵ� o(*������*)�֣�%d ������Ϸ!\n", length);
        printf("����Ϊ�������Ѷȣ�ƽ�֣������������̣�Ϊ���ʤ������һ������ %d ��Ϊ���䣨���� ��������� ��(�R���Q)�ף�\n", length);
        printf("\n1.��ʼ��Ϸ\n");
        printf("0.�˳���Ϸ\n");
        printf("��ѡ��:>");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ");
            goto exit;
        default:
            printf("�������");
            break;
        }
    }
exit:
    printf("\n");
    system("pause");
    return 0;
}
