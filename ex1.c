#include <stdio.h>

#define MAX 100


int buscarSequencial(int vetor[], int tamanho, int elemento);
void inserirSemRepetir(int vetor[], int elemento, int *tamanho, int max);
void percorrer(int vetor[], int tamanho);

int main() {
    int lista[MAX];
    int tamanho = 0; 
    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir valor\n");
        printf("2. Exibir lista\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                inserirSemRepetir(lista, valor, &tamanho, MAX);
                break;
            case 2:
                percorrer(lista, tamanho);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}

int buscarSequencial(int vetor[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return 1; 
        }
    }
    return 0; 
}


void inserirSemRepetir(int vetor[], int elemento, int *tamanho, int max) {
    if (*tamanho >= max) {
        printf("Erro: Lista cheia!\n");
        return;
    }
    if (buscarSequencial(vetor, *tamanho, elemento)) {
        printf("Erro: Valor ja existe na lista!\n");
        return;
    }
    vetor[*tamanho] = elemento;
    (*tamanho)++;
    printf("Valor inserido com sucesso!\n");
}


void percorrer(int vetor[], int tamanho) {
    if (tamanho == 0) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("Elementos da lista: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}