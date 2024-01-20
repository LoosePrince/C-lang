#include <stdio.h>
#include <stdlib.h>

#define ROW 15 // �������̵�����
#define COL 15 // �������̵�����

char board[ROW][COL];         // ��������
int traversal[ROW][COL];      // ��������
char players[2] = {'X', 'O'}; // Ĭ��X������壬O�������

// ��ʼ�����̵ĺ���
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

// ��ʼ�����̱����ĺ���
void initraversal()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            traversal[i][j] = 0; // �������ϵ�ÿ��λ�ö����Ϊδ����
        }
    }
}

// ��������ϱ�������ӵĺ���
void killtraversal()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (traversal[i][j] == -1) // �����λ�õ����ӱ����Ϊ����Χ
            {
                board[i][j] = ' ';   // ����������Ϊ��
                traversal[i][j] = 0; // ����λ�õı������Ϊδ����
            }
        }
    }
    printBoard(); // ��ӡ����
}

// ��ӡ���̵ĺ���
void printBoard()
{
    system("cls");
    printf("Χ��1.0��C���԰棩\n\n����Χ��\n��ʾ������ t0 ����������Ϸ\n���£�����\n\n\n");
    printf("   ");
    for (int i = 0; i < COL; i++)
    {
        printf("%c|", 'A' + i); // ��ӡ�к�
    }
    printf("\n  _______________________________");
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("%2d|", i); // ��ӡ�к�
        for (int j = 0; j < COL; j++)
        {
            printf("%c ", board[i][j]); // ��ӡ�����ϵ�����
        }
        printf("\n");
    }
}

// ���ӵĺ���
void makeMove(int row, int col, char player)
{
    board[row][col] = player; // �����ӷ���������ָ����λ��
}

// ����Ƿ񱻰�Χ
int SurroundCount(int row, int col, int currentPlayer)
{
    traversal[row][col] = 1; // ����ǰλ�ñ��Ϊ�ѱ���

    // ���ĸ��������
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + dx[i], newCol = col + dy[i];
        if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL)
        {
            if (board[newRow][newCol] == ' ')
            {
                return 0; // �ҵ���ȱ��δ����Χ
            }
            else if (board[newRow][newCol] == players[currentPlayer] && traversal[newRow][newCol] == 0)
            {
                if (SurroundCount(newRow, newCol, currentPlayer) == 0)
                {
                    return 0; // �����������δ����Χ����ǰ����Ҳδ����Χ
                }
            }
        }
    }

    // ����ĸ�����û�п�ȱ����ǰλ�ñ���Χ
    traversal[row][col] = -1; // ���Ϊ����Χ
    return 1;
}

// ����Ƿ��Χ
int Surround(int row, int col, int currentPlayer)
{
    initraversal();                         // ��ʼ�����̱����ĺ���
    int opponent = (currentPlayer + 1) % 2; // ��������

    // ���ĸ��������
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
                traversal[newRow][newCol] = -1; // ��Ƕ�������Ϊ����Χ
                killtraversal();                // �������Χ������
                if (checkWin(row, col, currentPlayer, 0))
                {
                    return 1; // �����ǰ���ʤ��������1
                }
            }
        }
    }
    return 0; // ���û�м�⵽��Χ������0
}

// ����Ƿ�Ӯ��ĺ���
int checkWin(int row, int col, int currentPlayer, int exemptFromDeath)
{
    Surround(row, col, currentPlayer); // �������Χ������

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
        if (Surround(row, col, currentPlayer)) // �����ж��Ƿ��Χ��������ѱ���Χ������
        {
            return 1; // ����1��ʾ��ǰ���ʤ��
        }
    }
    else
    {
        return 1; // Ӯ��
    }
}

// ������
int main()
{
    int currentPlayer = 0;           // ��ǰ��ҵ�������0��ʾ���壬1��ʾ����
    char colChar;                    // �û�������к�
    int row;                         // �к�
    int col;                         // �к�
    int exemptFromDeath[2] = {1, 1}; // ���ڿ��ֱ���
    while (1)
    {
        init();       // ��ʼ������
        printBoard(); // ��ӡ����
        printf("\n������ڰ����Ӧ��ʾ���ַ�����Ҫʹ�������ַ�����ͬ�ַ���:");
        scanf(" %c%c", &players[0], &players[1]);
        while (1)
        {
            printf("��ǰ���ӣ�%c \n��������������(����): ", players[currentPlayer]); // ��ʾ�û���������λ��
            scanf(" %c%d", &colChar, &row);                                          // ��ȡ�û����������λ��
            col = colChar - 'A';                                                     // ���û�������к�ת��Ϊ��������
            if (colChar == 't' && row == 0)
            {
                break; // ������һ��
            }
            else if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != ' ')
            {
                printf("������Ч���������ӣ�\n"); // ����û����������λ����Ч����ʾ�û���������
                continue;
            }
            makeMove(row, col, players[currentPlayer]);                            // ��ָ��λ������
            printBoard();                                                          // ��ӡ����
            if (checkWin(row, col, currentPlayer, exemptFromDeath[currentPlayer])) // ����Ƿ�Ӯ��
            {
                printf("���� %c ��ʤ��\n", players[currentPlayer]); // ���Ӯ�壬��ӡӮ����Ϣ
                break;
            }
            currentPlayer = (currentPlayer + 1) % 2; // �л����
            exemptFromDeath[currentPlayer] = 0;      // ������ֱ���
        }
        printf("�Ƿ�ʼ�µ�һ�֣� (y/n): "); // ��ʾ�û��Ƿ�����һ��
        char playAgain;
        scanf(" %c", &playAgain); // ��ȡ�û���ѡ��
        if (playAgain == 'y')
        {
            continue;
        }
        else
        {
            printf("��Ϸ��������л������棡\n"); // ����û�ѡ�����棬������Ϸ
            system("pause");
            break;
        }
    }
    return 0;
}