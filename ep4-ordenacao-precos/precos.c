#include <stdio.h>
#include <string.h>

int main() {
    // nome de cada produto, na mesma posicao do seu preco
    char produtos[10][20] = {"Arroz 5kg", "Feijao 1kg", "Leite 1L", "Cafe 500g", "Acucar 1kg",
                             "Oleo 900ml", "Macarrao 500g", "Ovos (duzia)", "Pao de forma", "Manteiga 200g"};
    // precos de 10 produtos de supermercado, em reais
    float precos[10] = {24.90, 8.49, 5.29, 19.90, 4.79, 7.99, 4.39, 12.50, 9.90, 13.75};
    float aux;          // guarda um preco durante a troca
    char auxNome[20];   // guarda um nome durante a troca

    printf("==========================================\n");
    printf("   PRECOS DO SUPERMERCADO - Bubble Sort\n");
    printf("==========================================\n");

    // 1) Dados originais, na ordem em que foram declarados
    printf("\n--- Precos originais (sem ordem) ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%-15s R$ %6.2f\n", produtos[i], precos[i]);
    }
    // 2) Bubble Sort crescente: do mais barato para o mais caro
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - 1 - i; j++) {
            if (precos[j] > precos[j + 1]) {
                aux = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = aux;
                // o nome troca junto, para continuar ao lado do seu preco
                strcpy(auxNome, produtos[j]);
                strcpy(produtos[j], produtos[j + 1]);
                strcpy(produtos[j + 1], auxNome);
            }
        }
    }
    printf("\n--- Ordem crescente (mais barato primeiro) ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%-15s R$ %6.2f\n", produtos[i], precos[i]);
    }
    // 3) Bubble Sort decrescente: so o sinal do if muda, de > para <
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - 1 - i; j++) {
            if (precos[j] < precos[j + 1]) {
                aux = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = aux;
                strcpy(auxNome, produtos[j]);
                strcpy(produtos[j], produtos[j + 1]);
                strcpy(produtos[j + 1], auxNome);
            }
        }
    }
    printf("\n--- Ordem decrescente (mais caro primeiro) ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%-15s R$ %6.2f\n", produtos[i], precos[i]);
    }

    printf("\n==========================================\n");
    return 0;
}