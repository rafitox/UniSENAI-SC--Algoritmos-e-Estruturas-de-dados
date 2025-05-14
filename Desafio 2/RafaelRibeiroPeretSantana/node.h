#ifndef NODO_H
#define NODO_H

#include "cliente.h"

typedef struct Nodo {
    Cliente* cliente;
    struct Nodo* prox;
} Nodo;

typedef Nodo Node; // Add this line to alias Nodo as Node

Nodo* cria_nodo(Cliente* cliente);
void libera_nodo(Nodo* nodo);

#endif // NODO_H
