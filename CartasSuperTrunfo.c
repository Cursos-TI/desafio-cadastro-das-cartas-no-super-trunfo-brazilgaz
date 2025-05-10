#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadeDemografica;
} CartaPais;

// Função para calcular a densidade demográfica
float calcularDensidadeDemografica(int populacao, float area) {
    return (area > 0) ? (float)populacao / area : 0.0;
}

// Função para obter o valor de um atributo escolhido
float getAtributo(CartaPais carta, int escolha) {
    switch (escolha) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.numPontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return 0.0; // Tratar erro
    }
}

// Função para obter o nome de um atributo escolhido
const char* getNomeAtributo(int escolha) {
    switch (escolha) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Número de Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Define as duas cartas diretamente no código
    CartaPais carta1 = {"Canadá", 38000000, 9985000.00, 2000.00, 150, 3.80};
    CartaPais carta2 = {"Japão", 126000000, 377900.00, 5000.00, 300, 333.42};

    int escolha1, escolha2;

    printf("\n--- Batalha de Super Trunfo de Países ---\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n\n", carta2.nomePais);

    // --- Escolha do Primeiro Atributo ---
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Sua primeira escolha: ");
    scanf("%d", &escolha1);

    if (escolha1 < 1 || escolha1 > 5) {
        printf("Opção inválida para o primeiro atributo. Saindo.\n");
        return 1;
    }

    // --- Escolha do Segundo Atributo (garantindo que seja diferente do primeiro) ---
    printf("\nEscolha o SEGUNDO atributo para comparar:\n");
    printf("%s\n%s\n%s\n%s\n%s\n",
           (escolha1 != 1) ? "1 - População" : "",
           (escolha1 != 2) ? "2 - Área" : "",
           (escolha1 != 3) ? "3 - PIB" : "",
           (escolha1 != 4) ? "4 - Número de Pontos Turísticos" : "",
           (escolha1 != 5) ? "5 - Densidade Demográfica" : "");
    printf("Sua segunda escolha: ");
    scanf("%d", &escolha2);

    if (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("Opção inválida para o segundo atributo ou igual ao primeiro. Saindo.\n");
        return 1;
    }

    // --- Realiza as Comparações e Calcula a Soma dos Atributos ---
    float valor1_atributo1 = getAtributo(carta1, escolha1);
    float valor2_atributo1 = getAtributo(carta2, escolha1);
    float valor1_atributo2 = getAtributo(carta1, escolha2);
    float valor2_atributo2 = getAtributo(carta2, escolha2);

    int venceu1 = 0; // 1 se carta1 vence no atributo, -1 se carta2 vence, 0 se empate
    int venceu2 = 0;

    // Compara o primeiro atributo
    if (escolha1 == 5) { // Densidade Demográfica (menor vence)
        venceu1 = (valor1_atributo1 < valor2_atributo1) ? 1 : (valor2_atributo1 < valor1_atributo1) ? -1 : 0;
    } else { // Outros atributos (maior vence)
        venceu1 = (valor1_atributo1 > valor2_atributo1) ? 1 : (valor2_atributo1 > valor1_atributo1) ? -1 : 0;
    }

    // Compara o segundo atributo
    if (escolha2 == 5) { // Densidade Demográfica (menor vence)
        venceu2 = (valor1_atributo2 < valor2_atributo2) ? 1 : (valor2_atributo2 < valor1_atributo2) ? -1 : 0;
    } else { // Outros atributos (maior vence)
        venceu2 = (valor1_atributo2 > valor2_atributo2) ? 1 : (valor2_atributo2 > valor1_atributo2) ? -1 : 0;
    }

    // Calcula a soma dos valores dos atributos para cada carta
    float soma1 = valor1_atributo1 + valor1_atributo2;
    float soma2 = valor2_atributo1 + valor2_atributo2;

    // --- Exibe os Resultados ---
    printf("\n--- Resultado da Comparação Avançada ---\n");
    printf("Países: %s vs %s\n", carta1.nomePais, carta2.nomePais);

    printf("\nAtributo 1: %s\n", getNomeAtributo(escolha1));
    printf("%s: %.2f\n", carta1.nomePais, valor1_atributo1);
    printf("%s: %.2f\n", carta2.nomePais, valor2_atributo1);
    printf("Vencedor neste atributo: %s\n", (venceu1 == 1) ? carta1.nomePais : (venceu1 == -1) ? carta2.nomePais : "Empate");

    printf("\nAtributo 2: %s\n", getNomeAtributo(escolha2));
    printf("%s: %.2f\n", carta1.nomePais, valor1_atributo2);
    printf("%s: %.2f\n", carta2.nomePais, valor2_atributo2);
    printf("Vencedor neste atributo: %s\n", (venceu2 == 1) ? carta1.nomePais : (venceu2 == -1) ? carta2.nomePais : "Empate");

    printf("\n--- Soma dos Atributos ---\n");
    printf("%s: %.2f (%.2f + %.2f)\n", carta1.nomePais, soma1, valor1_atributo1, valor1_atributo2);
    printf("%s: %.2f (%.2f + %.2f)\n", carta2.nomePais, soma2, valor2_atributo1, valor2_atributo2);

    printf("\n--- Resultado Final da Rodada ---\n");
    if (soma1 > soma2) {
        printf("Vencedor da rodada: %s\n", carta1.nomePais);
    } else if (soma2 > soma1) {
        printf("Vencedor da rodada: %s\n", carta2.nomePais);
    } else {
        printf("Empate na rodada!\n");
    }

    return 0;
}