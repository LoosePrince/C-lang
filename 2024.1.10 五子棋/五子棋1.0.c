#include <stdio.h>
#include <stdlib.h>

#define ROW 15 // �������̵�����
#define COL 15 // �������̵�����

char board[ROW][COL]; // ��������
char players[2] = {'X', 'O'}; // X������壬O�������

// ��ʼ�����̵ĺ���
void init(){
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = ' '; // �������ϵ�ÿ��λ�ö���ʼ��Ϊ�ո�
        }
    }
}

// ��ӡ���̵ĺ���
void printBoard(){
    system("cls");
    printf("������1.0��C���԰棩\n\n�����������ڿհ״����ӣ��������+����������ӣ�����б�������Ӽ�Ϊ��ʤ��\n\n\n");
    printf("   ");
    for (int i = 0; i < COL; i++) {
        printf("%d|", i); // ��ӡ�к�
    }
    printf("\n_____________________________________");
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("%c|", 'A' + i); // ��ӡ�к�
        for (int j = 0; j < COL; j++) {
            if(j > 9)
            {
                printf("%2c ", board[i][j]); // ��ӡ�����ϵ�����
            }
            else
            {
                printf("%2c", board[i][j]); // ��ӡ�����ϵ�����
            }
        }
        printf("\n");
    }
}

// ����ĺ���
void makeMove(int row, int col, char player){
    board[row][col] = player; // �����ӷ���������ָ����λ��
}

// ����Ƿ�Ӯ��ĺ���
int checkWin(int row, int col, char player){
    int count = 1;
    for (int i = col - 1; i >= 0 && board[row][i] == player; i--) {
        count++;
    }
    for (int i = col + 1; i < COL && board[row][i] == player; i++) {
        count++;
    }
    if (count >= 5) {
        return 1; // �����һ������5�����������ӣ�����1��ʾӮ��
    }

    count = 1;
    for (int i = row - 1; i >= 0 && board[i][col] == player; i--) {
        count++;
    }
    for (int i = row + 1; i < ROW && board[i][col] == player; i++) {
        count++;
    }
    if (count >= 5) {
        return 1; // �����һ������5�����������ӣ�����1��ʾӮ��
    }

    count = 1;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 && board[i][j] == player; i--, j--) {
        count++;
    }
    for (int i = row + 1, j = col + 1; i < ROW && j < COL && board[i][j] == player; i++, j++) {
        count++;
    }
    if (count >= 5) {
        return 1; // �������Խ�������5�����������ӣ�����1��ʾӮ��
    }

    count = 1;
    for (int i = row - 1, j = col + 1; i >= 0 && j < COL && board[i][j] == player; i--, j++) {
        count++;
    }
    for (int i = row + 1, j = col - 1; i < ROW && j >= 0 && board[i][j] == player; i++, j--) {
        count++;
    }
    if (count >= 5) {
        return 1; // ������ҶԽ�������5�����������ӣ�����1��ʾӮ��
    }

    return 0; // �����û��5�����������ӣ�����0��ʾ��û��Ӯ��
}

// ������
int main() {
    int currentPlayer = 0; // ��ǰ��ҵ�������0��ʾ���壬1��ʾ����
    char rowChar; // �û�������к�
    int col; // �û�������к�
    while (1) {
        init(); // ��ʼ������
        while (1) {
            printBoard(); // ��ӡ����
            printf("��ǰΪ %c ��, ��������������(�� ��): ", players[currentPlayer]); // ��ʾ�û���������λ��
            scanf(" %c %d", &rowChar, &col); // ��ȡ�û����������λ��
            int row = rowChar - 'A'; // ���û�������к�ת��Ϊ��������
            if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != ' ') {
                printf("������Ч���������ӣ�\n"); // ����û����������λ����Ч����ʾ�û���������
                continue;
            }
            makeMove(row, col, players[currentPlayer]); // ��ָ��λ������
            if (checkWin(row, col, players[currentPlayer])) { // ����Ƿ�Ӯ��
                printf(" %c ���ʤ��\n", players[currentPlayer]); // ���Ӯ�壬��ӡӮ����Ϣ
                break;
            }
            currentPlayer = (currentPlayer + 1) % 2; // �л����
        }
        printf("�Ƿ�ʼ�µ�һ�֣� (1Ϊ�¾�, 0Ϊ����): "); // ��ʾ�û��Ƿ�����һ��
        int playAgain;
        scanf("%d", &playAgain); // ��ȡ�û���ѡ��
        if (!playAgain) {
            break; // ����û�ѡ�����棬������Ϸ
        }
    }
    return 0;
}
