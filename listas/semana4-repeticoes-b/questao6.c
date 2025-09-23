#include <stdio.h>

int main()
{

    int a, b, c, contador = 0;

    printf("Trios pitagóricos com o maior número menor que 1000:\n");

    for (c = 1; c < 1000; c++)
    {

        for (b = 1; b < c; b++)
        {

            for (a = 1; a <= b; a++)
            {

                if ((a * a) + (b * b) == (c * c))
                {   
                    printf("(%d, %d, %d)\n", a, b, c);
                    contador++;
                }
            }
        }
    }

    printf("\nTotal de trios encontrados: %d\n", contador);
    return 0;
}