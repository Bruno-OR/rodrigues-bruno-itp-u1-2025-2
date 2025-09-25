#include <stdio.h>

int main()
{

    int n, terreno[30], i, comprimento_ponte;
    int altura_maxima = 0;

    printf("Digite o número de pontos: ");
    scanf("%d", &n);

    printf("Digite as alturas: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &terreno[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (terreno[i] > altura_maxima)
        {
            altura_maxima = terreno[i];
        }
    }

    int indice1 = -1;
    int indice2 = -1;

    for (i = 0; i < n; i++)
    {
        if (terreno[i] == altura_maxima)
        {
            if (indice1 == -1)
            {
                indice1 = i;
            }
            else
            {
                indice2 = i;
            }
        }
    }

    comprimento_ponte = indice2 - indice1 - 1;

    printf("A ponte terá comprimento igual a %d \n", comprimento_ponte);

    return 0;
}