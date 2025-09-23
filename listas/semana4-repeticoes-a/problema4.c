#include <stdio.h>
#include <math.h>

int main()
{

    float x_atual, y_atual;
    float x_anterior = 0, y_anterior = 0;
    float pontuacao_total = 0.0;
    const int NUMERO_DE_LANCAMENTOS = 10;

    printf("--- Jogo de Dardos Inovador ---\n");
    printf("Digite as coordenadas (x y) para cada um dos %d lançamentos.\n\n", NUMERO_DE_LANCAMENTOS);

    for (int i = 1; i <= NUMERO_DE_LANCAMENTOS; i++)
    {
        printf("Coordenadas do lançamento %d: ", i);
        scanf("%f %f", &x_atual, &y_atual);

        float distancia_alvo = sqrt(pow(x_atual, 2) + pow(y_atual, 2));

        if (distancia_alvo <= 1.0)
        {
            pontuacao_total += 10;
        }
        else if (distancia_alvo <= 2.0)
        {
            pontuacao_total += 6;
        }
        else if (distancia_alvo <= 3.0)
        {
            pontuacao_total += 4;
        }

        if (i > 1)
        {
            float distancia_anterior = sqrt(pow(x_atual - x_anterior, 2) + pow(y_atual - y_anterior, 2));

            if (distancia_anterior <= 1.0)
            {
                pontuacao_total += 5;
            }
            else if (distancia_anterior <= 2.0)
            {
                pontuacao_total += 3;
            }
            else if (distancia_anterior <= 3.0)
            {
                pontuacao_total += 2;
            }
        }

        x_anterior = x_atual;
        y_anterior = y_atual;
    }

    printf("\n----------------------------------\n");
    printf("A pontuação total foi de: %.0f pontos.\n", pontuacao_total);
    printf("----------------------------------\n");

    return 0;
}