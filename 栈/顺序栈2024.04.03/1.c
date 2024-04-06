#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int top;      // ջ��ָ�룬ָ��ջ��Ԫ���������е�λ�ã���ʼֵΪ0����ʾջ��������Ŀ�ͷ��
    int base;     // ջ��ָ�룬ָ��ջ��Ԫ���������е�λ�ã���ʼֵΪ0����ʾջ��������Ŀ�ͷ��
    int data[20]; // �洢ջ��Ԫ�ص����飬�����СΪ20��
} stack;

// ��ʼ��
void creat_stack(stack *s)
{
    s->top = 0;
    s->base = 0;
    memset(s->data, 0, sizeof(s->data)); // �������е�����Ԫ�س�ʼ��Ϊ0��
}

// ��ջ
void push(stack *s, int value) // ��ջ��������Ԫ��valueѹ��ջs�С�
{

    if (s->top >= sizeof(s->data) / sizeof(s->data[0]) - 1 || s->top < s->base) // ���ջ���������޷���ջ��
    {
        printf("Stackջ�������޷���ջ\n"); // �����ʾ��Ϣ��
    }
    else // ���ջδ�����������ջ��
    {
        s->data[s->top] = value; // ��Ԫ��valueѹ��ջ����
        s->top++;                // ջ��ָ���1����ʾջ��Ԫ��λ�ú��ơ�
    }
}

// ѭ����ջ
void push_loop(stack *s) // ѭ����ջ���������û������Ԫ��ѹ��ջs�С�
{
    int i, value;
    printf("������Ҫ��ջ�ĸ���: ");                                                // �����ʾ��Ϣ��
    scanf("%d", &i);                                                               // ��ȡ�û������Ԫ�ظ�����
    if (i + s->top > sizeof(s->data) / sizeof(s->data[0]) - 1 || s->top < s->base) // ���ջ���������޷���ջ��
    {
        printf("Stackջ���洢20��Ԫ�أ��޷���ջ\n"); // �����ʾ��Ϣ��
    }
    else
    {
        printf("������Ҫ��ջ��Ԫ�أ��Կո�����س�ȷ��:\n "); // �����ʾ��Ϣ��
        for (int j = 0; j < i; j++)                           // ѭ��i�Ρ�
        {
            scanf("%d", &value); // ��ȡ�û������Ԫ�ء�
            push(s, value);      // ����push������Ԫ��valueѹ��ջs�С�
        }
    }
}

// ��ջ
void pop(stack *s) // ��ջ��������ջ��Ԫ�ص�����
{
    if (s->top <= s->base) // ���ջΪ�գ����޷���ջ��
    {
        printf("StackջΪ�գ��޷���ջ\n"); // �����ʾ��Ϣ��
    }
    else // ���ջ��Ϊ�գ�����Գ�ջ��
    {
        s->data[s->top] = 0; // ��ջ��Ԫ����Ϊ0��
        s->top--;            // ջ��ָ���1����ʾջ��Ԫ��λ��ǰ�ơ�
    }
}

// ѭ����ջ
void pop_loop(stack *s) // ѭ����ջ��������ջs�е�Ԫ�����ε�����
{
    while (s->top > s->base) // ��ջ��Ϊ��ʱ�����Խ���ѭ����ջ������
    {
        pop(s); // ����pop��������ջ��Ԫ�ص�����
    }
    printf("Stackջ�����\n"); // �����ʾ��Ϣ��
}

// ��ȡջ��Ԫ��
int get_top(stack *s) // ��ȡջ��Ԫ�ز���������ջ��Ԫ�ء�
{
    if (s->top <= s->base) // ���ջΪ�գ����޷���ȡջ��Ԫ�ء�
    {
        printf("StackջΪ�գ��޷���ȡջ��Ԫ��\n"); // �����ʾ��Ϣ��
        return -1;                                 // ����-1��ʾ��ȡʧ�ܡ�
    }
    else // ���ջ��Ϊ�գ�����Ի�ȡջ��Ԫ�ء�
    {
        return s->data[s->top - 1]; // ����ջ��Ԫ�ء�
    }
}

// ���
void print_stack(stack *s) // ���ջs�е�����Ԫ�ء�
{
    int i = 0;         // ����һ��������i�����ڱ���ջ�е�Ԫ�ء�
    while (i < s->top) // ��iС��ջ��ָ��ʱ����ʾջ�л���Ԫ�ء�
    {
        printf("%d ", s->data[i]); // ���ջ�е�i��Ԫ�ء�
        i++;                       // ������i��1����ʾ������һ��Ԫ�ء�
    }
    printf("\n"); // ������з���ʹ��������������
}

// ��ȡָ��Ԫ��ֵ
int get_value(stack *s, int index) // ��ȡָ��Ԫ��ֵ����������ָ��Ԫ��ֵ��
{
    if (index >= s->top) // ���ָ���������ڵ���ջ��ָ�룬���ʾջ��û�и�Ԫ�ء�
    {
        printf("Stackջ��û�и�Ԫ��\n"); // �����ʾ��Ϣ��
        return -1;                       // ����-1��ʾ��ȡʧ�ܡ�
    }
    else // ���ָ������С��ջ��ָ�룬���ʾջ���и�Ԫ�ء�
    {
        return s->data[index]; // ����ָ��Ԫ��ֵ��
    }
}

int main()
{
    stack s;                     // ����һ��ջs��
    creat_stack(&s);             // ��ʼ��ջs��
    push_loop(&s);               // ѭ����ջ�����������Ԫ����ջ��
    print_stack(&s);             // ���ջs�е�����Ԫ�ء�
    pop(&s);                     // ��ջ��������ջ��Ԫ�ص�����
    printf("%d\n", get_top(&s)); // ��ȡջ��Ԫ�ز���������ջ��Ԫ�ء�
    system("pause");
    return 0;
}
