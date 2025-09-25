#include <stdio.h>

void imprimeHorario(int h, int m, int formato);

int main()
{

    int hora, minuto, op;

    printf("Digite a hora da primeira ronda (0-23): ");
    scanf("%d", &hora);
    printf("Digite os minutos da primeira ronda (0-59): ");
    scanf("%d", &minuto);
    printf("Escolha o formato: \n0 - Para formato 24h \n1 - Para formato 12h\nOpcao: ");
    scanf("%d", &op);
    printf("\n--- Horários das Rondas ---\n");

    imprimeHorario(hora, minuto, op);

    imprimeHorario(hora + 1, minuto, op);
    imprimeHorario(hora + 2, minuto + 10, op);
    imprimeHorario(hora + 4, minuto + 40, op);
    imprimeHorario(hora + 12, minuto + 5, op);

    return 0;
}

void imprimeHorario(int h, int m, int formato)
{

    h = h + (m / 60);
    m = m % 60;

    h = h % 24;

    if (formato == 0)
    {

        printf("%02d:%02d\n", h, m);
    }
    else
    {
        int hora_12h = h;

        if (h == 0)
        { // Meia-noite
            hora_12h = 12;
            printf("%02d:%02d AM\n", hora_12h, m);
        }
        else if (h < 12)
        { // Manhã
            printf("%02d:%02d AM\n", hora_12h, m);
        }
        else if (h == 12)
        { // Meio-dia
            printf("%02d:%02d PM\n", hora_12h, m);
        }
        else
        { // Tarde/Noite
            hora_12h = h - 12;
            printf("%02d:%02d PM\n", hora_12h, m);
        }
    }
}
