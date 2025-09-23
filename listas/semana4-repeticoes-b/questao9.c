#include <stdio.h>

int main()
{

    float preco1, preco2;
    float quantia_disponivel;
    int qtd1, qtd2;

    float menor_resto;
    int melhor_qtd1 = 0;
    int melhor_qtd2 = 0;

    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%f", &preco1);

    printf("Digite o preco do segundo fornecedor: ");
    scanf("%f", &preco2);

    printf("Digite a quantia disponivel: ");
    scanf("%f", &quantia_disponivel);

    menor_resto = quantia_disponivel;

    for (qtd1 = 0; qtd1 <= 10; qtd1++)
    {
        for (qtd2 = 0; qtd2 <= 10; qtd2++)
        {

            float custo_total = (qtd1 * preco1) + (qtd2 * preco2);

            if (custo_total <= quantia_disponivel)
            {
                float resto_atual = quantia_disponivel - custo_total;

                if (resto_atual < menor_resto)
                {

                    menor_resto = resto_atual;
                    melhor_qtd1 = qtd1;
                    melhor_qtd2 = qtd2;
                }
            }
        }
    }

    printf("\n");
    printf("Resta menos comprando %d do primeiro e %d do segundo\n", melhor_qtd1, melhor_qtd2);

    return 0;
}