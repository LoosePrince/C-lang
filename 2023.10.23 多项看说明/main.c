#include<stdio.h>
#include <stdlib.h>

int main()
{
    int run;
    printf("1.由1组成的等腰三角形    2.由1组成的直角三角形\n3.设定今天是星期三，输出20天后是星期几     4.输入长方形的宽和长计算周长和面积\n\n选择要执行的函数：");
    scanf("%d",&run);
    if (run == 1)
    {
        run1();
    }
    else if (run == 2){ run2(); }
    else if (run == 3){ run3(); }
    else if (run == 4){ run4(); }
    else {
        printf("输入错误！");
    }
    return 0;
}

void run1() //等腰三角形
{
    int i,a,h;
    h=4; //总行数
    //printf("请输入三角形的大小（行数）：");scanf("%d",&h);printf("\n"); //手动输入控制行数
    for ( i = 0; i <= h; i++) //行数循环
    {
        for (a = 0; a < h - i; a++) //空格循环
        {
            printf("  "); //空格
        }

        for (a = 0; a < i*2-1; a++) //字符循环
        {
            printf("1 "); //要显示的字符
        }
        printf("\n");
    }
    printf("\n\n");
    main();
}

void run2() //直角三角形
{
    int i,c,d;
    d=7; //字符显示的差值一
    for ( i = 0; i < 5; i++) //总共行数
    {
        c = 6; //设置默认值，和插值1差多少就第一行显示多少个
        while (c < d)
        {
            c = c + 1;
            printf("1 "); //要显示的字符
        }
        d= d + 1; //1的数量增加
        c = c - d;
        printf("\n");
    }
    printf("\n\n");
    main();
}

void run3()
{
    int week,s;
    //scanf("%d",&week);
    week = 3;
    s = (week + 20) % 7;
    char *cn[] = {"天","一","二","三","四","五","六"};
    printf("星期%s\n\n",cn[s]);
    main();
}

void run4()
{
    float a,b,z,m;
    printf("输入长宽以计算周长和面积：");
    scanf("%f %f",&a,&b);
    z = (a+b)*2;
    m = a*b;
    printf("周长：%.2f\n面积：%.2f\n",z,m);
    printf("\n\n");
    main();
}
