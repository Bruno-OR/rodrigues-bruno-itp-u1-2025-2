#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_CTYPE, "Portuguese"); // Usado para imprimir corretamente os acentos e caracteres especiais em português

    float celsius, fahrenheit, kelvin;

    printf("\nDigite a temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = ((celsius * 9) / 5) + 32;
    kelvin = celsius + 273.15;
    printf("\n--- Resultado da conversão ---\n\n");
    printf("%.1f graus Celsius em graus Fahrenheit = \t%.1f F\n", celsius, fahrenheit);
    printf("%.1f graus Celsius em graus Kelvin = \t\t%.1f K", celsius, kelvin);

    
    return 0;
}