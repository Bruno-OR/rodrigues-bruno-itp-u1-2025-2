#include <stdio.h>

int main() {

    int m, n; 
    int i, j;
    int acertos = 0;
    int sorteados[30];
    int aposta[50];

    // Números sorteados (m) e apostados (n)
    scanf("%d %d", &m, &n);

    //Lê os m números sorteados e armazena no vetor 'sorteados'
    for (i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }

    //Lê os n números da aposta e armazena no vetor 'aposta'
    for (i = 0; i < n; i++) {
        scanf("%d", &aposta[i]);
    }

    //Compara os vetores para contar os acertos
    for (i = 0; i < n; i++) {
        //percorre todos os números que foram sorteados.
        for (j = 0; j < m; j++) {
            // Se o número da aposta for igual a um dos números sorteados incrementa o contador de acertos ee para de procurar, pois já encontrou o par.
            if (aposta[i] == sorteados[j]) {
                acertos++; 
                break;     
            }
        }
    }
    printf("%d\n", acertos);

    return 0;
}
