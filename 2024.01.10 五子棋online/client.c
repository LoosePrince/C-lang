#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <conio.h>

#pragma comment(lib, "ws2_32.lib")

#define ROW 15
#define COL 15
#define MAX_BUF_SIZE 1024

char board[ROW][COL];
char players[2] = {'X', 'O'};

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

void printBoard()
{
    system("cls");
    printf("五子棋2.0（C语言联机版）\n\n规则：在棋盘内空白处落子，输入纵轴+横轴进行落子，横纵斜连成五子即为获胜。输入 XO 结束本盘游戏\n其它：游戏和设备不是最高配置，朋友才是.\n更新：测试版\n\n\n");
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

void makeMove(int row, int col, char player)
{
    board[row][col] = player; // 将棋子放在棋盘上指定的位置
}

int checkWin(int row, int col, char player)
{
    int count = 1;
    for (int i = col - 1; i >= 0 && board[row][i] == player; i--)
    {
        count++;
    }
    for (int i = col + 1; i < COL && board[row][i] == player; i++)
    {
        count++;
    }
    if (count >= 5)
    {
        return 1; // 如果在一行中有5个连续的棋子，返回1表示赢棋
    }

    count = 1;
    for (int i = row - 1; i >= 0 && board[i][col] == player; i--)
    {
        count++;
    }
    for (int i = row + 1; i < ROW && board[i][col] == player; i++)
    {
        count++;
    }
    if (count >= 5)
    {
        return 1; // 如果在一列中有5个连续的棋子，返回1表示赢棋
    }

    count = 1;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 && board[i][j] == player; i--, j--)
    {
        count++;
    }
    for (int i = row + 1, j = col + 1; i < ROW && j < COL && board[i][j] == player; i++, j++)
    {
        count++;
    }
    if (count >= 5)
    {
        return 1; // 如果在左对角线上有5个连续的棋子，返回1表示赢棋
    }

    count = 1;
    for (int i = row - 1, j = col + 1; i >= 0 && j < COL && board[i][j] == player; i--, j++)
    {
        count++;
    }
    for (int i = row + 1, j = col - 1; i < ROW && j >= 0 && board[i][j] == player; i++, j--)
    {
        count++;
    }
    if (count >= 5)
    {
        return 1; // 如果在右对角线上有5个连续的棋子，返回1表示赢棋
    }

    return 0; // 如果都没有5个连续的棋子，返回0表示还没有赢棋
}

int main()
{
    system("cls");
    printf("五子棋游戏\n");
    printf("作者：树梢上有只鸟\n");
    printf("工具：VS code , Gemini 1.0 Pro , ChatGPT-3.5 , ChatGPT-4.0 , 记事本(Notepad) , Windows 11 专业版\n\n");
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("初始化 Winsock 失败\n");
        return -1;
    }

    // 询问用户是等待方还是连接方
    int role;
    printf("选择角色：1. 等待方 2. 连接方\n");
    role = getch() - '0'; // 减去 '0' 以获取数字
    printf("\n");

    if (role == 1)
    {
        int port;
        printf("请输入要使用的端口号：");
        scanf("%d", &port);

        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == INVALID_SOCKET)
        {
            printf("创建套接字失败\n");
            WSACleanup();
            return -1;
        }

        SOCKADDR_IN addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);
        if (bind(sock, (SOCKADDR *)&addr, sizeof(addr)) == SOCKET_ERROR)
        {
            printf("绑定套接字到端口失败\n");
            closesocket(sock);
            WSACleanup();
            return -1;
        }

        // 获取本机 IP 地址
        char hostname[256];
        gethostname(hostname, sizeof(hostname));
        HOSTENT *host = gethostbyname(hostname);
        char *ip = inet_ntoa(*(struct in_addr *)*host->h_addr_list);
        printf("本机 IP 地址：%s\n", ip);

        printf("等待对方连接...\n");
        if (listen(sock, 1) == SOCKET_ERROR)
        {
            printf("监听套接字失败\n");
            closesocket(sock);
            WSACleanup();
            return -1;
        }

        SOCKET client_sock;
        SOCKADDR_IN client_addr;
        int client_addr_len = sizeof(client_addr);
        client_sock = accept(sock, (SOCKADDR *)&client_addr, &client_addr_len);
        if (client_sock == INVALID_SOCKET)
        {
            printf("接受连接失败\n");
            closesocket(sock);
            WSACleanup();
            return -1;
        }

        // 显示对方 IP 和端口
        char *client_ip = inet_ntoa(client_addr.sin_addr);
        printf("连接成功！\n");
        printf("对方 IP：%s", client_ip);
        printf(":%d\n\n", ntohs(client_addr.sin_port));

        init();
        int currentPlayer = 1;
        char move[5];
        int row, col;

        while (1)
        {
            if (currentPlayer == 1)
            {
                printf("等待对方落子...\n");
                recv(client_sock, move, sizeof(move), 0);
                row = move[1] - '0';
                col = move[0] - 'A';
                makeMove(row, col, players[currentPlayer]);

                if (checkWin(row, col, players[currentPlayer]))
                {
                    printBoard();
                    printf("恭喜 对方 获胜！\n");
                    break;
                }

                printBoard();
                currentPlayer = 0;
            }
            else
            {
                printBoard();
                printf("我方 落子 (列行): ");
                scanf("%s", move);
                row = move[1] - '0';
                col = move[0] - 'A';

                if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != ' ')
                {
                    printf("落子无效，请重新输入。(按任意键)\n");
                    getchar();
                    continue;
                }

                makeMove(row, col, players[currentPlayer]);
                send(client_sock, move, strlen(move) + 1, 0);

                if (checkWin(row, col, players[currentPlayer]))
                {
                    printBoard();
                    printf("恭喜 我方 获胜！\n");
                    break;
                }

                printBoard();

                currentPlayer = 1;
            }
        }

        closesocket(client_sock);
    }
    else if (role == 2)
    {

        char ip[16];
        int port;
        printf("请输入对方 IP：");
        scanf("%s", ip);
        printf("请输入对方端口：");
        scanf("%d", &port);

        SOCKET client_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (client_sock == INVALID_SOCKET)
        {
            printf("创建套接字失败\n");
            WSACleanup();
            return -1;
        }

        SOCKADDR_IN addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip);
        addr.sin_port = htons(port);
        if (connect(client_sock, (SOCKADDR *)&addr, sizeof(addr)) == SOCKET_ERROR)
        {
            printf("连接到对方失败\n");
            closesocket(client_sock);
            WSACleanup();
            return -1;
        }

        init();
        int currentPlayer = 0;
        char move[5];
        int row, col;

        char serverMsg[32];
        recv(client_sock, serverMsg, sizeof(serverMsg), 0); // 接收服务器发来的信息
        if (strcmp(serverMsg, "你是先手") == 0)
        {
            currentPlayer = 0; // 设置当前玩家为先手
            printf("你是先手。\n");
        }
        else
        {
            currentPlayer = 1; // 设置当前玩家为后手
            printf("你是后手，等待对方落子...\n");
        }

        while (1)
        {
            if (currentPlayer == 0)
            {
                printBoard();
                printf("我方落子 (列行): ");
                scanf("%s", move);
                row = move[1] - '0';
                col = move[0] - 'A';

                if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != ' ')
                {
                    printf("落子无效，请重新输入。\n");
                    continue;
                }

                makeMove(row, col, players[currentPlayer]);
                send(client_sock, move, strlen(move) + 1, 0); // 发送落子信息给服务器

                if (checkWin(row, col, players[currentPlayer]))
                {
                    printBoard();
                    printf("恭喜，你赢了！\n");
                    break;
                }

                printBoard();
                currentPlayer = 1 - currentPlayer; // 切换玩家
                printf("落子已发送，等待对方落子...\n");
            }
            else
            {
                recv(client_sock, move, sizeof(move), 0); // 接收对方落子信息
                row = move[1] - '0';
                col = move[0] - 'A';
                makeMove(row, col, players[1 - currentPlayer]);

                if (checkWin(row, col, players[1 - currentPlayer]))
                {
                    printBoard();
                    printf("很遗憾，对方赢了！\n");
                    break;
                }

                printBoard();
                currentPlayer = 1 - currentPlayer; // 切换回当前玩家
            }
        }

        closesocket(client_sock);
    }

    // closesocket(sock);
    WSACleanup();

    char choice;
    printf("是否再来一局？ (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        main(); // 重新开始一局
        /*if (role == 1) {
            int currentPlayer = 1;
            goto star1;
        }
        else if (role == 2) {
            int currentPlayer = 0;
            goto star2;
        }*/
    }
    else
    {
        printf("游戏结束，感谢您的游玩！（按任意退出）\n");
        getchar();
    }

    return 0;
}
