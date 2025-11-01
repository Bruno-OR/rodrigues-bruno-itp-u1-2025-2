#include <stdio.h>
#include <stdlib.h> // Para malloc() e free()


int* buscaNoVetor(int *v, int n, int valor, int *qtd) {
    int i;
    int count = 0; // Contador para as ocorrências

    //Primeira Passagem: Contar as ocorrências
    for (i = 0; i < n; i++) {
        if (v[i] == valor) {
            count++;
        }
    }

    // Armazena a contagem no endereço apontado por qtd
    *qtd = count;

    // Se nenhuma ocorrência foi encontrada, retorna NULL
    if (count == 0) {
        return NULL;
    }

    //Alocar memória para o vetor de índices
    int *indices = (int *) malloc(count * sizeof(int));

    // Verifica se a alocação falhou
    if (indices == NULL) {
        *qtd = 0; //Zera a quantidade para indicar erro
        return NULL;
    }

    //Segunda Passagem: Preencher o vetor de índices
    int index_count = 0; // Índice para o vetor 'indices'
    for (i = 0; i < n; i++) {
        if (v[i] == valor) {
            indices[index_count] = i;
            index_count++;
        }
    }

    // Retorna o ponteiro para o vetor de índices
    return indices;
}

int main() {

    int n, valor_buscado, quantidade_ocorrencias = 0;
    int *vetor_principal = NULL;
    int *indices_encontrados = NULL;
    int i;

    //Lê o tamanho do vetor principal
    scanf("%d", &n);

    //Aloca dinamicamente o vetor principal
    vetor_principal = (int *) malloc(n * sizeof(int));
    if (vetor_principal == NULL) {
        printf("Erro: Falha ao alocar memória para o vetor principal.\n");
        return 1;
    }

    //Lê os n elementos do vetor principal
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor_principal[i]);
    }

    //Lê o valor a ser buscado
    scanf("%d", &valor_buscado);

    //Chama a função de busca
    // Passa o endereço de 'quantidade_ocorrencias' para que a função possa modificá-la
    indices_encontrados = buscaNoVetor(vetor_principal, n, valor_buscado, &quantidade_ocorrencias);

    //Imprime o resultado
    if (indices_encontrados == NULL) {
        // Verifica se foi por falta de ocorrências ou erro de alocação
        if (quantidade_ocorrencias == 0) {
             printf("Nenhuma ocorrencia\n");
        } else {
            // Se qtd != 0 mas o ponteiro é NULL, houve erro de alocação na busca
             printf("Erro: Falha ao alocar memória para os índices.\n");
        }
    } else {
        // Imprime a quantidade
        printf("%d\n", quantidade_ocorrencias);
        // Imprime os índices encontrados
        for (i = 0; i < quantidade_ocorrencias; i++) {
            printf("%d ", indices_encontrados[i]);
        }
        printf("\n");
    }

    // 7. Libera a memória alocada
    free(vetor_principal);
    free(indices_encontrados); // free(NULL) é seguro

    return 0;
}
