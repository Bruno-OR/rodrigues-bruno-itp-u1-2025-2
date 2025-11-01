#include <stdio.h>

int main()
{

    int M, N; // Dimensões da matriz (Linhas e Colunas)
    int i, j;

    int campo[10][10];
    // Matriz de controle para marcar os setores já irrigados e contados
    int irrigado[10][10] = {0};

    int total_ferteis = 0;
    int irrigados_contados = 0;

    // Lê as dimensões da matriz
    scanf("%d %d", &M, &N);

    // Lê os dados do campo e já conta o total de setores férteis
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &campo[i][j]);
            if (campo[i][j] == 1)
            {
                total_ferteis++;
            }
        }
    }

    // Percorre a matriz para encontrar os irrigadores
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            // Se encontrar um irrigador (valor 2) verifica os 4 vizinhos (Norte, Sul, Leste, Oeste)
            if (campo[i][j] == 2)
            {

                // Vizinho Norte (i-1, j)
                if (campo[i - 1][j] == 1 && irrigado[i - 1][j] == 0)
                {
                    irrigados_contados++;
                    irrigado[i - 1][j] = 1; // Marca como já contado
                }

                // Vizinho Sul (i+1, j)
                if (campo[i + 1][j] == 1 && irrigado[i + 1][j] == 0)
                {
                    irrigados_contados++;
                    irrigado[i + 1][j] = 1;
                }

                // Vizinho Oeste (i, j-1)
                if (campo[i][j - 1] == 1 && irrigado[i][j - 1] == 0)
                {
                    irrigados_contados++;
                    irrigado[i][j - 1] = 1;
                }

                // Vizinho Leste (i, j+1)
                if (campo[i][j + 1] == 1 && irrigado[i][j + 1] == 0)
                {
                    irrigados_contados++;
                    irrigado[i][j + 1] = 1;
                }
            }
        }
    }

    // Calcula os setores férteis não irrigados
    int nao_irrigados = total_ferteis - irrigados_contados;

    printf("%d %d\n", irrigados_contados, nao_irrigados);

    return 0;
}
