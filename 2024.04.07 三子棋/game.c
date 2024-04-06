#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// #include "test.h"
#define ROW 9 // 定义棋盘的行数
#define COL 9 // 定义棋盘的列数
#define length 5 // 定义连成长度

char board[ROW][COL];

void init()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = ' '; // 将棋盘上的每个位置都初始化为空格
        }
    }
}

void print_board()
{
    system("cls"); // 清屏
    printf("电脑: 落子吧，你赢不了我的 ヾ(≧▽≦*)o\n记得哦，你要填满棋盘，同时不连成 %d 子不然你就输啦 []~(￣▽￣)~*\n\n", length);
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
        printf("---"); // 打印分割线
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
                printf("---"); // 打印分割线
                if (j < COL - 1)
                {
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}

//落子
int play(int row, int col, char player)
{
    if (board[row][col] == ' ' && row >= 0 && row < ROW && col >= 0 && col < COL)
    {
        board[row][col] = player;
        return 1;
    }
    else
    {
        return 0; // 落子失败，返回0
    }
}

int check_win(int row, int col, char player)
{
    int count = 1; // 在函数开始时定义count变量
    // 检查横向
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

    count = 1; // 重置count，而不是重新定义
    // 检查纵向
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

    count = 1; // 重置count
    // 检查正对角线
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

    count = 1; // 重置count
    // 检查反对角线
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
                return 0; // 没有平局，继续
            }
        }
    }

    return -1; //平局，返回-1
}

//电脑落子
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
                // printf("电脑赢了!\n");
                printf("我连成了 %d 子，所以你输了（电脑 ヾ(≧▽≦*)o）\n", length);
                printf("\n");
                system("pause");
                return 1;
            }
            else if (fail == -1)
            {
                // printf("平局!\n");
                printf("恭喜你赢了！（电脑 (┬┬﹏┬┬)）\n");
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
    // 玩家先手
    while (1) 
    {
        int row, col;
        printf("请输入你的落子坐标(行/列):");
        scanf("%d%d", &row, &col);
        row--;
        col--;
        if (play(row, col, 'X'))
        {
            print_board();
            int fail = check_win(row, col, 'X');
            if (fail == 1)
            {
                // printf("你赢了!\n");
                printf("你连成了 %d 子，所以你输了（电脑 ヾ(≧▽≦*)o）\n", length);
                printf("\n");
                system("pause");
                break;
            }
            else if (fail == -1)
            {
                // printf("平局!\n");
                printf("恭喜你赢了！（电脑 (┬┬﹏┬┬)）\n");
                break;
            }
            else
            {
                if(computer_play()) // 电脑落子
                {
                    break;
                }
            } 
        }
        else
        {
            printf("落子失败，请重新输入!\n");
        }
    }

    // 电脑先手
    // while (1)
    // {
    //     if (computer_play()) // 电脑落子
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         int row, col;
    //         printf("请输入你的落子坐标(列/行):");
    //         scanf("%d%d", &col, &row);
    //         row--;
    //         col--;
    //         if (play(row, col, 'X'))
    //         {
    //             print_board();
    //             if (check_win(row, col, 'X'))
    //             {
    //                 printf("你赢了!\n");
    //                 printf("\n");
    //                 system("pause");
    //                 break;
    //             }
    //         }
    //         else
    //         {
    //             printf("落子失败，请重新输入!\n");
    //         }
    //     }
    // }
}

int main()
{
    srand((unsigned)time(NULL)); // 随机数种子
    while (1)
    {
        system("cls"); // 清屏
        printf("欢迎来到（电脑 我的 o(*￣▽￣*)ブ）%d 子棋游戏!\n", length);
        printf("规则：为了提升难度，平局（填满整个棋盘）为你获胜，任意一方连成 %d 子为你输（电脑 我随机落子 ψ(≧▽≦)ψ）\n", length);
        printf("\n1.开始游戏\n");
        printf("0.退出游戏\n");
        printf("请选择:>");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏");
            goto exit;
        default:
            printf("输入错误");
            break;
        }
    }
exit:
    printf("\n");
    system("pause");
    return 0;
}
