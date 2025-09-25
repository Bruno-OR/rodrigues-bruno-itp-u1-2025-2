#include <stdio.h>

int main()
{

    float preco1, preco2;
    float quantia_disponivel;
    int qtd1, qtd2;

    printf("Digite o preço do primeiro fornecedor: ");
    scanf("%f", &preco1);

    printf("Digite o preço do segundo fornecedor: ");
    scanf("%f", &preco2);

    printf("Digite a quantia disponível: ");
    scanf("%f", &quantia_disponivel);

    printf("\n--- Verificando todas as possibilidades de compra ---\n\n");

    for (qtd1 = 0; qtd1 <= 10; qtd1++)
    {

        for (qtd2 = 0; qtd2 <= 10; qtd2++)
        {

            float custo_total = (qtd1 * preco1) + (qtd2 * preco2);

            if (custo_total <= quantia_disponivel)
            {
                float resto = quantia_disponivel - custo_total;

                printf("Comprando %d do primeiro e %d do segundo resta: R$ %.2f\n", qtd1, qtd2, resto);
            }
        }
    }

    return 0;
}