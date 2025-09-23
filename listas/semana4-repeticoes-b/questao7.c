#include <stdio.h>

int main()
{
    int a, b, i, j, cont;
    printf("\nDigite a: ");
    scanf("%d", &a);
    printf("\nDigite b: ");
    scanf("%d", &b);

    while (a <= b)
    {
        printf("\nErro: 'a' deve ser maior que 'b'. Tente novamente.\n");
        printf("\nDigite a: ");
        scanf("%d", &a);
        printf("\nDigite b: ");
        scanf("%d", &b);
    }

    printf("\nNúmeros primos entre %d e %d:\n", b, a);

    for (i = b; i <= a; i++)
    {

        if (i < 2)
        {
            continue;
        }

        cont = 0;

            for (j = 1; j <= i; j++)
            {
                if (i % j == 0)
                {
                    cont++;
                }
            }

        if (cont == 2)
        {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}