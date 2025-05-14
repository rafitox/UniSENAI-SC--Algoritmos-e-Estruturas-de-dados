#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Lista* cria_lista() {
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    if (!nova) return NULL;
    nova->inicio = NULL;
    return nova;
}

void insere_lista(Lista* lista, Cliente* cliente) {
    if (!lista || !cliente) return;
    Nodo* novo = cria_nodo(cliente);
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void imprime_lista(const Lista* lista) {
    Nodo* atual = lista->inicio;
    while (atual) {
        imprime_cliente(atual->cliente);
        atual = atual->prox;
    }
}

void libera_lista(Lista* lista) {
    Nodo* atual = lista->inicio;
    while (atual) {
        Nodo* temp = atual;
        atual = atual->prox;
        libera_nodo(temp);
    }
    free(lista);
}

int get_quantidade(const Lista* lista) {
    int count = 0;
    Nodo* atual = lista->inicio;
    while (atual) {
        count++;
        atual = atual->prox;
    }
    return count;
}

Nodo* get_inicio(const Lista* lista) {
    return lista->inicio;
}

Cliente* get_data(const Nodo* nodo) {
    return nodo->cliente;
}

Nodo* get_next(const Nodo* nodo) {
    return nodo->prox;
}
