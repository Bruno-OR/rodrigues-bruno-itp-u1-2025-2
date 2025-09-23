#include <stdio.h>

int main()
{
    float largura, comprimento, bolso;

    printf("\nQual o comprimento da folha? ");
    scanf("%f", &comprimento);

    printf("\nQual a largura da folha? ");
    scanf("%f", &largura);

    printf("\nQual o comprimento do bolso? ");
    scanf("%f", &bolso);

    int qtdeDobras = 0;

    while ((largura > bolso && comprimento > bolso))
    {

        if (comprimento > largura)
        {
            comprimento = comprimento / 2;
        }
        else
        {
            largura = largura / 2;
        }

        qtdeDobras += 1;
    }

    printf("\nForam necessárias %d dobras para a folha caber no bolso", qtdeDobras);

    return 0;
}
