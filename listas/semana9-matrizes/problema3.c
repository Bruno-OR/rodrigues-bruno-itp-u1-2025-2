#include <stdio.h>

int main()
{

    int M; // Número de times
    int i, j;
    int resultados[20][20];
    int empates = 0;

    // Lê a dimensão da matriz (número de times)
    scanf("%d", &M);

    // Lê a matriz de resultados
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &resultados[i][j]);
        }
    }

    // Conta o número de empates
    //  Percorre apenas a parte superior da matriz (acima da diagonal principal) para verificar cada partida uma única vez.
    for (i = 0; i < M; i++)
    {
        // Começa j de i+1 para evitar a diagonal e a parte inferior
        for (j = i + 1; j < M; j++)
        {
            // Verifica se os gols marcados por i contra j são iguais aos marcados por j contra i
            if (resultados[i][j] == resultados[j][i])
            {
                empates++;
            }
        }
    }

    printf("%d\n", empates);

    return 0;
}
