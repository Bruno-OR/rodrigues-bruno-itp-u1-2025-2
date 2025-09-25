#include <stdio.h>

void lerRespostas(int vetor[], int tamanho, char tipo[]);
int contarAcertos(int gabarito[], int respostas[], int tamanho);
void imprimirResultado(int acertos);

int main()
{

    int n_questoes;
    int i;
    int acertos = 0;

    int gabarito[20];
    int respostas[20];

    printf("Digite a quantidade de questões (1 a 20): ");
    scanf("%d", &n_questoes);

    if (n_questoes < 1 || n_questoes > 20)
    {
        printf("Número de questões inválido.\n");
        return 1;
    }

    lerRespostas(gabarito, n_questoes, "gabarito");
    lerRespostas(respostas, n_questoes, "aluno");
    acertos = contarAcertos(gabarito, respostas, n_questoes);
    imprimirResultado(acertos);

    return 0;
}

void lerRespostas(int vetor[], int tamanho, char tipo[])
{

    printf("Digite as %d respostas do %s: ", tamanho, tipo);

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

int contarAcertos(int gabarito[], int respostas[], int tamanho)
{

    int acertos = 0;

    for (int i = 0; i < tamanho; i++)
    {

        if (gabarito[i] == respostas[i])
        {
            acertos++;
        }
    }

    return acertos;
}

void imprimirResultado(int acertos)
{
    printf("\n");
    if (acertos == 1)
    {
        printf("%d acerto\n", acertos);
    }
    else
    {
        printf("%d acertos\n", acertos);
    }
}