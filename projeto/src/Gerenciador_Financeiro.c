#include <stdio.h>
#include <stdlib.h> // Para malloc, realloc, free
#include <string.h> // Para strcmp, strcpy

char **tickers = NULL;   // Ponteiro para ponteiro de char (para o array de strings)
double *precos = NULL;   // Ponteiro para double
double *dysAnual = NULL; // Ponteiro para double
int totalAtivos = 0;
int capacidade = 0; // Controla a capacidade alocada

void exibirMenu();
void cadastrarAtivo();
void listarAtivos();
void simularCarteira();
void liberarMemoria();
void exibirRelatorio(int anosCompletos, int numAtivos, double matriz[][numAtivos], char **nomesTickers);

// --- Main ---
int main()
{
    int opcao;
    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarAtivo();
            break;
        case 2:
            listarAtivos();
            break;
        case 3:
            simularCarteira();
            break;
        case 0:
            printf("\nSaindo...\n\n");
            break;
        default:
            printf("\nOpcao invalida!\n\n");
            break;
        }
    } while (opcao != 0);

    liberarMemoria();
    return 0;
}

// --- Funções ---

void exibirMenu()
{
    printf("\n--- Simulador Financeiro ---\n");
    printf("1. Cadastrar Ativo na Carteira\n");
    printf("2. Listar Ativos Cadastrados\n");
    printf("3. Iniciar Simulacao de Carteira\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void cadastrarAtivo()
{
    if (totalAtivos >= capacidade)
    {
        int novaCapacidade = (capacidade == 0) ? 5 : capacidade * 2;
        double *tempPrecos = realloc(precos, novaCapacidade * sizeof(double));
        if (tempPrecos == NULL)
        {
            printf("ERRO: Falha ao alocar memoria para precos!\n");
            return;
        }
        precos = tempPrecos;
        double *tempDys = realloc(dysAnual, novaCapacidade * sizeof(double));
        if (tempDys == NULL)
        {
            printf("ERRO: Falha ao alocar memoria para DYs!\n");
            return;
        }
        dysAnual = tempDys;
        char **tempTickers = realloc(tickers, novaCapacidade * sizeof(char *));
        if (tempTickers == NULL)
        {
            printf("ERRO: Falha ao alocar memoria para tickers!\n");
            return;
        }
        tickers = tempTickers;
        capacidade = novaCapacidade;
        printf(" -> (Memoria da carteira expandida para %d ativos)\n", capacidade);
    }

    // Aloca memória para a string do novo ticker antes de ler
    tickers[totalAtivos] = malloc(7 * sizeof(char));
    if (tickers[totalAtivos] == NULL)
    {
        printf("ERRO: Falha ao alocar memoria para o novo ticker string!\n");
        return;
    }

    char novoTickerTemp[7];
    printf("\n--- Cadastro de Novo Ativo ---\n");
    printf("Digite o ticker (max 6 caracteres): ");
    scanf("%6s", novoTickerTemp);

    for (int i = 0; i < totalAtivos; i++)
    {
        if (tickers[i] != NULL && strcmp(novoTickerTemp, tickers[i]) == 0)
        {
            printf("\nERRO: O ticker '%s' ja existe.\n", novoTickerTemp);
            free(tickers[totalAtivos]); // Libera a memória alocada para a string não usada
            tickers[totalAtivos] = NULL;
            return;
        }
    }

    strcpy(tickers[totalAtivos], novoTickerTemp);
    printf("Digite o preco: ");
    scanf("%lf", &precos[totalAtivos]);
    printf("Digite o DY Anual (%%): ");
    scanf("%lf", &dysAnual[totalAtivos]);
    totalAtivos++;
    printf("\n---------------------------\nAtivo cadastrado! Total: %d\n---------------------------\n", totalAtivos);
}

void listarAtivos()
{
    printf("\n--- Ativos na Carteira (%d cadastrados) ---\n", totalAtivos);
    if (totalAtivos == 0)
    {
        printf("Nenhum ativo cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalAtivos; i++)
    {
        printf("%d: Ticker: %s | Preco: R$%.2f | DY: %.2f%%\n", i + 1, tickers[i], precos[i], dysAnual[i]);
    }
}

void simularCarteira()
{
    if (totalAtivos == 0)
    {
        printf("\nERRO: Cadastre ativos antes de simular.\n");
        return;
    }

    double aporteInicial, aporteMensal, metaRendaPassiva;
    double alocacao[totalAtivos];
    long long int quantidadeUnidades[totalAtivos];
    double somaAlocacao = 0;

    for (int i = 0; i < totalAtivos; i++)
    {
        quantidadeUnidades[i] = 0;
    }

    printf("\n--- Configuracao da Simulacao de Carteira ---\n");
    for (int i = 0; i < totalAtivos; i++)
    {
        printf("Digite o %% de alocacao para %s: ", tickers[i]);
        scanf("%lf", &alocacao[i]);
        somaAlocacao += alocacao[i];
    }
    if (somaAlocacao > 100.1 || somaAlocacao < 99.9)
    {
        printf("\nERRO: Soma das alocacoes deve ser 100%%.\n");
        return;
    }
    printf("Digite o APORTE INICIAL (ou 0): ");
    scanf("%lf", &aporteInicial);
    printf("Digite o APORTE MENSAL: ");
    scanf("%lf", &aporteMensal);
    printf("Digite a META de renda passiva mensal: ");
    scanf("%lf", &metaRendaPassiva);

    int meses = 0;
    double rendaPassivaAtual = 0;
    double caixaSobra = 0.0;
    int maxAnos = 50;
    double historicoPatrimonio[maxAnos][totalAtivos];

    if (aporteInicial > 0)
    {
        for (int i = 0; i < totalAtivos; i++)
        {
            double valorAlocado = aporteInicial * (alocacao[i] / 100.0);
            long long int unidadesIniciais = (long long int)(valorAlocado / precos[i]);
            if (unidadesIniciais > 0)
            {
                quantidadeUnidades[i] = unidadesIniciais;
                caixaSobra += valorAlocado - (unidadesIniciais * precos[i]);
            }
            else
            {
                caixaSobra += valorAlocado;
            }
        }
    }

    printf("\nIniciando simulacao de carteira...\n");
    while (rendaPassivaAtual < metaRendaPassiva && (meses / 12) < maxAnos)
    {
        meses++;
        rendaPassivaAtual = 0;
        for (int i = 0; i < totalAtivos; i++)
        {
            double divMensal = (precos[i] * (dysAnual[i] / 100.0)) / 12.0;
            rendaPassivaAtual += quantidadeUnidades[i] * divMensal;
        }
        double valorParaInvestir = aporteMensal + rendaPassivaAtual + caixaSobra;
        caixaSobra = 0;
        for (int i = 0; i < totalAtivos; i++)
        {
            double valorAlocado = valorParaInvestir * (alocacao[i] / 100.0);
            long long int novasUnidades = (long long int)(valorAlocado / precos[i]);
            if (novasUnidades > 0)
            {
                quantidadeUnidades[i] += novasUnidades;
                caixaSobra += valorAlocado - (novasUnidades * precos[i]);
            }
            else
            {
                caixaSobra += valorAlocado;
            }
        }

        if (meses > 0 && meses % 12 == 0)
        {
            int anoAtualIdx = (meses / 12) - 1;
            printf("Ano %d -> Renda Passiva Mensal Total: R$ %.2f\n", anoAtualIdx + 1, rendaPassivaAtual);
            for (int i = 0; i < totalAtivos; i++)
            {
                historicoPatrimonio[anoAtualIdx][i] = quantidadeUnidades[i] * precos[i];
            }
        }
    } // Fim do while

    printf("\n--- Resultado Final da Simulacao ---\n");
    printf("Meta de R$ %.2f atingida!\n", metaRendaPassiva);
    printf("Tempo necessario: %d anos e %d meses.\n", meses / 12, meses % 12);
    double patrimonioTotal = caixaSobra;
    printf("\n--- Patrimonio Acumulado Detalhado ---\n");
    for (int i = 0; i < totalAtivos; i++)
    {
        double patrimonioAtivo = quantidadeUnidades[i] * precos[i];
        printf("%s: %lld unidades -> R$ %.2f\n", tickers[i], quantidadeUnidades[i], patrimonioAtivo);
        patrimonioTotal += patrimonioAtivo;
    }
    printf("Sobra em caixa: R$ %.2f\n", caixaSobra);
    printf("Patrimonio total estimado: R$ %.2f\n", patrimonioTotal);
    printf("------------------------------------\n");

    exibirRelatorio(meses / 12, totalAtivos, historicoPatrimonio, tickers);
}

void exibirRelatorio(int anosCompletos, int numAtivos, double matriz[][numAtivos], char **nomesTickers)
{
    printf("\n--- Relatorio Anual de Evolucao do Patrimonio por Ativo ---\n");
    printf("%-5s", "Ano");
    for (int j = 0; j < numAtivos; j++)
    {
        printf(" | %-10s", nomesTickers[j]);
    }
    printf("\n------");
    for (int j = 0; j < numAtivos; j++)
    {
        printf("-|-----------");
    }
    printf("\n");
    for (int i = 0; i < anosCompletos; i++)
    {
        printf("%-5d", i + 1);
        for (int j = 0; j < numAtivos; j++)
        {
            if (i < 50)
            {
                printf(" | R$%-9.2f", matriz[i][j]);
            }
            else
            {
                printf(" | %-10s", "N/A");
            }
        }
        printf("\n");
    }
    printf("------");
    for (int j = 0; j < numAtivos; j++)
    {
        printf("-|-----------");
    }
    printf("\n");
}

void liberarMemoria()
{
    if (tickers != NULL)
    {
        for (int i = 0; i < totalAtivos; i++)
        {
            free(tickers[i]); // Libera cada string de ticker
        }
        free(tickers); // Libera o array de ponteiros
    }
    free(precos);
    free(dysAnual);
    tickers = NULL;
    precos = NULL;
    dysAnual = NULL;
    totalAtivos = 0;
    capacidade = 0;
    printf("Memoria liberada.\n");
}