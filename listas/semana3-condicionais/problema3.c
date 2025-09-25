#include <stdio.h>

int main()

{
    float nota1, nota2, nota3, media;

    printf("\nDigite a primeira nota: ");
    scanf("%f", &nota1);

    printf("\nDigite a segunda nota: ");
    scanf("%f", &nota2);

    printf("\nDigite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("\n----------------RESULTADO----------------\n");

    if (media >= 7)
    {
        printf("\nAluno Aprovado");
    }
    else if (media < 4)
    {
        printf("\nAluno Reprovado");
    }
    else
    {
        printf("\nAluno em Recuperação");
    }

    printf("\nMédia final: %.1f\n\n", media);
    printf("----------------------------------------\n\n");

    return 0;
}