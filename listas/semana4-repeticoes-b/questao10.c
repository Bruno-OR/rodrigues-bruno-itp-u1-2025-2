#include <stdio.h>

int main()
{

    float p;
    float q;
    int x, y;

    float maior_razao = 1.0;
    int melhor_x = 0;
    int melhor_y = 0;

    printf("Digite o preco de venda p: ");
    scanf("%f", &p);

    printf("Digite o preco de producao q: ");
    scanf("%f", &q);

    for (x = 2; x <= 10; x++)
    {

        for (y = 1; y < x; y++)
        {

            if ((y * p) >= (x * q))
            {

                float razao_atual = (float)x / y;

                if (razao_atual > maior_razao)
                {

                    maior_razao = razao_atual;
                    melhor_x = x;
                    melhor_y = y;
                }
            }
        }
    }

    printf("\n");
    if (melhor_x > 0)
    {
        printf("A melhor promocao eh: leve %d pague %d\n", melhor_x, melhor_y);
    }
    else
    {
        printf("Nenhuma promocao vantajosa sem prejuizo foi encontrada.\n");
    }

    return 0;
}