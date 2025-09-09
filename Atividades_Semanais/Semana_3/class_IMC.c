#include <stdio.h>
#include <math.h> //Para incluir a função pow
#include <locale.h>

int main()
{

    setlocale(LC_CTYPE, "Portuguese"); // Usado para imprimir corretamente os acentos e caracteres especiais em português
    float peso, altura, imc;

    printf("\nQual o seu peso (em Kg)? ");
    scanf("%f", &peso);
    printf("Qual sua altura (em metros)? ");
    scanf("%f", &altura);

    if (peso <= 0 || altura <= 0)
    {
        printf("Por favor insira os dados corretamente!\n");
        printf("Programa encerrado.\n\n");

        return 1; // para encerrar o programa
    }

    imc = peso / pow(altura, 2); // calcula base^expoente

    printf("\n--- Resultado ---\n\n");
    printf("Seu IMC é: %.2f\n", imc);
    if (imc <= 18.5)
    {
        printf("Abaixo do peso\n\n");
    }
    else if (imc <= 24.9)
    {
        printf("Peso normal\n\n");
    }
    else if (imc <= 29.9)
    {
        printf("Sobrepeso\n\n");
    }
    else
    {
        printf("Obesidade\n\n");
    }

    return 0;
}