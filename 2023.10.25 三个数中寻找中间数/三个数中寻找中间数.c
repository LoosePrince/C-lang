#include <stdio.h>
//思路二的另一种方法，不使用if
int main()
{
    int s1, s2, s3;
    scanf("%d%d%d", &s1, &s2, &s3);
    int max = (s1 > s2) ? ((s1 > s3) ? s1 : s3) : ((s2 > s3) ? s2 : s3);
    int min = (s1 < s2) ? ((s1 < s3) ? s1 : s3) : ((s2 < s3) ? s2 : s3);
    printf("%d", (s1+s2+s3)-max-min);
    return 0;
}

//思路二
void run()
{
    int s1, s2, s3;
    scanf("%d%d%d", &s1, &s2, &s3);
    int max = s1;
    //获取最大数
    if (s2 > max) {max = s2;}
    if (s3 > max) {max = s3;}

    int min = s1;
    //获取最小数
    if (s2 < min) {min = s2;}
    if (s3 < min) {min = s3;}

    //三数相加减去最大和最小就是中位数
    int s = (s1+s2+s3)-max-min;
    printf("%d",s);
    return 0;
}

//思路一
void run2()
{
    int s1,s2,s3;
    scanf("%d%d%d",&s1,&s2,&s3);
    //比较 s1是否小于s2大于s3 或者 s1是否大于s2小于s3
    if ( (s1 <= s2 && s1 >= s3) || (s1 >= s2 && s1 <= s3) )
    {
        printf("%d",s1);
    }
    //比较 s2是否大于s1小于s3 或者 s2是否大于s1小于s3
    else if ( (s2 <= s1 && s2 >= s3) || (s2 >= s1 && s2 <= s3) )
    {
        printf("%d",s2);
    }
    //s1和s3都不是那么就是s3
    else
    {
        printf("%d",s3);
    }
    return 0;
}
