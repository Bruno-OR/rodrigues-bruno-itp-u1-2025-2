#include <stdio.h>
#include <stdlib.h> // Para a função abs()

int main() {
    

    int q1, q2, q3, q4; 
    int solucao_count = 0;

    printf("Soluções para o problema das 4 rainhas:\n");

    
    for (q1 = 0; q1 < 4; q1++) {
        
        for (q2 = 0; q2 < 4; q2++) {
            
            if (q1 == q2 || abs(q1 - q2) == abs(0 - 1)) {
                continue; 
            }

            
            for (q3 = 0; q3 < 4; q3++) {
                
                if (q3 == q1 || abs(q3 - q1) == abs(0 - 2) ||
                    q3 == q2 || abs(q3 - q2) == abs(1 - 2)) {
                    continue;
                }

                
                for (q4 = 0; q4 < 4; q4++) {
                    
                    if (q4 == q1 || abs(q4 - q1) == abs(0 - 3) ||
                        q4 == q2 || abs(q4 - q2) == abs(1 - 3) ||
                        q4 == q3 || abs(q4 - q3) == abs(2 - 3)) {
                        continue;
                    }

                    
                    solucao_count++;
                    printf("\nSolucao #%d:\n", solucao_count);
                    
                    // Imprime o tabuleiro (Bônus para visualização)
                    for (int linha = 0; linha < 4; linha++) {
                        for (int coluna = 0; coluna < 4; coluna++) {
                            if ((coluna == 0 && linha == q1) ||
                                (coluna == 1 && linha == q2) ||
                                (coluna == 2 && linha == q3) ||
                                (coluna == 3 && linha == q4)) {
                                printf(" Q ");
                            } else {
                                printf(" . ");
                            }
                        }
                        printf("\n");
                    }
                }
            }
        }
    }

    if (solucao_count == 0) {
        printf("Nenhuma solucao encontrada.\n");
    }

    return 0;
}