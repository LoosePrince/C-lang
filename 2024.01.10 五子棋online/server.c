#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket1, clientSocket2;
    struct sockaddr_in serverAddr, clientAddr;
    int clientAddrSize = sizeof(clientAddr);
    char buffer[MAX_BUF_SIZE];
    int recvSize;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WinSock��ʼ��ʧ��\n");
        return 1;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        printf("����socketʧ��\n");
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080); // ѡ��һ���˿�

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("��ʧ��\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, 2) == SOCKET_ERROR) {
        printf("����ʧ��\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("�ȴ������ͻ�������...\n");
    clientSocket1 = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket1 == INVALID_SOCKET) {
        printf("�ͻ���1����ʧ��\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("�ͻ���1������\n");

    clientSocket2 = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket2 == INVALID_SOCKET) {
        printf("�ͻ���2����ʧ��\n");
        closesocket(clientSocket1);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("�ͻ���2������\n");

    // ֪ͨ�ͻ���˭������
    const char *firstPlayer = "��������";
    const char *secondPlayer = "���Ǻ���";
    send(clientSocket1, secondPlayer, strlen(secondPlayer) + 1, 0); // �����һ�����ӵĿͻ��˺���
    send(clientSocket2, firstPlayer, strlen(firstPlayer) + 1, 0); // �ڶ������ӵĿͻ�������

    // �������ͻ���֮��ת����Ϣ
    while (1) {
        memset(buffer, 0, MAX_BUF_SIZE);
        recvSize = recv(clientSocket2, buffer, MAX_BUF_SIZE, 0); // �����ֿͻ��˽���
        if (recvSize <= 0) break; // �ͻ��˶Ͽ����ӻ����
        send(clientSocket1, buffer, recvSize, 0); // ת�������ֿͻ���

        memset(buffer, 0, MAX_BUF_SIZE);
        recvSize = recv(clientSocket1, buffer, MAX_BUF_SIZE, 0); // �Ӻ��ֿͻ��˽���
        if (recvSize <= 0) break; // �ͻ��˶Ͽ����ӻ����
        send(clientSocket2, buffer, recvSize, 0); // ת�������ֿͻ���
    }

    // ����
    closesocket(clientSocket1);
    closesocket(clientSocket2);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}