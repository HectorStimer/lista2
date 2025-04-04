#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

void insert(int list[], int *count, int value);
void removeValue(int list[], int *count, int value);
int binarySearch(int list[], int count, int value);
void traverse(int list[], int count);
void printMenu();

int main() {
    int list[SIZE] = {0};
    int count = 0;
    int option, value;

    do {
        printMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (count < SIZE) {
                    printf("Digite o valor para inserir: ");
                    scanf("%d", &value);
                    insert(list, &count, value);
                } else {
                    printf("A lista está cheia!\n");
                }
                break;
            case 2:
                printf("Digite o valor para remover: ");
                scanf("%d", &value);
                removeValue(list, &count, value);
                break;
            case 3:
                printf("Digite o valor para buscar: ");
                scanf("%d", &value);
                int index = binarySearch(list, count, value);
                if (index != -1) {
                    printf("Valor encontrado na posição %d.\n", index);
                } else {
                    printf("Valor não encontrado.\n");
                }
                break;
            case 4:
                traverse(list, count);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 0);

    return 0;
}

void insert(int list[], int *count, int value) {
    int i = *count - 1;
    while (i >= 0 && list[i] < value) {
        list[i + 1] = list[i];
        i--;
    }
    list[i + 1] = value;
    (*count)++;
    printf("Valor inserido com sucesso.\n");
}

void removeValue(int list[], int *count, int value) {
    int index = binarySearch(list, *count, value);
    if (index != -1) {
        for (int i = index; i < *count - 1; i++) {
            list[i] = list[i + 1];
        }
        (*count)--;
        printf("Valor removido com sucesso.\n");
    } else {
        printf("Valor não encontrado na lista.\n");
    }
}

int binarySearch(int list[], int count, int value) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (list[mid] == value) {
            return mid;
        } else if (list[mid] < value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void traverse(int list[], int count) {
    printf("Lista: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Inserir dados na lista\n");
    printf("2. Remover dados da lista\n");
    printf("3. Buscar um valor na lista\n");
    printf("4. Percorrer a lista\n");
    printf("0. Sair\n");
}