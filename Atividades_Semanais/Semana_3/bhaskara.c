#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main()

{

    float a, b, c, delta;
    float raiz1, raiz2;

    printf("\n-------------ax^2 + bx + c = 0-------------\n\n");

    printf("Digite o valor de a: ");
    scanf("%f", &a);

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    printf("Digite o valor de c: ");
    scanf("%f", &c);

    delta = (pow(b, 2) - (4 * a * c));

    if (delta > 0)
    {
        printf("\n-------------Resultado: Duas raízes reais e distintas-------------\n\n");
        
        raiz1 = (-b + sqrt(delta)) / (2 * a);
        raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("X1 = %.2f", raiz1);
        printf("\nX2 = %.2f", raiz2);
        printf("\n\n-------------------------------------------------------------------\n\n");
    }
    else if (delta == 0)
    {
        printf("\n-------------Resultado: Uma raíz real-------------\n\n");
       
        raiz1 = -b / (2 * a);
        printf("X = %.2f", raiz1);
         printf("\n\n---------------------------------------------------\n\n");
    }
    else
    {
        printf("\n-------------Resultado: Não possui raízes reais-------------\n\n");
        printf("Valor de delta = %.2f", delta);
        printf("\n\n-----------------------------------------------------------\n\n");
    }

    return 0;
}