
#ifndef LISTA_H
#define LISTA_H

#include "node.h"

typedef struct Lista {
    Nodo* inicio;
} Lista;

Lista* cria_lista();
void insere_lista(Lista* lista, Cliente* cliente);
void imprime_lista(const Lista* lista);
void libera_lista(Lista* lista);

#endif // LISTA_H
