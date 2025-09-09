#include <stdio.h>
#include <math.h> //Para incluir a função pow

int main()
{

    float capital_inicial, taxa_juros, montante_final;
    int tempo_anos;

    printf("\nDigite o capital inicial: R$ ");
    scanf("%f", &capital_inicial);
    printf("Qual a taxa de juros? (Em %%): ");
    scanf("%f", &taxa_juros);
    printf("Agora digite o tempo de investimento em anos: ");
    scanf("%d", &tempo_anos);

    montante_final = capital_inicial * pow(1 + (taxa_juros / 100), tempo_anos);

    printf("\n--- Resultado do Investimento ---\n");
    printf("\nApós %d anos, o montante final será de: R$ %.2f", tempo_anos, montante_final);

    return 0;
}