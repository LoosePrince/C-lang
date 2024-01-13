#include <stdio.h>
#include <stdlib.h>

#define ROW 15 // 定义棋盘的行数
#define COL 15 // 定义棋盘的列数

char board[ROW][COL]; // 定义棋盘
char players[2] = {'X', 'O'}; // X代表黑棋，O代表白棋

// 初始化棋盘的函数
void init(){
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = ' '; // 将棋盘上的每个位置都初始化为空格
        }
    }
}

// 打印棋盘的函数
void printBoard(){
    system("cls");
    printf("五子棋1.0（C语言版）\n\n规则：在棋盘内空白处落子，输入横轴+纵轴进行落子，横纵斜连成五子即为获胜。\n\n\n");
    printf("   ");
    for (int i = 0; i < COL; i++) {
        printf("%d|", i); // 打印列号
    }
    printf("\n_____________________________________");
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("%c|", 'A' + i); // 打印行号
        for (int j = 0; j < COL; j++) {
            if(j > 9)
            {
                printf("%2c ", board[i][j]); // 打印棋盘上的棋子
            }
            else
            {
                printf("%2c", board[i][j]); // 打印棋盘上的棋子
            }
        }
        printf("\n");
    }
}

// 下棋的函数
void makeMove(int row, int col, char player){
    board[row][col] = player; // 将棋子放在棋盘上指定的位置
}

// 检查是否赢棋的函数
int checkWin(int row, int col, char player){
    int count = 1;
    for (int i = col - 1; i >= 0 && board[row][i] == player; i--) {
        count++;
    }
    for (int i = col + 1; i < COL && board[row][i] == player; i++) {
        count++;
    }
    if (count >= 5) {
        return 1; // 如果在一行中有5个连续的棋子，返回1表示赢棋
    }

    count = 1;
    for (int i = row - 1; i >= 0 && board[i][col] == player; i--) {
        count++;
    }
    for (int i = row + 1; i < ROW && board[i][col] == player; i++) {
        count++;
    }
    if (count >= 5) {
        return 1; // 如果在一列中有5个连续的棋子，返回1表示赢棋
    }

    count = 1;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 && board[i][j] == player; i--, j--) {
        count++;
    }
    for (int i = row + 1, j = col + 1; i < ROW && j < COL && board[i][j] == player; i++, j++) {
        count++;
    }
    if (count >= 5) {
        return 1; // 如果在左对角线上有5个连续的棋子，返回1表示赢棋
    }

    count = 1;
    for (int i = row - 1, j = col + 1; i >= 0 && j < COL && board[i][j] == player; i--, j++) {
        count++;
    }
    for (int i = row + 1, j = col - 1; i < ROW && j >= 0 && board[i][j] == player; i++, j--) {
        count++;
    }
    if (count >= 5) {
        return 1; // 如果在右对角线上有5个连续的棋子，返回1表示赢棋
    }

    return 0; // 如果都没有5个连续的棋子，返回0表示还没有赢棋
}

// 主函数
int main() {
    int currentPlayer = 0; // 当前玩家的索引，0表示黑棋，1表示白棋
    char rowChar; // 用户输入的行号
    int col; // 用户输入的列号
    while (1) {
        init(); // 初始化棋盘
        while (1) {
            printBoard(); // 打印棋盘
            printf("当前为 %c 棋, 请输入落子坐标(横 纵): ", players[currentPlayer]); // 提示用户输入落子位置
            scanf(" %c %d", &rowChar, &col); // 读取用户输入的落子位置
            int row = rowChar - 'A'; // 将用户输入的行号转换为数组索引
            if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != ' ') {
                printf("落子无效，重新落子！\n"); // 如果用户输入的落子位置无效，提示用户重新输入
                continue;
            }
            makeMove(row, col, players[currentPlayer]); // 在指定位置落子
            if (checkWin(row, col, players[currentPlayer])) { // 检查是否赢棋
                printf(" %c 棋获胜！\n", players[currentPlayer]); // 如果赢棋，打印赢家信息
                break;
            }
            currentPlayer = (currentPlayer + 1) % 2; // 切换玩家
        }
        printf("是否开始新的一局？ (1为新局, 0为结束): "); // 提示用户是否再玩一次
        int playAgain;
        scanf("%d", &playAgain); // 读取用户的选择
        if (!playAgain) {
            break; // 如果用户选择不再玩，结束游戏
        }
    }
    return 0;
}
