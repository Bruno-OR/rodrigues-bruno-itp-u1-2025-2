#include <stdio.h>

// Função para imprimir o nome do mês com base no índice (0-11)
void imprimeNomeDoMes(int indice_mes)
{
    switch (indice_mes)
    {
    case 0:
        printf("Janeiro ");
        break;
    case 1:
        printf("Fevereiro ");
        break;
    case 2:
        printf("Marco ");
        break;
    case 3:
        printf("Abril ");
        break;
    case 4:
        printf("Maio ");
        break;
    case 5:
        printf("Junho ");
        break;
    case 6:
        printf("Julho ");
        break;
    case 7:
        printf("Agosto ");
        break;
    case 8:
        printf("Setembro ");
        break;
    case 9:
        printf("Outubro ");
        break;
    case 10:
        printf("Novembro ");
        break;
    case 11:
        printf("Dezembro ");
        break;
    }
}

int main()
{

    const int NUM_MESES = 12;
    int chuvas[NUM_MESES];
    int indices_meses[NUM_MESES];
    int i, j;

    // Lê os 12 valores de chuva
    for (i = 0; i < NUM_MESES; i++)
    {
        scanf("%d", &chuvas[i]);
        indices_meses[i] = i;
    }

    // Ordena os dados usando Selection Sort (do maior para o menor)
    for (i = 0; i < NUM_MESES - 1; i++)
    {
        int max_idx = i;
        for (j = i + 1; j < NUM_MESES; j++)
        {
            if (chuvas[j] > chuvas[max_idx])
            {
                max_idx = j;
            }
        }

        // Troca a quantidade de chuva
        int temp_chuva = chuvas[max_idx];
        chuvas[max_idx] = chuvas[i];
        chuvas[i] = temp_chuva;

        // Troca o índice do mês correspondente
        int temp_indice = indices_meses[max_idx];
        indices_meses[max_idx] = indices_meses[i];
        indices_meses[i] = temp_indice;
    }

    // Imprime o ranking ordenado
    for (i = 0; i < NUM_MESES; i++)
    {
        // Usa uma função com switch case para imprimir o nome do mês
        imprimeNomeDoMes(indices_meses[i]);
        printf("%d\n", chuvas[i]);
    }

    return 0;
}
