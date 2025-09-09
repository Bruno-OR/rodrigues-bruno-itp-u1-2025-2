#include <stdio.h>

int main()
{

    float valor_Compra, desconto, valor_final;

    printf("Qual o valor da compra? R$ ");
    scanf("%f", &valor_Compra);

    if (valor_Compra <= 100)
    {
        desconto = 0;
        valor_final = valor_Compra;
        printf("\n--------Sem desconto--------\n\n");
        printf("Valor final da compra: R$ %.2f ", valor_final);
    }
    else if (valor_Compra <= 500)
    {
        desconto = valor_Compra * 0.1;
        valor_final = valor_Compra - (valor_Compra * 0.1);
        printf("\n--------10%% de desconto.--------\n\n");
        printf("Valor do desconto: R$ %.2f\n", desconto);
        printf("Valor final da compra: R$ %.2f ", valor_final);
    }
    else if (valor_Compra <= 1000)
    {
        desconto = valor_Compra * 0.15;
        valor_final = valor_Compra - (valor_Compra * 0.15);
        printf("\n--------15%% de desconto.--------\n\n");
        printf("Valor do desconto: R$ %.2f\n", desconto);
        printf("Valor final da compra: R$ %.2f ", valor_final);
    }
    else
    {
        desconto = valor_Compra * 0.2;
        valor_final = valor_Compra - (valor_Compra * 0.2);
        printf("\n--------20%% de desconto.--------\n\n");
        printf("Valor do desconto: R$ %.2f\n", desconto);
        printf("Valor final da compra: R$ %.2f ", valor_final);
    }
    printf("\n---------------------------------\n\n");

    return 0;
}