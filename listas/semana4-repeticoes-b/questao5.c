#include <stdio.h>

int main()
{

    int n, i, j, contador = 1;

    printf(" Digite um valor para n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", contador);
            contador++;
        }

        printf("\n");
    }
    return 0;
}
