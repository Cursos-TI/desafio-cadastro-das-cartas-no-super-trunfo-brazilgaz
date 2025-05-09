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
    if (area > 0) {
        return (float)populacao / area;
    } else {
        return 0.0;
    }
}

int main() {
    // Define as duas cartas diretamente no código (reutilizando a ideia do nível novato)
    CartaPais carta1 = {
        "Brasil",
        214000000,
        8516000.00,
        1400.00,
        250,
        0.0 // Densidade Demográfica (será calculada)
    };

    CartaPais carta2 = {
        "Argentina",
        45000000,
        2780000.00,
        490.00,
        100,
        0.0 // Densidade Demográfica (será calculada)
    };

    // Calcula a densidade demográfica para cada carta
    carta1.densidadeDemografica = calcularDensidadeDemografica(carta1.populacao, carta1.area);
    carta2.densidadeDemografica = calcularDensidadeDemografica(carta2.populacao, carta2.area);

    int escolha;

    printf("\n--- Batalha de Super Trunfo de Países ---\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n\n", carta2.nomePais);

    do {
        printf("Escolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);

        printf("\n--- Resultado da Comparação ---\n");
        printf("Países: %s vs %s\n", carta1.nomePais, carta2.nomePais);

        switch (escolha) {
            case 1: // Comparar População
                printf("Atributo: População\n");
                printf("%s: %d\n", carta1.nomePais, carta1.populacao);
                printf("%s: %d\n", carta2.nomePais, carta2.populacao);
                if (carta1.populacao > carta2.populacao) {
                    printf("Vencedor: %s\n", carta1.nomePais);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("Vencedor: %s\n", carta2.nomePais);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 2: // Comparar Área
                printf("Atributo: Área\n");
                printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
                printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);
                if (carta1.area > carta2.area) {
                    printf("Vencedor: %s\n", carta1.nomePais);
                } else if (carta2.area > carta1.area) {
                    printf("Vencedor: %s\n", carta2.nomePais);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 3: // Comparar PIB
                printf("Atributo: PIB\n");
                printf("%s: %.2f trilhões USD\n", carta1.nomePais, carta1.pib);
                printf("%s: %.2f trilhões USD\n", carta2.nomePais, carta2.pib);
                if (carta1.pib > carta2.pib) {
                    printf("Vencedor: %s\n", carta1.nomePais);
                } else if (carta2.pib > carta1.pib) {
                    printf("Vencedor: %s\n", carta2.nomePais);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 4: // Comparar Número de Pontos Turísticos
                printf("Atributo: Número de Pontos Turísticos\n");
                printf("%s: %d\n", carta1.nomePais, carta1.numPontosTuristicos);
                printf("%s: %d\n", carta2.nomePais, carta2.numPontosTuristicos);
                if (carta1.numPontosTuristicos > carta2.numPontosTuristicos) {
                    printf("Vencedor: %s\n", carta1.nomePais);
                } else if (carta2.numPontosTuristicos > carta1.numPontosTuristicos) {
                    printf("Vencedor: %s\n", carta2.nomePais);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 5: // Comparar Densidade Demográfica
                printf("Atributo: Densidade Demográfica\n");
                printf("%s: %.2f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
                printf("%s: %.2f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);
                if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                    printf("Vencedor: %s\n", carta1.nomePais);
                } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                    printf("Vencedor: %s\n", carta2.nomePais);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 0:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
        printf("\n");
    } while (escolha != 0);

    return 0;
}