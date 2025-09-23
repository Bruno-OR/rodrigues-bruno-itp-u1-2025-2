#include <stdio.h>
#include <math.h> //Para incluir a função pow
#include <ctype.h>

int main()
{
    float taxa_Fixa = 15;
    float consumo, valor_Total;
    char tipo_Consumidor;

    printf("\nDigite o consumo (em KhW): ");
    scanf("%f", &consumo);
    printf("\nDigite o tipo de consumidor (R - residencial, C - comercial, I - industrial): ");
    scanf(" %c", &tipo_Consumidor);

    tipo_Consumidor = toupper(tipo_Consumidor);

    if (tipo_Consumidor == 'R')
    {
        valor_Total = (0.6 * consumo) + taxa_Fixa;
    }
    else if (tipo_Consumidor == 'C')
    {
        valor_Total = (0.48 * consumo) + taxa_Fixa;
    }
    else if (tipo_Consumidor == 'I')
    {
        valor_Total = (1.29 * consumo) + taxa_Fixa;
    }
    printf("\n----------------------------------\n");
    printf("Valor total calculado: R$ %.2f", valor_Total);
    printf("\n----------------------------------\n");
    return 0;
}