#include <stdio.h>
#include <math.h>
#include <ctype.h> // Para a função toupper que vai converter a letra digitada para maiúscula

int main()
{
    char jogador1, jogador2;

    printf("--- Jogo: Pedra, Papel, Tesoura ---\n");
    printf("Opções: [P]edra, [A]papel, [T]esoura\n\n");

    printf("Jogador 1, faça sua jogada: ");
    scanf(" %c", &jogador1);

    printf("Jogador 2, faça sua jogada: ");
    scanf(" %c", &jogador2);

    jogador1 = toupper(jogador1);
    jogador2 = toupper(jogador2);

    printf("\n\n----------------RESULTADO----------------\n\n");

    if (jogador1 == jogador2)
    {
        printf("Empate!\n");
    }
    else if ((jogador1 == 'P' && jogador2 == 'T') ||
             (jogador1 == 'T' && jogador2 == 'A') ||
             (jogador1 == 'A' && jogador2 == 'P'))
    {
        printf("Vitória do Jogador 1!\n");
    }
    else if ((jogador2 == 'P' && jogador1 == 'T') ||
             (jogador2 == 'T' && jogador1 == 'A') ||
             (jogador2 == 'A' && jogador1 == 'P'))
    {
        printf("Vitória do Jogador 2!\n");
    }
    else
    {
        printf("Erro: Uma ou ambas as jogadas são inválidas!\n");
        printf("Por favor, use apenas P, A ou T.\n");
    }
    printf("\n----------------------------------------\n\n");

    return 0;
}