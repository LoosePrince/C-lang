#include <stdio.h>
//#include <math.h>

int main()
{
    int i;
    char x[i];
    for ( i = 1; i <= 5; i++)
    {
        scanf("%c", &x[i]);
    }
    for ( i = 1; i <= 5; i++)
    {
        if (x[i] >= 'A' && x[i] <= 'Z')
        {
            printf("%c",x[i]+32);
        }
        if (x[i] >= 'a' && x[i] <= 'z')
        {
            printf("%c",x[i]-32);
        }
    }
    return 0;
}
