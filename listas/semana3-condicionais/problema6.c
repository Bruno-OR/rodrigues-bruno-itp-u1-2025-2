#include <stdio.h>
#include <ctype.h>

int main()

{

    char febre, cabeca, corpo, tosse;

    printf("\n-------------Perguntas-------------\n\n");

    printf("Digite S para Sim ou N para Não.\n");

    printf("\nTem febre? ");
    scanf(" %c", &febre);

    printf("Tem dor de cabeça? ");
    scanf(" %c", &cabeca);

    printf("Tem dor no corpo? ");
    scanf(" %c", &corpo);

    printf("Tem tosse? ");
    scanf(" %c", &tosse);

    febre = toupper(febre);
    cabeca = toupper(cabeca);
    corpo = toupper(corpo);
    tosse = toupper(tosse);

    printf("\n\n-------------Diagnóstico-------------\n\n");

    if (febre == 'S' && cabeca == 'S' && corpo == 'S' && tosse == 'N')
    {
        printf("Possível gripe.\n");
    }
    else if (febre == 'S' && cabeca == 'N' && corpo == 'N' && tosse == 'S')
    {
        printf("Possível resfriado.\n");
    }
    else if (febre == 'N' && cabeca == 'S' && corpo == 'N' && tosse == 'N')
    {
        printf("Possível enxaqueca.\n");
    }
    else if (febre == 'S' && cabeca == 'N' && corpo == 'N' && tosse == 'N')
    {
        printf("Consulte um médico.\n");
    }
    else if (febre == 'N' && cabeca == 'N' && corpo == 'N' && tosse == 'N')
    {
        printf("Você parece estar bem!\n");
    }
    else
    {
        printf("Consulte um médico para avaliação!\n");
    }
    printf("\n-------------------------------------\n\n");
    return 0;
}