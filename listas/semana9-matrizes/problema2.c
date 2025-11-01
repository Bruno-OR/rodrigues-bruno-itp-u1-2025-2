#include <stdio.h>

int main()
{

    int M, x; // M = número de usuários, x = usuário alvo
    int i, j;
    int amizades[100][100];

    // Lê a dimensão da matriz (número de usuários)
    scanf("%d", &M);

    // Lê a matriz de amizades
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &amizades[i][j]);
        }
    }

    // Lê o ID do usuário que tera as sugestões
    scanf("%d", &x);

    // Lógica para encontrar e imprimir as sugestões
    //  O laço externo percorre todos os usuários para ver se podem ser uma sugestão
    for (int potencial_amigo = 0; potencial_amigo < M; potencial_amigo++)
    {

        // Condição 1: Não pode ser o próprio usuário e não podem ser amigos
        if (potencial_amigo != x && amizades[x][potencial_amigo] == 0)
        {

            // Se não são amigos, procura por um amigo em comum
            int tem_amigo_comum = 0; // Flag de controle

            // O laço interno percorre todos os usuários para ver se algum é amigo em comum
            for (int amigo_em_comum = 0; amigo_em_comum < M; amigo_em_comum++)
            {

                // Verifica se o amigo_em_comum é amigo de AMBOS
                if (amizades[x][amigo_em_comum] == 1 && amizades[potencial_amigo][amigo_em_comum] == 1)
                {
                    tem_amigo_comum = 1;
                    break; // Se encontrou 1, para
                }
            }

            // Se, após a busca, encontrar um amigo em comum, imprime a sugestão
            if (tem_amigo_comum == 1)
            {
                printf("%d ", potencial_amigo);
            }
        }
    }

    printf("\n");

    return 0;
}
