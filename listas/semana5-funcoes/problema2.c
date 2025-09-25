#include <stdio.h>

int ehPrimo(int numero)
{

    if (numero < 2)
    {
        return 0;
    }

    for (int i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{

    int x;
    const int LIMITE = 50000;

    printf("Procurando por trios de primos (x, x+2, x+6) ate %d:\n", LIMITE);

    for (x = 1; x <= LIMITE; x++)
    {

        if (ehPrimo(x) && ehPrimo(x + 2) && ehPrimo(x + 6))
        {

            printf("(%d, %d, %d)\n", x, x + 2, x + 6);
        }
    }

    return 0;
}