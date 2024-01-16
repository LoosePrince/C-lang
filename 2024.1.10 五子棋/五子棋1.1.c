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
    printf("������1.1��C���԰棩\n\n�����������ڿհ״����ӣ��������+����������ӣ�����б�������Ӽ�Ϊ��ʤ��\n��ʾ���������ӷ��Ž���������Ϸ\n���£��޸���ʾ���ݣ��Զ������ӣ������������������з���\n\n\n");
    printf("   ");
    for (int i = 0; i < COL; i++) {
        printf("%c|", 'A' + i); // ��ӡ�к�
    }
    printf("\n  _______________________________");
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("%2d|", i); // ��ӡ�к�
        for (int j = 0; j < COL; j++) {
            printf("%c ", board[i][j]); // ��ӡ�����ϵ�����
        }
        printf("\n");
    }
}

// ���ӵĺ���
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
    char colChar; // �û�������к�
    int row; // �к�
    int col; // �к�
    while (1) {
        init(); // ��ʼ������
        printBoard(); // ��ӡ����
        printf("\n������ڰ����Ӧ��ʾ���ַ�����Ҫʹ�������ַ�����ͬ�ַ���:");
        scanf(" %c%c",&players[0],&players[1]);
        while (1) {
            printf("��ǰ���ӣ�%c \n��������������(����): ", players[currentPlayer]); // ��ʾ�û���������λ��
            scanf(" %c%c",&colChar , &rowChar); // ��ȡ�û����������λ��
            row = rowChar - '0'; // ���û�������к�ת��Ϊ��������
            col = colChar - 'A'; // ���û�������к�ת��Ϊ��������
            if (colChar == players[0] && rowChar == players[1]) {
                break; // ������һ��
            }
            else if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != ' ') {
                printf("������Ч���������ӣ�\n"); // ����û����������λ����Ч����ʾ�û���������
                continue;
            }
            makeMove(row, col, players[currentPlayer]); // ��ָ��λ������
            printBoard(); // ��ӡ����
            if (checkWin(row, col, players[currentPlayer])) { // ����Ƿ�Ӯ��
                printf("���� %c ��ʤ��\n", players[currentPlayer]); // ���Ӯ�壬��ӡӮ����Ϣ
                break;
            }
            currentPlayer = (currentPlayer + 1) % 2; // �л����
        }
        printf("�Ƿ�ʼ�µ�һ�֣� (y/n): "); // ��ʾ�û��Ƿ�����һ��
        char playAgain;
        scanf(" %c", &playAgain); // ��ȡ�û���ѡ��
        if (playAgain == 'y') {
            continue; 
        }
        else {
            printf("��Ϸ��������л������棡\n"); // ����û�ѡ�����棬������Ϸ
            system("pause");
            break;
        }
    }
    return 0;
}
