# Introdução a Técnicas de Programação
* **Aluno**: Bruno Cézar de Oliveira Rodrigues
* **Matrícula**: 20250052728
* **Período**: 2025.2

## 📁 Estrutura do Projeto
- **projeto/:** Projeto principal da unidade
- **listas/:** Soluções das listas de exercícios
- **README.md:** Este arquivo

## 📈 Projeto: Simulador de Investimentos
**Descrição**: Uma aplicação em C que permita ao usuário simular o tempo de investimento necessário para atingir determinada meta de renda de uma carteira baseada em dados fundamentais de uma Ação ou Fundo Imobiliário bem como a meta e valores investidos, ambos definidos pelo usuário. O desenvolvimento do projeto será incremental, com novas funcionalidades sendo adicionadas ao longo do semestre, aplicando os conceitos aprendidos em aula.

**Repositório**: https://github.com/Bruno-OR/rodrigues-bruno-itp-u1-2025-2

**Vídeo de Demonstração U1**: https://youtu.be/pjq3BbfsSOA

**Vídeo de Demonstração U2**: https://youtu.be/MqglamfJvok

### Funcionalidades Implementadas na U1:
- **Menu Interativo:** Permite ao usuário navegar entre as diferentes opções do simulador.
- **Cadastro de Ativos:** O usuário pode inserir os dados de uma Ação ou Fundo Imobiliário (preço, dividendo anual).
- **Simulação de Investimento:** Calcula o tempo necessário em meses para atingir uma meta de renda passiva, com base em aportes mensais definidos pelo usuário.
- **Exibição de Relatório:** Mostra o resultado da simulação de forma clara, incluindo o total investido e o tempo para atingir o objetivo.

### Funcionalidades Implementadas na U2:
- **Cadastro de Ativos Dinâmico:** Remove o limite fixo de ativos usando alocação dinâmica de memória (malloc/realloc).
- **Validação de Ticker Duplicado:** Impede o cadastro de ativos com o mesmo ticker usando strcmp.
- **Simulação de Carteira Completa:** Implementa a simulação considerando a carteira inteira, com:
- - * Alocação percentual definida pelo usuário para cada ativo.
- - * Distribuição do aporte mensal e da renda passiva entre os ativos.
- **Relatório Histórico Anual (Matriz):** Exibe uma tabela com a evolução do patrimônio em cada ativo, ano a ano.
- **Gerenciamento de Memória:** Libera a memória alocada dinamicamente ao sair (free).

### Conceitos da U1 Aplicados:
* **Estruturas condicionais:** Utilizadas para gerenciar o menu principal (switch-case) e para validar as entradas do usuário, evitando erros no programa.
* **Estruturas de repetição:** Foram usados dois laços de repetição, sendo um para manter o menu de opções sempre disponível até que o usuário escolha a opção de sair e o outro para realizar a simulação mês a mês, calculando o reinvestimento de dividendos e novos aportes, até que a meta de renda seja atingida.
* **Vetores:** Foram usados para armazenar a lista de ativos e suas informações. 
* **Funções:** O projeto foi dividido em algumas funções tornando o programa mais limpo e organizado.

### Conceitos da U2 Aplicados:
* **Strings:** Armazenamento dos tickers (char **tickers) e comparação para evitar duplicatas com strcmp. Cópia segura com strcpy.
* **Estruturas de Repetição Aninhadas:** Usadas na função simularCarteira, onde o laço while dos meses contém laços for para percorrer os ativos da carteira e também usada na função exibirRelatorio.
* **Matrizes (Arrays 2D):** Utilizada na função simularCarteira para armazenar o histórico anual do patrimônio por ativo. A função exibirRelatorio percorre essa matriz para exibir a tabela.
* **Ponteiros:** As variáveis globais tickers, precos e dysAnual foram transformadas em ponteiros.
* **Alocação Dinâmica Básica:** A função cadastrarAtivo utiliza malloc e realloc para expandir a capacidade da carteira conforme necessário. A função liberarMemoria utiliza free para liberar toda a memória ao final.

## 📝 Listas de Exercícios
As soluções para as listas de exercícios da Unidade 1 estão na pasta `listas/`.

### Semana 2 - Variáveis, Tipos e Operadores
* Problema 1: Calculadora de IMC
* Problema 2: Conversão de temperatura
* Problema 3: Cálculo de juros compostos
* Problema 4: Operações aritméticas básicas

### Semana 3 - Estruturas Condicionais
* Problema 1: Classificação de IMC
* Problema 2: Calculadora de energia elétrica
* Problema 3: Sistema de notas
* Problema 4: Pedra, papel, tesoura
* Problema 5: Calculadora de desconto progressivo
* Problema 6: Diagnóstico médico simples
* Problema 7: Sistema de equações do 2º grau
* Problema 8: Validador de triângulos

### Semana 4A - Repetições Simples
* Problema 1: Dobrando até não poder mais
* Problema 2: Salve o homem aranha
* Problema 3: Números colegas
* Problema 4: Jogo de dardos

### Semana 4B - Análise e Padrões
* Questões 1-4: Análise de código
* Questões 5-11: Implementações de padrões e problemas

### Semana 5 - Funções (Parte 1)
* Problema 1: Horários das rondas
* Problema 2: Primos triplos
* Problema 3: Pousando a sonda espacial

### Semana 6 - Vetores
* Problema 1: MEC Correção ENEM
* Problema 2: Álbum de figurinhas
* Problema 3: A construção da ponte
* Problema 4: Em busca do tesouro perdido

### Semana 7 - Strings
* Problema 1: Campo minado 1D
* Problema 2: Detecção de placas
* Problema 3: OpenMeet

### Semana 8 - Repetições aninhadas
* Problema 1:  Estou com sorte (ou não)
* Problema 2: Os dias mais chuvosos
* Problema 3: Esse sim é piloto

### Semana 9 - Matrizes
* Problema 1: Campo Agrícola
* Problema 2: Sugestão de amigos
* Problema 3: Campeonato de empates
* Problema 4: Uma pechincha!

### Semana 10 - Ponteiros e Alocação dinâmica
* Problema 1: Soma de Vetores
* Problema 2: Ocorrências no vetor
* Problema 3: Sopa de letrinhas

## 🎯 Principais Aprendizados
* **Unidade 1:** Com a introdução dos conceitos da unidade 1 ganhamos base para saber como otimizar um programa. O uso dos condicionais e estruturas de repetição nos permitiu a criação de algoritmos capazes de tomar decisões e testar múltiplas combinações. Já com o uso das funções, foi possível dividir o problema em partes, as quais cada uma se responsabiliza por alguma coisa, o que deixa o código mais limpo e fácil de entender e até de encontrar erros. E, por fim, o uso dos vetores nos garante a manipulação eficiente de um conjunto de dados. Ou seja, juntos, esses conceitos básicos forma um poderoso arsenal para a construção de um programa robusto e eficiente.

* **Unidade 2:** Esta unidade mostrou o quanto podemos evoluir nosso projeto com apenas alguns conceitos que, sozinhos, se tornam simples, como strings e matrizes, laços de repetição aninhados, ponteiros e alocação dinâmica, mas que juntos representam um arsenal poderoso, o que torna o projeto e demais atividades muito mais complexos. Foi possível criar estruturas de dados mais flexíveis com os ponteiros e alocação dinâmica, gerenciamento de memória com malloc e realloc e free, validações com strings e apresentar dados históricos com as matrizes. Já para a simulação da carteira foi essencial o uso dos laços aninhados.

## 💻 Ambiente de Desenvolvimento
* **SO**: Windows
* **Compilador**: GCC (via MinGW/MSYS2)
* **Editor**: Visual Studio Code