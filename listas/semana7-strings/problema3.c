#include <stdio.h>
#include <string.h> // Para strlen(), strcmp() e strtok()

// Função para identificar as datas.
// Retorna 1 se for uma data (formato DD/MM), 0 caso contrário.
int ehData(char *palavra)
{
    if (strlen(palavra) == 5 && palavra[2] == '/')
    {
        return 1;
    }
    return 0;
}

int main()
{

    char aluno_procurado[11];
    char linha_frequencias[1002];

    int total_aulas = 0;
    int presencas = 0;
    int encontrou_aluno_nesta_aula = 0;

    scanf("%s", aluno_procurado);
    getchar(); // Limpa o buffer de entrada

    // 2. Lê a linha inteira de frequências
    fgets(linha_frequencias, sizeof(linha_frequencias), stdin);

    char palavra_atual[1001];
    int j = 0; // Índice para a palavra_atual

    for (int i = 0; i < strlen(linha_frequencias); i++)
    {
        // Se o caractere não for um espaço ou quebra de linha, adiciona à palavra atual
        if (linha_frequencias[i] != ' ' && linha_frequencias[i] != '\n')
        {
            palavra_atual[j] = linha_frequencias[i];
            j++;
        }
        else
        {
            // Se for um espaço ou quebra de linha, a palavra terminou.
            if (j > 0)
            {                            // Garante que não temos "palavras" vazias
                palavra_atual[j] = '\0'; // Finaliza a string da palavra atual

                // Verifica se é data, se for, soma as aulas e reseta a presença do aluno
                if (ehData(palavra_atual))
                {
                    total_aulas++;
                    encontrou_aluno_nesta_aula = 0;
                }
                else
                { // Compara o nome do aluno procurado com a palavra atual e se a presença dele ainda não tiver sido contada, entra nessa condição
                    if (strcmp(palavra_atual, aluno_procurado) == 0 && encontrou_aluno_nesta_aula == 0)
                    {
                        presencas++;
                        encontrou_aluno_nesta_aula = 1;
                    }
                }

                j = 0; // Reseta o índice para a próxima palavra
            }
        }
    }

    int ausencias = total_aulas - presencas;
    printf("%d\n", ausencias);

    return 0;
}
