#include <stdio.h>

#define DIAS 7   // periodo de analise: uma semana, de segunda a domingo

int main() {
    // matriz de caracteres: cada linha guarda o nome de um dia
    char dias[DIAS][10] = {"Segunda", "Terca", "Quarta", "Quinta",
                           "Sexta", "Sabado", "Domingo"};
    int carros[DIAS];   // vetor: quantidade de carros em cada dia
    int total = 0;      // soma dos carros da semana
    int pico = 0;       // indice do dia com mais carros
    float media;        // media de carros por dia

    printf("==========================================\n");
    printf("   CONTROLE DE PEDAGIO - Fluxo semanal\n");
    printf("==========================================\n");
    printf("Informe quantos carros passaram em cada dia.\n\n");

    // 1) Leitura: um dia por volta do laco
    for (int i = 0; i < DIAS; i++) {
        printf("Carros - %s: ", dias[i]);
        while (scanf("%d", &carros[i]) != 1 || carros[i] < 0) {
            while (getchar() != '\n');   // descarta o que foi digitado errado
            printf("Valor invalido. Digite um numero inteiro, zero ou maior: ");
        }
    }

    // 2) Processamento: soma e procura do dia de pico
    for (int i = 0; i < DIAS; i++) {
        total = total + carros[i];
        if (carros[i] > carros[pico]) {
            pico = i;   // este dia passou o pico anterior: guarda a posicao dele
        }
    }
    media = (float) total / DIAS;   // (float) evita a divisao inteira, que cortaria as decimais

    // 3) Exibicao: tabela com o dia de pico destacado
    printf("\n------------- RELATORIO DA SEMANA -------------\n");
    printf("%-10s | %8s\n", "Dia", "Carros");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < DIAS; i++) {
        if (i == pico) {
            // \033[1;33m liga negrito amarelo e \033[0m volta ao normal
            printf("\033[1;33m%-10s | %8d  <-- PICO\033[0m\n", dias[i], carros[i]);
        } else {
            printf("%-10s | %8d\n", dias[i], carros[i]);
        }
    }
    printf("-----------------------------------------------\n");
    printf("Total da semana: %d carros\n", total);
    printf("Media por dia:   %.1f carros\n", media);
    printf("Dia de pico:     %s, com %d carros\n", dias[pico], carros[pico]);
    printf("===============================================\n");

    return 0;
}
