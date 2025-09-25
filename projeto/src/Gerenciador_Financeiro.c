#include <stdio.h>
#include <string.h>

// --- Declaração das variáveis ---
char tickers[5][7];
double precos[5];
double dysAnual[5];
int totalAtivos = 0;

// --- Funções ---
void exibirMenu();
void cadastrarAtivo();
void listarAtivos();
void iniciarSimulacao();
void simularInvestimento(double precoAtivo, double dyAnual, double aporteInicial, double aporteMensal, double metaRendaPassiva);

// --- Menu ---
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
            iniciarSimulacao();
            break;
        case 0:
            printf("\nSaindo...\n\n");
            break;
        default:
            printf("\nOpcao invalida!\n\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

void exibirMenu()
{
    printf("\n--- Simulador Financeiro ---\n");
    printf("1. Cadastrar Ativo na Carteira (max: 5)\n");
    printf("2. Listar Ativos Cadastrados\n");
    printf("3. Iniciar Simulacao com um Ativo\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void cadastrarAtivo()
{
    if (totalAtivos < 5)
    {
        printf("\n--- Cadastro de Novo Ativo ---\n");
        printf("Digite o ticker (max 6 caracteres): ");
        scanf("%s", tickers[totalAtivos]);
        printf("Digite o preco: ");
        scanf("%lf", &precos[totalAtivos]);
        printf("Digite o DY Anual (%%): ");
        scanf("%lf", &dysAnual[totalAtivos]);
        totalAtivos++;
        printf("\n---------------------------\n");
        printf("Ativo cadastrado com sucesso!\n");
         printf("---------------------------\n");
    }
    else
    {
        printf("\nERRO: Limite de 5 ativos atingido.\n");
    }
}

void listarAtivos()
{
    printf("\n--- Ativos na Carteira ---\n");
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

void iniciarSimulacao()
{
    if (totalAtivos == 0)
    {
        printf("\nERRO: Cadastre pelo menos um ativo antes de simular.\n");
        return;
    }

    int escolha;
    double aporteInicial, aporteMensal, metaRendaPassiva;

    printf("\n--- Iniciar Simulacao ---\n");
    listarAtivos();
    printf("Escolha o numero do ativo que deseja simular: ");
    scanf("%d", &escolha);

    if (escolha > 0 && escolha <= totalAtivos)
    {
        int indice = escolha - 1;

        printf("\n--- Configuracao para %s ---\n", tickers[indice]);
        printf("Digite o APORTE INICIAL (ou 0): ");
        scanf("%lf", &aporteInicial);
        printf("Digite o APORTE MENSAL: ");
        scanf("%lf", &aporteMensal);
        printf("Digite a META de renda passiva mensal: ");
        scanf("%lf", &metaRendaPassiva);

        simularInvestimento(precos[indice], dysAnual[indice], aporteInicial, aporteMensal, metaRendaPassiva);
    }
    else
    {
        printf("Escolha invalida.\n");
    }
}

void simularInvestimento(double precoAtivo, double dyAnual, double aporteInicial, double aporteMensal, double metaRendaPassiva)
{
    int meses = 0;
    long long int quantidadeUnidades = 0;
    double rendaPassivaAtual = 0;
    double caixaSobra = 0.0;
    double divMensalPorUnidade = (precoAtivo * (dyAnual / 100.0)) / 12.0; // (35.8*(8.31/100))/12 = 0,25

    if (aporteInicial > 0)
    {
        long long int unidadesIniciais = (long long int)(aporteInicial / precoAtivo); // 1500/35.8 = 41 .81
        if (unidadesIniciais > 0)
        {
            double custoInicial = unidadesIniciais * precoAtivo; // 41*35.8 = 1467.8
            caixaSobra = aporteInicial - custoInicial; // 1500 - 1467.8 = 32.2
            quantidadeUnidades = unidadesIniciais; // = 41
            rendaPassivaAtual = quantidadeUnidades * divMensalPorUnidade; // 41*0,25 = 10,25
        }
        else
        {
            caixaSobra = aporteInicial;
        }
    }

    while (rendaPassivaAtual < metaRendaPassiva) //10,25 < 1200
    {
        meses++;
        double valorParaInvestir = aporteMensal + rendaPassivaAtual + caixaSobra; //500 + 10,25 + 32,2
        long long int novasUnidadesCompradas = (long long int)(valorParaInvestir / precoAtivo); // 542,45/35.8 = 15, 15

        if (novasUnidadesCompradas > 0)
        {
            double custoDaCompra = novasUnidadesCompradas * precoAtivo; //15*35.8 = 537
            caixaSobra = valorParaInvestir - custoDaCompra; // 542.45-537 = 5,45
            quantidadeUnidades += novasUnidadesCompradas; // 41 + 15 = 56
        }
        else
        {
            caixaSobra = valorParaInvestir;
        }

        rendaPassivaAtual = quantidadeUnidades * divMensalPorUnidade; // 56 * 0,25 = 14
    }

    printf("\n--- Resultado da Simulacao ---\n");
    printf("Meta de R$ %.2f atingida!\n", rendaPassivaAtual);
    printf("Tempo necessario: %d anos e %d meses.\n", meses / 12, meses % 12);
    printf("Total de unidades acumuladas: %lld\n", quantidadeUnidades);
    printf("Patrimonio total estimado: R$ %.2f\n", (quantidadeUnidades * precoAtivo) + caixaSobra);
    printf("--------------------------------\n");
}
