#ifndef LISTA_H
#define LISTA_H

#include "node.h"

typedef struct Lista {
    Node* inicio;
    int tamanho;
} Lista;

Lista* cria_lista();
void libera_lista(Lista* lista);
void insere_lista(Lista* lista, Cliente* rc);
void imprime_lista(Lista* lista);
int get_quantidade(Lista* lista);
Node* get_inicio(Lista* lista);

#endif
