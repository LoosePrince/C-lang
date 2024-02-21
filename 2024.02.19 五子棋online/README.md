### 五子棋2.1（联机版）
#### 规则
> 在棋盘内空白处落子，输入纵轴+横轴进行落子，横纵斜连成五子即为获胜。
#### 更新
> **更新：** 修复不切换棋子的错误
#### 文件
client.c
> **客户端（支持点对点）：** 可以用作等待端或者连接服务端时作为客户端使用

server.c
> **服务端（未做验证）：** 本身不具备游戏功能，只负责将两个客户端进行连接

P2P.c
> **点对点端：** 既是服务端也是客户端，可以自己进行互相连接，如果双方不在同一网络需要等待端具备公网IP

#### 视频演示（已取消）
不要攻击我的服务器！！！

#### 图片演示（本地演示）
![image](https://github.com/LoosePrince/C-lang/assets/107794785/d7981adc-e70e-47b5-a7e0-4623475552e7)
![image](https://github.com/LoosePrince/C-lang/assets/107794785/279e17cc-9501-4e22-baba-a462d16251ff)
![image](https://github.com/LoosePrince/C-lang/assets/107794785/fa96ee38-09a1-498c-bfc1-e05641f3d023)
![image](https://github.com/LoosePrince/C-lang/assets/107794785/588deac8-ef7f-42b8-9481-d414061e7f0d)
![image](https://github.com/LoosePrince/C-lang/assets/107794785/95c1e8e4-fbfa-441a-a6f9-751671863f34)
![image](https://github.com/LoosePrince/C-lang/assets/107794785/115b62f6-4fff-4d34-84fb-984351eadb87)

#### 说明
整个代码均使用AI编写，P2P客户端由 **Gemini 1.0 Pro** 和 **GPT3.5** 编写，client和server服务端由 **GPT-4.0** 编写。
