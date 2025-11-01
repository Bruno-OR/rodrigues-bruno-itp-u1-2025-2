#include <stdio.h>
#include <stdlib.h> // Para malloc() e free()

int *alocarVetor(int n)
{
    int *vetor;
    // Aloca memória para 'n' inteiros
    vetor = (int *)malloc(n * sizeof(int));

    // Retorna o ponteiro (pode ser NULL se malloc falhar)
    return vetor;
}

int *somaVetores(int *u, int *v, int n)
{
    int *soma;
    int i;

    // Aloca memória para o vetor de resultado
    soma = alocarVetor(n);

    // Verifica se a alocação do vetor 'soma' foi bem sucedida
    if (soma == NULL)
    {
        return NULL; // Retorna NULL se não conseguiu alocar memória
    }

    // Calcula a soma elemento a elemento
    for (i = 0; i < n; i++)
    {
        soma[i] = u[i] + v[i];
    }

    // Retorna o ponteiro para o vetor com a soma
    return soma;
}

int main()
{

    int n1, n2;
    int *u = NULL, *v = NULL, *resultado = NULL; // Inicializa ponteiros como NULL
    int i;

    // Lê os tamanhos dos vetores
    scanf("%d %d", &n1, &n2);

    // Verifica se os tamanhos são compatíveis
    if (n1 != n2)
    {
        // Lê os elementos apenas para limpar a entrada, mas não os armazena
        for (i = 0; i < n1; i++)
        {
            scanf("%*d");
        } // %*d lê e descarta o inteiro
        for (i = 0; i < n2; i++)
        {
            scanf("%*d");
        }
        printf("dimensoes incompativeis\n");
    }
    else
    {
        // Aloca os vetores u e v
        u = alocarVetor(n1);
        v = alocarVetor(n2); // n2 é igual a n1

        // Verifica se a alocação falhou
        if (u == NULL || v == NULL)
        {
            printf("Erro: Falha ao alocar memória para os vetores de entrada.\n");
            // Libera a memória que pode ter sido alocada antes de sair
            free(u);
            free(v);
            return 1; // Termina com erro
        }

        // Lê os elementos dos vetores u e v
        for (i = 0; i < n1; i++)
        {
            scanf("%d", &u[i]);
        }
        for (i = 0; i < n2; i++)
        {
            scanf("%d", &v[i]);
        }

        // Calcula a soma
        resultado = somaVetores(u, v, n1);

        // Verifica se a alocação do resultado falhou
        if (resultado == NULL)
        {
            printf("Erro: Falha ao alocar memória para o vetor de resultado.\n");
            free(u);
            free(v);
            return 1; // Termina com erro
        }

        // Imprime o vetor resultante
        for (i = 0; i < n1; i++)
        {
            printf("%d ", resultado[i]);
        }
        printf("\n");

        // Libera a memória do vetor resultado
        free(resultado);
    }

    // Libera a memória dos vetores de entrada se foram alocados
    free(u);
    free(v);

    return 0;
}
