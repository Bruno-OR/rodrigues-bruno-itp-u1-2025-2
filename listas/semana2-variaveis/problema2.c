#include <stdio.h>

int main()
{

    float celsius, fahrenheit, kelvin;

    printf("\nDigite a temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = ((celsius * 9) / 5) + 32;
    kelvin = celsius + 273.15;
    printf("\n--- Resultado da convers�o ---\n\n");
    printf("%.1f graus Celsius em graus Fahrenheit = \t%.1f F\n", celsius, fahrenheit);
    printf("%.1f graus Celsius em graus Kelvin = \t\t%.1f K", celsius, kelvin);

        return 0;
}