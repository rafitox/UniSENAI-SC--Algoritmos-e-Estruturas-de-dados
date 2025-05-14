#include "estrutura.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    Requisicao* requisicao;
    struct node* next;
} Node;

struct estrutura {
    Node* inicio_da_fila;
    Node* fim_da_fila;
    int size;
};

Estrutura* create() {
    Estrutura* e = malloc(sizeof(Estrutura));
    if (e == NULL) {
        fprintf(stderr, "Falha ao alocar memória em Estrutura\n");
        return NULL;
    }
    e->inicio_da_fila = NULL;
    e->fim_da_fila = NULL;
    e->size = 0;
    return e;
}

int inserir(Estrutura* e, Requisicao* r) {
    if (e == NULL || r == NULL) {
        return 0; // Falhou
    }

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Falha ao alocar memória\n");
        return 0; // Falhou
    }
    
    newNode->requisicao = r;
    newNode->next = NULL;
    
    if (e->fim_da_fila == NULL) {
        e->inicio_da_fila = e->fim_da_fila = newNode;
    } else {
        e->fim_da_fila->next = newNode;
        e->fim_da_fila = newNode;
    }
    e->size++;
    return 1; // Successo
}

Requisicao* remover(Estrutura* e) {
    if (e == NULL || e->inicio_da_fila == NULL) {
        return NULL;
    }
    
    Node* temp = e->inicio_da_fila;
    Requisicao* r = temp->requisicao;
    
    e->inicio_da_fila = e->inicio_da_fila->next;
    if (e->inicio_da_fila == NULL) {
        e->fim_da_fila = NULL;
    }
    
    free(temp);
    e->size--;
    return r;
}

int get_size(Estrutura* e) {
    if (e == NULL) {
        return -1; // Falhou
    }
    return e->size;
}

void destroy_queue(Estrutura* e) {
    if (e == NULL) {
        return;
    }
    
    while (e->inicio_da_fila != NULL) {
        Node* temp = e->inicio_da_fila;
        e->inicio_da_fila = e->inicio_da_fila->next;
        
        // Libera a memória da requisição
        if (temp->requisicao != NULL) {
            libera(temp->requisicao);
        }
        
        free(temp);
    }
    
    free(e);
}
