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

// Add these functions:
int get_quantidade(const Lista* lista);
Nodo* get_inicio(const Lista* lista);
Cliente* get_data(const Nodo* nodo);
Nodo* get_next(const Nodo* nodo);

#endif // LISTA_H
