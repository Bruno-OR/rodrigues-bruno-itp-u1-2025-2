#include <stdio.h>
#include <math.h> //Para incluir a função pow

int main()
{

    float peso, altura, imc;

    printf("\nQual o seu peso (em Kg)? ");
    scanf("%f", &peso);
    printf("Qual sua altura (em metros)? ");
    scanf("%f", &altura);

    imc = peso / pow(altura, 2); // calcula base^expoente

    printf("\n--- Resultado ---\n\n");
    printf("Seu IMC é: %.2f", imc);

    return 0;
}