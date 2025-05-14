#ifndef NODE_H
#define NODE_H

#include "cliente.h"

typedef struct Nodo {
    Cliente* dado;
    struct Nodo* proximo;
} Node;

Node* criar_node(Cliente* dado);
void destruir_node(Node* node);
Cliente* get_data(Node* node);
Node* get_next(Node* node);

#endif
