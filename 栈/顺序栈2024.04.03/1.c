#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int top;      // 栈顶指针，指向栈顶元素在数组中的位置，初始值为0，表示栈顶在数组的开头。
    int base;     // 栈底指针，指向栈底元素在数组中的位置，初始值为0，表示栈底在数组的开头。
    int data[20]; // 存储栈中元素的数组，数组大小为20。
} stack;

// 初始化
void creat_stack(stack *s)
{
    s->top = 0;
    s->base = 0;
    memset(s->data, 0, sizeof(s->data)); // 将数组中的所有元素初始化为0。
}

// 入栈
void push(stack *s, int value) // 入栈操作，将元素value压入栈s中。
{

    if (s->top >= sizeof(s->data) / sizeof(s->data[0]) - 1 || s->top < s->base) // 如果栈已满，则无法入栈。
    {
        printf("Stack栈已满，无法入栈\n"); // 输出提示信息。
    }
    else // 如果栈未满，则可以入栈。
    {
        s->data[s->top] = value; // 将元素value压入栈顶。
        s->top++;                // 栈顶指针加1，表示栈顶元素位置后移。
    }
}

// 循环入栈
void push_loop(stack *s) // 循环入栈操作，将用户输入的元素压入栈s中。
{
    int i, value;
    printf("请输入要入栈的个数: ");                                                // 输出提示信息。
    scanf("%d", &i);                                                               // 读取用户输入的元素个数。
    if (i + s->top > sizeof(s->data) / sizeof(s->data[0]) - 1 || s->top < s->base) // 如果栈已满，则无法入栈。
    {
        printf("Stack栈最多存储20个元素，无法入栈\n"); // 输出提示信息。
    }
    else
    {
        printf("请输入要入栈的元素，以空格隔开回车确定:\n "); // 输出提示信息。
        for (int j = 0; j < i; j++)                           // 循环i次。
        {
            scanf("%d", &value); // 读取用户输入的元素。
            push(s, value);      // 调用push函数将元素value压入栈s中。
        }
    }
}

// 出栈
void pop(stack *s) // 出栈操作，将栈顶元素弹出。
{
    if (s->top <= s->base) // 如果栈为空，则无法出栈。
    {
        printf("Stack栈为空，无法出栈\n"); // 输出提示信息。
    }
    else // 如果栈不为空，则可以出栈。
    {
        s->data[s->top] = 0; // 将栈顶元素置为0。
        s->top--;            // 栈顶指针减1，表示栈顶元素位置前移。
    }
}

// 循环出栈
void pop_loop(stack *s) // 循环出栈操作，将栈s中的元素依次弹出。
{
    while (s->top > s->base) // 当栈不为空时，可以进行循环出栈操作。
    {
        pop(s); // 调用pop函数，将栈顶元素弹出。
    }
    printf("Stack栈已清空\n"); // 输出提示信息。
}

// 获取栈顶元素
int get_top(stack *s) // 获取栈顶元素操作，返回栈顶元素。
{
    if (s->top <= s->base) // 如果栈为空，则无法获取栈顶元素。
    {
        printf("Stack栈为空，无法获取栈顶元素\n"); // 输出提示信息。
        return -1;                                 // 返回-1表示获取失败。
    }
    else // 如果栈不为空，则可以获取栈顶元素。
    {
        return s->data[s->top - 1]; // 返回栈顶元素。
    }
}

// 输出
void print_stack(stack *s) // 输出栈s中的所有元素。
{
    int i = 0;         // 定义一个计数器i，用于遍历栈中的元素。
    while (i < s->top) // 当i小于栈顶指针时，表示栈中还有元素。
    {
        printf("%d ", s->data[i]); // 输出栈中第i个元素。
        i++;                       // 计数器i加1，表示遍历下一个元素。
    }
    printf("\n"); // 输出换行符，使输出结果更清晰。
}

// 获取指定元素值
int get_value(stack *s, int index) // 获取指定元素值操作，返回指定元素值。
{
    if (index >= s->top) // 如果指定索引大于等于栈顶指针，则表示栈中没有该元素。
    {
        printf("Stack栈中没有该元素\n"); // 输出提示信息。
        return -1;                       // 返回-1表示获取失败。
    }
    else // 如果指定索引小于栈顶指针，则表示栈中有该元素。
    {
        return s->data[index]; // 返回指定元素值。
    }
}

int main()
{
    stack s;                     // 定义一个栈s。
    creat_stack(&s);             // 初始化栈s。
    push_loop(&s);               // 循环入栈操作，将多个元素入栈。
    print_stack(&s);             // 输出栈s中的所有元素。
    pop(&s);                     // 出栈操作，将栈顶元素弹出。
    printf("%d\n", get_top(&s)); // 获取栈顶元素操作，返回栈顶元素。
    system("pause");
    return 0;
}
