#include <stdio.h>
#include <stdlib.h> // Para malloc() e free()
#include <string.h> // Para strlen()

char *misturar(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len_total = len1 + len2;
    char *resultado;
    int i = 0, j = 0, k = 0; // i para str1, j para str2, k para resultado

    // Aloca memória para a string resultado (+1 para o '\0')
    resultado = (char *)malloc((len_total + 1) * sizeof(char));
    if (resultado == NULL)
    {
        printf("Erro: Falha ao alocar memória.\n");
        return NULL; // Retorna NULL em caso de erro
    }

    // Alterna os caracteres enquanto ambas as strings tiverem caracteres
    while (i < len1 && j < len2)
    {
        resultado[k++] = str1[i++];
        resultado[k++] = str2[j++];
    }

    // Adiciona o restante da string mais longa se houver
    // Se str1 for mais longa
    while (i < len1)
    {
        resultado[k++] = str1[i++];
    }
    // Se str2 for mais longa
    while (j < len2)
    {
        resultado[k++] = str2[j++];
    }

    // Adiciona o caractere nulo terminador
    resultado[k] = '\0';

    // Retorna o ponteiro para a string resultado
    return resultado;
}

int main()
{

    // Buffers para ler as strings (100 chars + '\n' + '\0')
    char str1[102];
    char str2[102];
    char *string_misturada = NULL;

    // Lê a primeira string (permitindo espaços)
    printf("Digite a primeira string (até 100 caracteres): ");
    fgets(str1, sizeof(str1), stdin);
    // Remove a quebra de linha ('\n') que fgets pode adicionar
    str1[strcspn(str1, "\n")] = '\0';

    // Lê a segunda string
    printf("Digite a segunda string (até 100 caracteres): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // Chama a função para misturar as strings
    string_misturada = misturar(str1, str2);

    // Verifica se a mistura foi bem-sucedida e imprime o resultado
    if (string_misturada != NULL)
    {
        printf("%s\n", string_misturada);

        // Libera a memória alocada dinamicamente pela função misturar
        free(string_misturada);
    }

    return 0;
}
