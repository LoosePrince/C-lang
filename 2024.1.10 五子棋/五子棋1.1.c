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
    printf("五子棋1.1（C语言版）\n\n规则：在棋盘内空白处落子，输入横轴+纵轴进行落子，横纵斜连成五子即为获胜。\n提示：输入棋子符号结束本盘游戏\n更新：修复提示内容，自定义棋子，主动结束，交换行列符号\n\n\n");
    printf("   ");
    for (int i = 0; i < COL; i++) {
        printf("%c|", 'A' + i); // 打印列号
    }
    printf("\n  _______________________________");
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("%2d|", i); // 打印行号
        for (int j = 0; j < COL; j++) {
            printf("%c ", board[i][j]); // 打印棋盘上的棋子
        }
        printf("\n");
    }
}

// 落子的函数
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
    char colChar; // 用户输入的列号
    int row; // 行号
    int col; // 列号
    while (1) {
        init(); // 初始化棋盘
        printBoard(); // 打印棋盘
        printf("\n请输入黑白棋对应显示的字符（不要使用特殊字符或相同字符）:");
        scanf(" %c%c",&players[0],&players[1]);
        while (1) {
            printf("当前旗子：%c \n请输入落子坐标(列行): ", players[currentPlayer]); // 提示用户输入落子位置
            scanf(" %c%c",&colChar , &rowChar); // 读取用户输入的落子位置
            row = rowChar - '0'; // 将用户输入的行号转换为数组索引
            col = colChar - 'A'; // 将用户输入的列号转换为数组索引
            if (colChar == players[0] && rowChar == players[1]) {
                break; // 结束这一盘
            }
            else if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != ' ') {
                printf("落子无效，重新落子！\n"); // 如果用户输入的落子位置无效，提示用户重新输入
                continue;
            }
            makeMove(row, col, players[currentPlayer]); // 在指定位置落子
            printBoard(); // 打印棋盘
            if (checkWin(row, col, players[currentPlayer])) { // 检查是否赢棋
                printf("棋子 %c 获胜！\n", players[currentPlayer]); // 如果赢棋，打印赢家信息
                break;
            }
            currentPlayer = (currentPlayer + 1) % 2; // 切换玩家
        }
        printf("是否开始新的一局？ (y/n): "); // 提示用户是否再玩一次
        char playAgain;
        scanf(" %c", &playAgain); // 读取用户的选择
        if (playAgain == 'y') {
            continue; 
        }
        else {
            printf("游戏结束，感谢你的游玩！\n"); // 如果用户选择不再玩，结束游戏
            system("pause");
            break;
        }
    }
    return 0;
}
