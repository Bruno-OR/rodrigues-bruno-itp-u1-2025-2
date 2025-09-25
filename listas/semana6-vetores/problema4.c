#include <stdio.h>

int main()
{

    int sugestoes[10];
    int visitadas[10] = {0};

    int i;
    int ilha_atual = 0;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &sugestoes[i]);
    }

    while (1)
    {

        if (visitadas[ilha_atual] == 1)
        {

            printf("%d\n", ilha_atual);
            break;
        }

        visitadas[ilha_atual] = 1;
        ilha_atual = sugestoes[ilha_atual];
    }

    return 0;
}