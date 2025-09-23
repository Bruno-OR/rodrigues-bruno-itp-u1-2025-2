#include <stdio.h>

int main()
{

    float lado1, lado2, lado3;
    float a, b, c;

    printf("Digite o comprimento do primeiro lado: ");
    scanf("%f", &lado1);
    printf("Digite o comprimento do segundo lado: ");
    scanf("%f", &lado2);
    printf("Digite o comprimento do terceiro lado: ");
    scanf("%f", &lado3);

    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1))
    {

        printf("\nOs lados formam um triângulo.\n");
        printf("------------------------------------\n");

        printf("Classificação (Lados): ");
        if (lado1 == lado2 && lado2 == lado3)
        {
            printf("Equilátero\n");
        }
        else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3)
        {
            printf("Isósceles\n");
        }
        else
        {
            printf("Escaleno\n");
        }

        if (lado1 >= lado2 && lado1 >= lado3)
        {
            a = lado1;
            b = lado2;
            c = lado3;
        }
        else if (lado2 >= lado1 && lado2 >= lado3)
        {
            a = lado2;
            b = lado1;
            c = lado3;
        }
        else
        {
            a = lado3;
            b = lado1;
            c = lado2;
        }

        float a_quadrado = pow(a, 2);
        float bc_quadrado = pow(b, 2) + pow(c, 2);

        printf("Classificação (Ângulos): ");
        if (a_quadrado == bc_quadrado)
        {
            printf("Retângulo\n");
        }
        else if (a_quadrado < bc_quadrado)
        {
            printf("Acutângulo\n");
        }
        else
        {
            printf("Obtusângulo\n");
        }
    }
    else
    {
        printf("\nOs valores fornecidos não podem formar um triângulo.\n");
    }

    return 0;
}