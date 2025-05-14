#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* cria_lista() {
    Lista* lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void libera_lista(Lista* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        Node* temp = atual;
        atual = get_next(atual);
        destruir_node(temp);
    }
    free(lista);
}

void insere_lista(Lista* lista, Cliente* rc) {
    Node* novo = criar_node(rc);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

void imprime_lista(Lista* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        Cliente* rc = get_data(atual);
        printf("Nome: %s\n", get_nome(rc));
        atual = get_next(atual);
    }
}

int get_quantidade(Lista* lista) {
    return lista->tamanho;
}

Node* get_inicio(Lista* lista) {
    return lista->inicio;
}
