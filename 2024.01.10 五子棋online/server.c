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
        printf("WinSock初始化失败\n");
        return 1;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        printf("创建socket失败\n");
        WSACleanup();
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080); // 选择一个端口

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("绑定失败\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, 2) == SOCKET_ERROR) {
        printf("监听失败\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("等待两个客户端连接...\n");
    clientSocket1 = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket1 == INVALID_SOCKET) {
        printf("客户端1连接失败\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("客户端1已连接\n");

    clientSocket2 = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket2 == INVALID_SOCKET) {
        printf("客户端2连接失败\n");
        closesocket(clientSocket1);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("客户端2已连接\n");

    // 通知客户端谁是先手
    const char *firstPlayer = "你是先手";
    const char *secondPlayer = "你是后手";
    send(clientSocket1, secondPlayer, strlen(secondPlayer) + 1, 0); // 假设第一个连接的客户端后手
    send(clientSocket2, firstPlayer, strlen(firstPlayer) + 1, 0); // 第二个连接的客户端先手

    // 在两个客户端之间转发消息
    while (1) {
        memset(buffer, 0, MAX_BUF_SIZE);
        recvSize = recv(clientSocket2, buffer, MAX_BUF_SIZE, 0); // 从先手客户端接收
        if (recvSize <= 0) break; // 客户端断开连接或出错
        send(clientSocket1, buffer, recvSize, 0); // 转发给后手客户端

        memset(buffer, 0, MAX_BUF_SIZE);
        recvSize = recv(clientSocket1, buffer, MAX_BUF_SIZE, 0); // 从后手客户端接收
        if (recvSize <= 0) break; // 客户端断开连接或出错
        send(clientSocket2, buffer, recvSize, 0); // 转发给先手客户端
    }

    // 清理
    closesocket(clientSocket1);
    closesocket(clientSocket2);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}