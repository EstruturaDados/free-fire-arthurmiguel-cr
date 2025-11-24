#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int total = 0;

void limparBuffer() {
    while (getchar() != '\n');
}

// Inserir item
void inserirItem() {
    if (total >= MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }

    Item novo;
    printf("Nome: ");
    scanf("%s", novo.nome);
    limparBuffer();

    printf("Tipo: ");
    scanf("%s", novo.tipo);
    limparBuffer();

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    limparBuffer();

    mochila[total] = novo;
    total++;

    printf("Item adicionado!\n");
}

// Remover item
void removerItem() {
    char nome[30];
    printf("Nome do item para remover: ");
    scanf("%s", nome);
    limparBuffer();

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            total--;
            printf("Item removido!\n");
            return;
        }
    }

    printf("Item nao encontrado.\n");
}

// Listar itens
void listarItens() {
    if (total == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- Itens da mochila ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("-------------------------\n\n");
}

// Buscar item
void buscarItem() {
    char nome[30];
    printf("Nome do item para buscar: ");
    scanf("%s", nome);
    limparBuffer();

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("Item nao encontrado.\n");
}

int main() {
    int opcao;

    do {
        printf("\n1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("Fechando...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}