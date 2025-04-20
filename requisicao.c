#include "requisicao.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_NOME_LEN 40
#define MAX_PROC_LEN 10

struct requisicao {
    char nome_paciente[MAX_NOME_LEN + 1];  // 40 chars + null terminator
    int codigo_inscricao;
    char codigo_procedimento[MAX_PROC_LEN + 1];  // 10 chars + null terminator
};

Requisicao* cria_requisicao(char* nome, int inscricao, char* procedimento) {
    if (nome == NULL || procedimento == NULL) {
        return NULL;
    }
    
    Requisicao* req = (Requisicao*)malloc(sizeof(Requisicao));
    if (req == NULL) {
        fprintf(stderr, "Memory allocation failed for Requisicao\n");
        return NULL;
    }
    
    // Safe string copy with explicit null termination
    strncpy(req->nome_paciente, nome, MAX_NOME_LEN);
    req->nome_paciente[MAX_NOME_LEN] = '\0';
    
    req->codigo_inscricao = inscricao;
    
    strncpy(req->codigo_procedimento, procedimento, MAX_PROC_LEN);
    req->codigo_procedimento[MAX_PROC_LEN] = '\0';
    
    return req;
}

char* get_nome(Requisicao* r) {
    if (r == NULL) {
        return NULL;
    }
    return r->nome_paciente;
}

int get_inscricao(Requisicao* r) {
    if (r == NULL) {
        return -1;  // Error indicator
    }
    return r->codigo_inscricao;
}

char* get_procedimento(Requisicao* r) {
    if (r == NULL) {
        return NULL;
    }
    return r->codigo_procedimento;
}

void libera(Requisicao* r) {
    if (r != NULL) {
        free(r);
    }
}
