#include <stdlib.h>
#include "node.h"

Node* criar_node(Cliente* dado) {
    Node* novo = malloc(sizeof(Node));
    novo->dado = dado;
    novo->proximo = NULL;
    return novo;
}

void destruir_node(Node* node) {
    if (node) free(node);
}

Cliente* get_data(Node* node) {
    return node->dado;
}

Node* get_next(Node* node) {
    return node->proximo;
}
