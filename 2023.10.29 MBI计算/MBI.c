#include <stdio.h>
#include <stdlib.h>

int main()
{
    float kg,cm; //定义变量重量和身高
    printf("请输入身高（cm）和体重（kg）以空格分开：");
    scanf("%f%f",&cm,&kg); //获取身高厘米和体重千克
    float m = cm/100; //转换厘米为米
    float MBI = kg/(m*m); //MBI的公式
    //float MBI = kg/( (cm/100)*(cm/100) )
    printf("MBI:%f\n",MBI); //输出结果
    return 0; 
}
