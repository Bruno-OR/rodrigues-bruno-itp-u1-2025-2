#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, i, j, difAB, difBA;
    int somaA = 0, somaB = 0;

    printf("\nDigite o primeiro número: ");
    scanf("%d", &a);
    printf("\nDigite o segundo número: ");
    scanf("%d", &b);

    while (a == b)
    {
        printf("\nPor favor, digite números diferentes: ");
        printf("\nDigite o primeiro número: ");
        scanf("%d", &a);
        printf("\nDigite o segundo número: ");
        scanf("%d", &b);
    }

    for (i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            somaA += i;
        }
    }
    printf("\n");

    for (j = 1; j < b; j++)
    {
        if (b % j == 0)
        {
            somaB += j;
        }
    }

    difAB = somaA - b;
    difBA = somaB - a;

    if (difAB <= 2 && difBA <= 2)
    {
        printf("S");
    }
    else
    {
        printf("N");
    }

    return 0;
}
