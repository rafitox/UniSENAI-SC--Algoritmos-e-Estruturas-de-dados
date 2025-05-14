
#include <stdlib.h>
#include "node.h"

Nodo* cria_nodo(Cliente* cliente) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL) return NULL;
    novo->cliente = cliente;
    novo->prox = NULL;
    return novo;
}

void libera_nodo(Nodo* nodo) {
    if (nodo) {
        libera_cliente(nodo->cliente);
        free(nodo);
    }
}
