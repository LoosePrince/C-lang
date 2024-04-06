#include <stdio.h>
#include<stdlib.h>
#include <math.h>

// 定义单项链表
typedef struct Lnode
{
    int data; //定义节点的数据域
    struct Lnode *next; //定义节点的指针域
} Lnode;


//初始化
void initlist(Lnode *L)
{
    L->next = NULL; //初始化L节点的next指针指向NULL
}

// 输出
void prlist(Lnode *L)
{
    printf("链表的所有元素为：");
    L = L->next;   // 将L节点的next指针指向的节点赋值给L，即L指向第一个节点。
    while (L != 0) // 循环输出链表中的所有节点。
    {
        printf("%d ", L->data); // 输出链表中的所有节点。
        L = L->next;            // 将L节点的next指针指向的节点赋值给L，即L指向下一个节点。
    }
    printf("\n");
}

//前插法
void creatlist(Lnode *L)
{
    int n;//定义一个变量，用于存储用户输入的数组长度
    printf("请输入你要插入多少个节点:"); //提示用户输入数组长度
    scanf("%d",&n);//读取用户输入的数组长度
    int i = n; //定义一个变量，用于存储数组中的元素
    printf("请输入%d个节点的值:\n",n); //提示用户输入节点的值
    for (; i > 0; i--) //循环插入节点
    {
        Lnode *p = (Lnode *)malloc(sizeof(Lnode)); //创建一个新节点p，并为其分配内存空间
        scanf("%d",&p->data); //读取用户输入的第i个节点的值，并将其存储到p节点的data成员中。
        p -> next = NULL; //将p节点的next指针指向NULL，表示p节点是尾节点，此条可以省略，因为默认会将尾节点指向NULL
        p -> next = L->next; //将p节点的next指针指向L节点的next指针指向的节点，即L节点的下一个节点。
        L -> next = p; //将L节点的next指针指向p节点，即将p节点插入到L节点的前面。
    }
    prlist(L); // 输出链表。
}

//尾插法
void creatlist1(Lnode *L)
{
    int n;//定义一个变量，用于存储用户输入的数组长度
    printf("请输入你要插入多少个节点:"); //提示用户输入数组长度
    scanf("%d",&n);//读取用户输入的数组长度
    int i = n; //定义一个变量，用于存储数组中的元素
    printf("请输入%d个节点的值:\n",n); //提示用户输入节点的值
    for (; i > 0; i--) //循环插入节点
    {
        Lnode *p = (Lnode *)malloc(sizeof(Lnode)); //创建一个新节点p，并为其分配内存空间
        scanf("%d",&p->data); //读取用户输入的第i个节点的值，并将其存储到p节点的data成员中。
        p -> next = NULL; //将p节点的next指针指向NULL，表示p节点是尾节点。
        Lnode *q = L; //定义一个指针q，用于遍历链表。
        while (q -> next != NULL) //循环找到链表的尾节点。
        {
            q = q -> next; //将q节点的next指针指向的节点赋值给q，即q指向下一个节点。
        }
        q -> next = p; //将q节点的next指针指向p节点，即将p节点插入到q节点的后面。
    }
    prlist(L); // 输出链表。
}

//插入
void insertlist(Lnode *L)
{
    int n;//定义一个变量，用于存储用户输入的文字
    printf("请输入你要插入的节点的位置:"); //提示用户输入要插入的节点的位置
    scanf("%d",&n);//读取用户输入的要插入的节点
    Lnode *p = L; //定义一个指针p，用于遍历链表。
    int i = 1; //定义一个变量，用于存储节点的位置
    while (p -> next != NULL) //循环找到链表的尾节点。
    {
        if (i == n) //如果节点的位置等于用户输入的位置，则插入该节点。
        {
            Lnode *q = (Lnode *)malloc(sizeof(Lnode)); //创建一个新节点q，并为其分配内存空间
            scanf("%d",&q->data); //读取用户输入的节点的值，并将其存储到q节点的data成员中。
            q -> next = p -> next; //将q节点的next指针指向p节点的next指针指向的节点，即将q节点插入到p节点的后面。
            p -> next = q; //将p节点的next指针指向q节点，即将q节点插入到p节点的后面。
            break; //退出循环。
        }
        i++; //循环加1
        p = p -> next; //将p节点的next指针指向的节点赋值给p，即p指向下一个节点。
    }
    prlist(L); // 输出链表。
}

//删除
void deletelist(Lnode *L)
{
    int n;//定义一个变量，用于存储用户输入的文字
    printf("请输入你要删除的节点的位置:"); //提示用户输入要删除的节点的位置
    scanf("%d",&n);//读取用户输入的要删除的节点
    Lnode *p = L; //定义一个指针p，用于遍历链表。
    int i = 1; //定义一个变量，用于存储节点的位置
    while (p -> next != NULL) //循环找到链表的尾节点。
    {
        if (i == n) //如果节点的位置等于用户输入的位置，则删除该节点。
        {
            Lnode *q = p -> next; //定义一个指针q，用于记录指向要删除的节点。
            p -> next = q -> next; //将p节点的next指针指向q节点的next指针指向的节点，即将q节点从链表中删除。
            free(q); //释放q节点的内存空间。
            break; //退出循环。
        }
        p = p -> next; //将p节点的next指针指向的节点赋值给p，即p指向下一个节点。
        i++; //节点的位置加1。
    }
    prlist(L); // 输出链表。
}

int main()
{
    Lnode L;
    initlist(&L); //初始化链表L。
    creatlist1(&L); //尾插法创建链表。
    insertlist(&L); //插入节点。
    deletelist(&L); //删除链表中的节点。
    return 0;
}
