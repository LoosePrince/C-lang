#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prf (int (*p)[4])
{
    p[1][2] = 100;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    
}

int main()
{
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int (*p)[4] = a;
    prf(p);
    // p[1][2] = *(p + 1)[2] = *(p[1] + 2) = *(*(p + 1) + 2) = 100
    system("pause");
    return 0;
}
