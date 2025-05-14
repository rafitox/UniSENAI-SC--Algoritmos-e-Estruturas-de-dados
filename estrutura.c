#include "estrutura.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    Requisicao* requisicao;
    struct node* next;
} Node;

struct estrutura {
    Node* front;
    Node* rear;
    int size;
};

Estrutura* create() {
    Estrutura* e = (Estrutura*)malloc(sizeof(Estrutura));
    if (e == NULL) {
        fprintf(stderr, "Falha ao alocar memória em Estrutura\n");
        return NULL;
    }
    e->front = NULL;
    e->rear = NULL;
    e->size = 0;
    return e;
}

int inserir(Estrutura* e, Requisicao* r) {
    if (e == NULL || r == NULL) {
        return 0; // Failed
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Falha ao alocar memória\n");
        return 0; // Failed
    }
    
    newNode->requisicao = r;
    newNode->next = NULL;
    
    if (e->rear == NULL) {
        e->front = e->rear = newNode;
    } else {
        e->rear->next = newNode;
        e->rear = newNode;
    }
    e->size++;
    return 1; // Success
}

Requisicao* remover(Estrutura* e) {
    if (e == NULL || e->front == NULL) {
        return NULL;
    }
    
    Node* temp = e->front;
    Requisicao* r = temp->requisicao;
    
    e->front = e->front->next;
    if (e->front == NULL) {
        e->rear = NULL;
    }
    
    free(temp);
    e->size--;
    return r;
}

int get_size(Estrutura* e) {
    if (e == NULL) {
        return -1; // Error
    }
    return e->size;
}

void destroy_queue(Estrutura* e) {
    if (e == NULL) {
        return;
    }
    
    while (e->front != NULL) {
        Node* temp = e->front;
        e->front = e->front->next;
        
        // Libera a memória da requisição
        if (temp->requisicao != NULL) {
            libera(temp->requisicao);
        }
        
        free(temp);
    }
    
    free(e);
}
