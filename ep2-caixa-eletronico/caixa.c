#include <stdio.h>

int main() {
    printf("==========================================\n");
    printf("   MEU CAIXA - Caixa Eletronico Simples\n");
    printf("==========================================\n");
    printf("Aqui voce pode consultar seu saldo, depositar e sacar.\n");
    printf("Ola! Seja bem-vindo(a) ao seu caixa.\n\n");

    int opcao;
    float saldo = 500.00;   // saldo base definido no inicio (desafio bonus)
    float valor;            // valor digitado no deposito ou no saque

    do {
        printf("\n---------------- MENU ----------------\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');   // descarta o que foi digitado errado
            opcao = -1;                  // forca cair no default
        }

        switch (opcao) {
            case 1:
                printf("Seu saldo atual e: R$ %.2f\n", saldo);
                break;

            case 2:
                printf("Valor do deposito: R$ ");
                if (scanf("%f", &valor) != 1) {
                    while (getchar() != '\n');
                    valor = 0;
                }
                if (valor <= 0) {
                    printf("Valor invalido. O deposito precisa ser maior que zero.\n");
                } else {
                    saldo = saldo + valor;
                    printf("Deposito feito! Novo saldo: R$ %.2f\n", saldo);
                }
                break;

            case 3:
                printf("Valor do saque: R$ ");
                if (scanf("%f", &valor) != 1) {
                    while (getchar() != '\n');
                    valor = 0;
                }
                if (valor <= 0) {
                    printf("Valor invalido. O saque precisa ser maior que zero.\n");
                } else if (valor > saldo) {
                    printf("Saque negado: o valor e maior que o seu saldo (R$ %.2f).\n", saldo);
                } else {
                    saldo = saldo - valor;
                    printf("Saque feito! Novo saldo: R$ %.2f\n", saldo);
                }
                break;

            case 0:
                printf("Encerrando o atendimento...\n");
                break;

            default:
                printf("Opcao invalida. Escolha 1, 2, 3 ou 0.\n");
        }

    } while (opcao != 0);
    
    printf("\n==========================================\n");
    printf("Saldo final da sua conta: R$ %.2f\n", saldo);
    printf("Obrigado por usar o MEU CAIXA. Ate a proxima!\n");
    printf("==========================================\n");

    return 0;
}
