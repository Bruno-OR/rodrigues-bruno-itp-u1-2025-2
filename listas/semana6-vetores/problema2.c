#include <stdio.h>

void checklist(int vetor[], int m, int n);

int main()
{
    int m, n;

    int album_checklist[1000];
    printf("Digite o total de figurinhas no álbum e a quantidade possuída, respectivamente: ");
    scanf("%d %d", &m, &n);

    checklist(album_checklist, m, n);

    return 0;
}

void checklist(int vetor[], int m, int n)
{

    for (int i = 1; i <= m; i++)
    {
        vetor[i] = 0;
    }

    printf("Digite as figurinhas que possui: ");
    for (int i = 0; i < n; i++)
    {
        int figurinha_possuida;
        scanf("%d", &figurinha_possuida);

        if (figurinha_possuida >= 1 && figurinha_possuida <= m)
        {
            vetor[figurinha_possuida] = 1;
        }
    }
    printf("As figurinhas faltantes são: ");
    for (int i = 1; i <= m; i++)
    {
        if (vetor[i] == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}