#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 100
#define MAX_STRING 50

// Estrutura para representar uma carta de cidade

typedef struct {
    char estado[MAX_STRING];
    int codigo;
    char nomeCidade[MAX_STRING];
    long long populacao;
    double pib;
    double area;
    int numPontosTuristicos;
    double densidadePopulacional; // Propriedade derivada
    double pibPerCapita;         // Propriedade derivada
} CartaCidade;

// Array para armazenar as cartas de cidades

CartaCidade cartasCidades[MAX_CARTAS];
int numCartasCidades = 0;

// Função para calcular a densidade populacional

double calcularDensidadePopulacional(long long populacao, double area) {
    if (area > 0) {
        return (double)populacao / area;
    } else {
        return 0.0;
    }
}

// Função para calcular o PIB per capita

double calcularPibPerCapita(double pib, long long populacao) {
    if (populacao > 0) {
        return pib / populacao;
    } else {
        return 0.0;
    }
}

// Função para cadastrar uma nova carta de cidade

void cadastrarCartaCidade() {
    if (numCartasCidades < MAX_CARTAS) {
        CartaCidade novaCarta;

        printf("\n--- Cadastrar Nova Carta de Cidade ---\n");
        printf("Estado: ");
        scanf(" %[^\n]", novaCarta.estado);

        printf("Código da Cidade: ");
        scanf("%d", &novaCarta.codigo);

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", novaCarta.nomeCidade);

        printf("População: ");
        scanf("%lld", &novaCarta.populacao);

        printf("PIB (em milhões de R$): ");
        scanf("%lf", &novaCarta.pib);

        printf("Área (em km²): ");
        scanf("%lf", &novaCarta.area);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &novaCarta.numPontosTuristicos);

        // Calcular propriedades

        novaCarta.densidadePopulacional = calcularDensidadePopulacional(novaCarta.populacao, novaCarta.area);
        
        novaCarta.pibPerCapita = calcularPibPerCapita(novaCarta.pib * 1000000, novaCarta.populacao); // Convertendo PIB para a unidade base

        cartasCidades[numCartasCidades++] = novaCarta;
        printf("Carta da cidade cadastrada com sucesso!\n");
    } else {
        printf("Limite máximo de cartas atingido.\n");
    }
}

// Função para exibir as informações detalhadas de uma carta de cidade

void exibirCartaCidade(CartaCidade carta) {
    printf("--- %s (%s) ---\n", carta.nomeCidade, carta.estado);

    printf("Código: %d\n", carta.codigo);

    printf("População: %lld habitantes\n", carta.populacao);

    printf("PIB: R$ %.2lf milhões\n", carta.pib);

    printf("Área: %.2lf km²\n", carta.area);

    printf("Número de Pontos Turísticos: %d\n", carta.numPontosTuristicos);

    printf("Densidade Populacional: %.2lf hab/km²\n", carta.densidadePopulacional);

    printf("PIB Per Capita: R$ %.2lf\n", carta.pibPerCapita);
}

// Função para listar todas as cartas de cidades cadastradas
void listarCartasCidades() {
    if (numCartasCidades > 0) {
        printf("\n--- Cartas de Cidades Cadastradas ---\n");
        for (int i = 0; i < numCartasCidades; i++) {
            printf("--- Carta %d ---\n", i + 1);
            exibirCartaCidade(cartasCidades[i]);
        }
    } else {
        printf("Nenhuma carta de cidade cadastrada ainda.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- Menu Super Trunfo de Cidades ---\n");
        printf("1. Cadastrar Carta de Cidade\n");
        printf("2. Listar Cartas de Cidades\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCartaCidade();
                break;
            case 2:
                listarCartasCidades();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}