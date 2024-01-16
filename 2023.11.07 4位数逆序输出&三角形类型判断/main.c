#include <stdio.h>
#include <math.h>

int main() //字符逆转方法
{
    char a,b,c,d;
    scanf("%c%c%c%c",&a,&b,&c,&d); //逐个读取，逐个输出
    printf("%c %c %c %c\n",d,c,b,a);
    return 0;
}

void run1() //除数方法（仅限四位的数字）
{
    int a;
    scanf("%d",&a);
    int s1 = a%10;  //1234的10的余数是4，也就是个位
    int s2 = a/10%10; //除以10让十位变成个位
    int s3 = a/100%10;
    int s4 = a/1000%10;
    printf("%d %d %d %d ",s1,s2,s3,s4);
    return 0;
}

void run2() //除数方法2（仅限四位的数字）
{
    int a;
    scanf("%d",&a);
    int s1 = a/1000 ; a = a - s1*1000; //1234除以1000得整数的1，也就是千位，然后减去取得的整数乘以当前位得到百位数
    int s2 = a/100 ; a = a - s2*100;
    int s3 = a/10 ; a = a - s3*10;
    printf("%d %d %d %d ",a,s3,s2,s1);
    return 0;
}

void run3() //三角形判定
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if( a+b>=c && a+c>=b && b+c>=a)
    {
        if( a==b && b==c)
        {
            printf("全等三角形");
        }
        else if( a==b || a==c || b==c)
        {
            printf("等腰三角形");
        }
        else if( a*a+b*b == c*c || a*a+c*c==b*b || b*b+c*c==a*a )
        {
            printf("直角三角形");
        }
        else
        {
            printf("普通三角形");
        }
        int l = a+b+c;
        printf("\n三角形周长：%d\n",l);
    }
    else
    {
        printf("不构成三角形\n");
    }
    return 0;
}
