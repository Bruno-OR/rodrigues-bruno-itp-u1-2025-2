#include <stdio.h>

int main()
{

    int M, X, Z;
    int i, y;
    int precos[10][10];

    int melhor_custo = 0; // Inicializa com 0
    int cidade_intermediaria = -1;
    int rota_encontrada = 0; // Flag: 0 = nenhuma rota válida encontrada ainda, 1 = já encontrada

    scanf("%d", &M);

    for (i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &precos[i][j]);
        }
    }

    scanf("%d %d", &X, &Z);

    // Verifica o custo da rota direta
    if (precos[X][Z] != 0)
    {
        melhor_custo = precos[X][Z];
        rota_encontrada = 1;       // Marca que o encontro da primeira rota válida
        cidade_intermediaria = -1; // Rota direta é a melhor por enquanto
    }

    // Verifica rotas com uma cidade intermediária
    for (y = 0; y < M; y++)
    {
        if (y == X || y == Z)
        {
            continue;
        }

        if (precos[X][y] != 0 && precos[y][Z] != 0)
        {
            int custo_atual = precos[X][y] + precos[y][Z];

            // Se ainda não tinha nenhuma rota ou se a rota atual é mais barata
            if (rota_encontrada == 0 || custo_atual < melhor_custo)
            {
                melhor_custo = custo_atual;
                cidade_intermediaria = y;
                rota_encontrada = 1; // Marca que foi encontrada uma rota válida ou atualiza a melhor
            }
        }
    }

    if (cidade_intermediaria == -1)
    {
        printf("%d-%d R$%d\n", X, Z, melhor_custo);
    }
    else
    {
        printf("%d-%d-%d R$%d\n", X, cidade_intermediaria, Z, melhor_custo);
    }

    return 0;
}
