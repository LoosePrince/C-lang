#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    printf("������һ������\n");
    scanf("%d", &n);
    int factorial = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
        sum += factorial;
    }
    printf("%d\n", sum);
    system("pause");
    return 0;
}
