#include <stdio.h>

int main()
{

    int n; // Quantidade de pilotos
    int i;
    int piloto_id;

    // Vetores para mapear o ID do piloto à sua posição.
    // Tamanho n+1 para usar o ID do piloto (1 a n) como índice
    int pos_largada[21];
    int pos_chegada[21];

    // Lê a quantidade de pilotos
    scanf("%d", &n);

    // Lê a ordem de largada e preenche o mapa de posições de largada
    //  Se o piloto #5 largou na primeira posição (i = 0), pos_largada[5] = 0.
    for (i = 0; i < n; i++)
    {
        scanf("%d", &piloto_id);
        pos_largada[piloto_id] = i;
    }

    // Lê a ordem de chegada e preenche o mapa de posições de chegada
    for (i = 0; i < n; i++)
    {
        scanf("%d", &piloto_id);
        pos_chegada[piloto_id] = i;
    }

    // Encontra o piloto com o maior ganho de posições
    int max_ganho = 0;
    int piloto_vencedor = -1;
    int houve_empate = 0;

    // Percorre cada piloto de 1 até n
    for (i = 1; i <= n; i++)
    {
        // Ganho = Posição de largada - Posição de chegada
        int ganho = pos_largada[i] - pos_chegada[i];

        if (ganho > max_ganho)
        {
            max_ganho = ganho;
            piloto_vencedor = i;
            houve_empate = 0;
        }
        else if (ganho == max_ganho && max_ganho > 0)
        {
            // Se o ganho for igual ao máximo atual (e maior que zero), então houve empate.
            houve_empate = 1;
        }
    }

    // Se houve empate OU se o maior ganho foi zero ou negativo
    if (houve_empate || max_ganho <= 0)
    {
        printf("empate\n");
    }
    else
    {
        printf("%d\n", piloto_vencedor);
    }

    return 0;
}
