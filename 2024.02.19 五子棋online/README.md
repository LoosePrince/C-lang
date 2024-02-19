### 五子棋2.0（联机版）
#### 规则
> 在棋盘内空白处落子，输入纵轴+横轴进行落子，横纵斜连成五子即为获胜。
#### 工具
> VS code , Gemini 1.0 Pro , ChatGPT-3.5 , ChatGPT-4.0 , 记事本(Notepad) , Windows 11 专业版
#### 文件
client.c
> **客户端：** 可以用作等待端或者连接服务端时作为客户端使用

server.c
> **服务端：** 本身不具备游戏功能，只负责将两个客户端进行连接

P2P.c
> **点对点端：** 既是服务端也是客户端，可以自己进行互相连接，如果双方不在同一网络需要等待端具备公网IP

#### 说明
整个代码均使用AI编写，P2P客户端由 **Gemini 1.0 Pro** 和 **GPT3.5** 编写，client和server服务端由 **GPT-4.0** 编写。

#### 视频演示
https://github.com/LoosePrince/C-lang/assets/107794785/e47ee824-f2e4-4df4-9fc4-ad8e21b62689
