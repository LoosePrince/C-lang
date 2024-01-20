#include <stdio.h>
#include <stdlib.h>

#define ROW 15 // 定义棋盘的行数
#define COL 15 // 定义棋盘的列数

char board[ROW][COL];         // 定义棋盘
int traversal[ROW][COL];      // 定义棋盘
char players[2] = {'X', 'O'}; // 默认X代表黑棋，O代表白棋

// 初始化棋盘的函数
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

// 初始化棋盘遍历的函数
void initraversal()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            traversal[i][j] = 0; // 将棋盘上的每个位置都标记为未遍历
        }
    }
}

// 清除棋盘上被标记棋子的函数
void killtraversal()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (traversal[i][j] == -1) // 如果该位置的棋子被标记为被包围
            {
                board[i][j] = ' ';   // 将棋子重置为空
                traversal[i][j] = 0; // 将该位置的标记重置为未遍历
            }
        }
    }
    printBoard(); // 打印棋盘
}

// 打印棋盘的函数
void printBoard()
{
    system("cls");
    printf("围棋1.0（C语言版）\n\n规则：围棋\n提示：输入 t0 结束本盘游戏\n更新：测试\n\n\n");
    printf("   ");
    for (int i = 0; i < COL; i++)
    {
        printf("%c|", 'A' + i); // 打印列号
    }
    printf("\n  _______________________________");
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("%2d|", i); // 打印行号
        for (int j = 0; j < COL; j++)
        {
            printf("%c ", board[i][j]); // 打印棋盘上的棋子
        }
        printf("\n");
    }
}

// 落子的函数
void makeMove(int row, int col, char player)
{
    board[row][col] = player; // 将棋子放在棋盘上指定的位置
}

// 检查是否被包围
int SurroundCount(int row, int col, int currentPlayer)
{
    traversal[row][col] = 1; // 将当前位置标记为已遍历

    // 向四个方向遍历
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + dx[i], newCol = col + dy[i];
        if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL)
        {
            if (board[newRow][newCol] == ' ')
            {
                return 0; // 找到空缺，未被包围
            }
            else if (board[newRow][newCol] == players[currentPlayer] && traversal[newRow][newCol] == 0)
            {
                if (SurroundCount(newRow, newCol, currentPlayer) == 0)
                {
                    return 0; // 如果相邻棋子未被包围，则当前棋子也未被包围
                }
            }
        }
    }

    // 如果四个方向都没有空缺，则当前位置被包围
    traversal[row][col] = -1; // 标记为被包围
    return 1;
}

// 检查是否包围
int Surround(int row, int col, int currentPlayer)
{
    initraversal();                         // 初始化棋盘遍历的函数
    int opponent = (currentPlayer + 1) % 2; // 对手棋子

    // 向四个方向遍历
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + dx[i], newCol = col + dy[i];
        if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL &&
            board[newRow][newCol] == players[opponent] && traversal[newRow][newCol] == 0)
        {
            if (SurroundCount(newRow, newCol, opponent) == 1)
            {
                traversal[newRow][newCol] = -1; // 标记对手棋子为被包围
                killtraversal();                // 清除被包围的棋子
                if (checkWin(row, col, currentPlayer, 0))
                {
                    return 1; // 如果当前玩家胜利，返回1
                }
            }
        }
    }
    return 0; // 如果没有检测到包围，返回0
}

// 检查是否赢棋的函数
int checkWin(int row, int col, int currentPlayer, int exemptFromDeath)
{
    Surround(row, col, currentPlayer); // 清除被包围的棋子

    int count = 1;
    for (int i = 0; i < ROW && exemptFromDeath == 0; i++)
    {
        for (int j = 0; j < COL && exemptFromDeath == 0; j++)
        {
            if (board[i][j] == players[(currentPlayer + 1) % 2])
            {
                count++;
            }
        }
    }
    if (count)
    {
        return 0;
        if (Surround(row, col, currentPlayer)) // 继续判断是否包围，并清除已被包围的棋子
        {
            return 1; // 返回1表示当前玩家胜利
        }
    }
    else
    {
        return 1; // 赢棋
    }
}

// 主函数
int main()
{
    int currentPlayer = 0;           // 当前玩家的索引，0表示黑棋，1表示白棋
    char colChar;                    // 用户输入的列号
    int row;                         // 行号
    int col;                         // 列号
    int exemptFromDeath[2] = {1, 1}; // 用于开局保护
    while (1)
    {
        init();       // 初始化棋盘
        printBoard(); // 打印棋盘
        printf("\n请输入黑白棋对应显示的字符（不要使用特殊字符或相同字符）:");
        scanf(" %c%c", &players[0], &players[1]);
        while (1)
        {
            printf("当前旗子：%c \n请输入落子坐标(列行): ", players[currentPlayer]); // 提示用户输入落子位置
            scanf(" %c%d", &colChar, &row);                                          // 读取用户输入的落子位置
            col = colChar - 'A';                                                     // 将用户输入的列号转换为数组索引
            if (colChar == 't' && row == 0)
            {
                break; // 结束这一盘
            }
            else if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != ' ')
            {
                printf("落子无效，重新落子！\n"); // 如果用户输入的落子位置无效，提示用户重新输入
                continue;
            }
            makeMove(row, col, players[currentPlayer]);                            // 在指定位置落子
            printBoard();                                                          // 打印棋盘
            if (checkWin(row, col, currentPlayer, exemptFromDeath[currentPlayer])) // 检查是否赢棋
            {
                printf("棋子 %c 获胜！\n", players[currentPlayer]); // 如果赢棋，打印赢家信息
                break;
            }
            currentPlayer = (currentPlayer + 1) % 2; // 切换玩家
            exemptFromDeath[currentPlayer] = 0;      // 解除开局保护
        }
        printf("是否开始新的一局？ (y/n): "); // 提示用户是否再玩一次
        char playAgain;
        scanf(" %c", &playAgain); // 读取用户的选择
        if (playAgain == 'y')
        {
            continue;
        }
        else
        {
            printf("游戏结束，感谢你的游玩！\n"); // 如果用户选择不再玩，结束游戏
            system("pause");
            break;
        }
    }
    return 0;
}