#include <stdio.h>
#include <string.h> // Para usar a função strlen()

int main() {
    
    char campo[21]; // Vetor para a palavra com 21 posições (20 caracteres + 1 para o terminador '\0')
    int indice;
    int tamanho_palavra;
    
    printf("Digite o campo (com '.' e 'x'): ");
    scanf("%s", campo);

    printf("Digite o índice a ser verificado: ");
    scanf("%d", &indice);

    
    tamanho_palavra = strlen(campo); // Para pegar o tamanho do campo

    // Validação para garantir que o índice digitado é válido
    if (indice < 0 || indice >= tamanho_palavra) {
        printf("Índice inválido!\n");
        return 1; // Termina o programa com erro
    }

    // Verifica se a posição escolhida é uma bomba
    if (campo[indice] == 'x') {
        printf("bum!\n");
    } else {
        // Se não for uma bomba, conta as bombas adjacentes
        int bombas_adjacentes = 0;

        // Verifica a posição à esquerda e soma +1 se houver bomba
        if (indice > 0 && campo[indice - 1] == 'x') {
            bombas_adjacentes++;
        }

        // Verifica a posição à direita e soma +1 se houver bomba
        if (indice < tamanho_palavra - 1 && campo[indice + 1] == 'x') {
            bombas_adjacentes++;
        }

        printf("%d\n", bombas_adjacentes); // imprime a quantidade de bombas adjacentes
    }

    return 0;
}

    
