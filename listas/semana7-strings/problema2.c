#include <stdio.h>
#include <string.h> // Para a função strlen()
#include <ctype.h>  // Para as funções isupper() e isdigit()


int main() {
    char placa[11];
    printf("Digite a placa: \n");
    scanf("%s", placa);

    int tamanho = strlen(placa);
    int i;

    
    // Verifica se o tamanho é 7 ou 8. Se não for, já é inválido.
    if (tamanho != 7 && tamanho != 8) {
        printf("inválido\n");
        return 0; // Termina o programa
    }

    // Verifica as 3 primeiras letras (comum a ambos os padrões)
    for (i = 0; i < 3; i++) {
        if (!isupper(placa[i])) {
            printf("inválido\n");
            return 0; // Se encontrar erro, termina o programa
        }
    }

    // Caso as 3 primeiras letras forem maiúsculas, verificamos se é brasileiro ou inválido ou se é mercosul ou inválido.

    if (tamanho == 8) { // Padrão brasileiro
        int eh_brasileiro_valido = 1; // Flag para controlar a validade

        if (placa[3] != '-') {
            eh_brasileiro_valido = 0;
        }

        for (i = 4; i < 8; i++) {
            if (!isdigit(placa[i])) {
                eh_brasileiro_valido = 0;
                break;
            }
        }

        if (eh_brasileiro_valido) {
            printf("brasileiro\n");
        } else {
            printf("inválido\n");
        }

    } else { // Verificação dos 4 últimos caracteres para o Mercosul
        if (isdigit(placa[3]) &&
            isupper(placa[4]) &&
            isdigit(placa[5]) &&
            isdigit(placa[6])) {
            printf("mercosul\n");
        } else {
            printf("inválido");
        }
    }
}

