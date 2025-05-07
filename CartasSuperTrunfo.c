#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de cidade
typedef struct {
    char estado[50];
    char codigo[50];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} CartaCidade;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    if (area > 0) {
        return (float)populacao / area;
    } else {
        return 0.0;
    }
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(float pib, int populacao) {
    if (populacao > 0) {
        return pib / populacao;
    } else {
        return 0.0;
    }
}

int main() {
    // Define as duas cartas diretamente no código
    CartaCidade carta1 = {
        "SP",
        "A01",
        "São Paulo",
        12300000,
        1521.11,
        699.28,
        50,
        0.0, // Densidade Populacional (será calculada)
        0.0  // PIB per Capita (será calculado)
    };

    CartaCidade carta2 = {
        "RJ",
        "B02",
        "Rio de Janeiro",
        6000000,
        1200.25,
        300.50,
        30,
        0.0, // Densidade Populacional (será calculada)
        0.0  // PIB per Capita (será calculado)
    };

    // Calcula a Densidade Populacional e o PIB per Capita para cada carta
    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPibPerCapita(carta1.pib * 1000000000.0, carta1.populacao); // PIB em bilhões
    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPibPerCapita(carta2.pib * 1000000000.0, carta2.populacao); // PIB em bilhões

    // --- Escolha do atributo para comparação (DEFINIDO NO CÓDIGO) ---
    char atributoComparacao[] = "População"; // Você pode alterar para "Área", "PIB", "Densidade Populacional" ou "PIB per Capita"

    printf("Comparação de cartas (Atributo: %s):\n\n", atributoComparacao);

    // Exibe as informações das cartas para o atributo escolhido
    printf("Carta 1 - %s (%s): ", carta1.nomeCidade, carta1.estado);
    if (strcmp(atributoComparacao, "População") == 0) {
        printf("%d\n", carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributoComparacao, "Área") == 0) {
        printf("%.2f km²\n", carta1.area);
        printf("Carta 2 - %s (%s): %.2f km²\n", carta2.nomeCidade, carta2.estado, carta2.area);
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributoComparacao, "PIB") == 0) {
        printf("%.2f bilhões\n", carta1.pib);
        printf("Carta 2 - %s (%s): %.2f bilhões\n", carta2.nomeCidade, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributoComparacao, "Densidade Populacional") == 0) {
        printf("%.2f hab/km²\n", carta1.densidadePopulacional);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributoComparacao, "PIB per Capita") == 0) {
        printf("%.2f\n", carta1.pibPerCapita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);
        if (carta1.pibPerCapita > carta2.pibPerCapita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        printf("Atributo de comparação inválido no código.\n");
    }

    return 0;
}