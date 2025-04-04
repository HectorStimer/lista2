#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int conta;
    float saldo;
} Cliente;

typedef struct {
    Cliente clientes[MAX];
    int tamanho;
} Lista;

void inicializarLista(Lista *lista) {
    lista->tamanho = 0;
}

void adicionarCliente(Lista *lista, char nome[], int conta, float saldo) {
    if (lista->tamanho < MAX) {
        strcpy(lista->clientes[lista->tamanho].nome, nome);
        lista->clientes[lista->tamanho].conta = conta;
        lista->clientes[lista->tamanho].saldo = saldo;
        lista->tamanho++;
    } else {
        printf("Lista cheia! Não é possível adicionar mais clientes.\n");
    }
}

int buscarPorConta(Lista *lista, int conta) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->clientes[i].conta == conta) {
            return i;
        }
    }
    return -1;
}

int buscarPorNome(Lista *lista, char nome[]) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->clientes[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void exibirCliente(Cliente cliente) {
    printf("Nome: %s\n", cliente.nome);
    printf("Conta: %d\n", cliente.conta);
    printf("Saldo: %.2f\n", cliente.saldo);
}

void buscarCliente(Lista *lista, int conta, char nome[]) {
    int indice = buscarPorConta(lista, conta);
    if (indice != -1) {
        printf("Cliente encontrado pelo número da conta:\n");
        exibirCliente(lista->clientes[indice]);
    } else {
        indice = buscarPorNome(lista, nome);
        if (indice != -1) {
            printf("Cliente encontrado pelo nome:\n");
            exibirCliente(lista->clientes[indice]);
        } else {
            printf("Cliente não encontrado.\n");
        }
    }
}

void exibirTodosClientes(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Cliente %d:\n", i + 1);
        exibirCliente(lista->clientes[i]);
        printf("\n");
    }
}

int main() {
    Lista lista;
    inicializarLista(&lista);

    adicionarCliente(&lista, "Hector", 12345, 1000.50);
    adicionarCliente(&lista, "Maria", 67890, 2000.75);
    adicionarCliente(&lista, "João", 54321, 1500.00);

    printf("Exibindo todos os clientes:\n");
    exibirTodosClientes(&lista);

    printf("\nBuscando cliente com conta 12345:\n");
    buscarCliente(&lista, 12345, "");

    printf("\nBuscando cliente com nome 'Maria':\n");
    buscarCliente(&lista, -1, "Maria");

    printf("\nBuscando cliente inexistente:\n");
    buscarCliente(&lista, 99999, "Carlos");

    return 0;
}
