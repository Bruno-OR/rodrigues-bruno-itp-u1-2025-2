#include <stdio.h>
#include <math.h>

int main()
{

    float x_aranha, y_aranha;
    float comprimento_teia;
    int n_alvos;

    int sucesso = 1;

    printf("Digite a coordenada inicial (x, y) do Homem-Aranha: ");
    scanf("%f %f", &x_aranha, &y_aranha);

    printf("Digite o comprimento máximo da teia: ");
    scanf("%f", &comprimento_teia);

    printf("Digite a quantidade de alvos: ");
    scanf("%d", &n_alvos);

    for (int i = 0; i < n_alvos; i++)
    {
        float ax, ay, distancia;

        printf("Digite a coordenada do alvo %d (x, y): ", i + 1);
        scanf("%f %f", &ax, &ay);

        if (sucesso == 0)
        {
            continue;
        }

        distancia = sqrt(pow(ax - x_aranha, 2) + pow(ay - y_aranha, 2));

        if (distancia > comprimento_teia)
        {

            sucesso = 0;
        }
        else
        {

            float x_anterior = x_aranha;
            x_aranha = 2 * ax - x_anterior;
        }
    }

    if (sucesso == 1)
    {
        printf("\nS\n");
    }
    else
    {
        printf("\nN\n");
    }

    return 0;
}