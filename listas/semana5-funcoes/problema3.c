#include <stdio.h>
#include <math.h>

double calculaAltura(double x, double y);
int ehPontoSeguro(double x, double y);

int main()
{
    double x_pouso, y_pouso;

    printf("Digite a coordenada de pouso (x y): ");
    scanf("%lf %lf", &x_pouso, &y_pouso);

    if (ehPontoSeguro(x_pouso, y_pouso) == 0)
    {
        printf("\ntroque de coordenada\n");
    }
    else
    {
        int vizinhos_seguros = 0;
        if (ehPontoSeguro(x_pouso + 2, y_pouso))
            vizinhos_seguros++;
        if (ehPontoSeguro(x_pouso - 2, y_pouso))
            vizinhos_seguros++;
        if (ehPontoSeguro(x_pouso, y_pouso - 2))
            vizinhos_seguros++;
        if (ehPontoSeguro(x_pouso, y_pouso + 2))
            vizinhos_seguros++;

        printf("\n");
        if (vizinhos_seguros <= 1)
        {
            printf("inseguro\n");
        }
        else if (vizinhos_seguros <= 3)
        {
            printf("relativamente seguro\n");
        }
        else
        {
            printf("seguro\n");
        }
    }
    return 0;
}

double calculaAltura(double x, double y)
{
    return sin(cos(y) + x) + cos(y + sin(x));
}

int ehPontoSeguro(double x, double y)
{
    double h;
    if ((h = calculaAltura(x, y)) < 0 || h > 2)
        return 0;
    if ((h = calculaAltura(x + 0.2, y + 0.2)) < 0 || h > 2)
        return 0;
    if ((h = calculaAltura(x - 0.2, y - 0.2)) < 0 || h > 2)
        return 0;
    if ((h = calculaAltura(x + 0.2, y - 0.2)) < 0 || h > 2)
        return 0;
    if ((h = calculaAltura(x - 0.2, y + 0.2)) < 0 || h > 2)
        return 0;
    return 1;
}