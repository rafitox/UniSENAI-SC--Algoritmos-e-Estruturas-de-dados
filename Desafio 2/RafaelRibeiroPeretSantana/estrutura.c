#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

static int hash_string(const char* str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (31 * hash + str[i]) % TAM_TABELA;
    }
    return hash;
}

static int faixa_renda(double renda) {
    if (renda <= 2000.0) return 0;
    else if (renda <= 3000.0) return 1;
    else if (renda <= 5000.0) return 2;
    else return 3;
}

Estrutura* cria_estrutura() {
    Estrutura* e = (Estrutura*) malloc(sizeof(Estrutura));
    if (!e) return NULL;
    
    for (int i = 0; i < TAM_TABELA; i++) {
        e->tabela_nome[i] = cria_lista();
        e->tabela_bairro[i] = cria_lista();
    }
    
    for (int i = 0; i < 6; i++) 
        e->tabela_pessoas[i] = cria_lista();
    
    for (int i = 0; i < 2; i++) 
        e->tabela_criancas[i] = cria_lista();
    
    for (int i = 0; i < 4; i++) 
        e->tabela_renda[i] = cria_lista();
    
    return e;
}

void insere_cliente(Estrutura* e, int criterio, Cliente* c) {
    switch(criterio) {
        case 1:
            insere_lista(e->tabela_nome[hash_string(c->nome)], c);
            break;
        case 2:
            insere_lista(e->tabela_bairro[hash_string(c->bairro)], c);
            break;
        case 3:
            insere_lista(e->tabela_pessoas[c->pessoas <= 5 ? c->pessoas : 5], c);
            break;
        case 4:
            insere_lista(e->tabela_criancas[c->criancas_pequenas ? 1 : 0], c);
            break;
        case 5:
            insere_lista(e->tabela_renda[faixa_renda(c->renda)], c);
            break;
        default:
            break;
    }
}

Lista* recupera_cliente(Estrutura* e, int criterio, int complemento, char* busca) {
    switch (criterio) {
        case 1:
            return e->tabela_nome[hash_string(busca)];
        case 2:
            return e->tabela_bairro[hash_string(busca)];
        case 3:
            return e->tabela_pessoas[(complemento <= 5 ? complemento : 5)];
        case 4:
            return e->tabela_criancas[complemento ? 1 : 0];
        case 5:
            return e->tabela_renda[complemento];
        default:
            return NULL;
    }
}

void libera_estrutura(Estrutura* e) {
    for (int i = 0; i < TAM_TABELA; i++) {
        libera_lista(e->tabela_nome[i]);
        libera_lista(e->tabela_bairro[i]);
    }
    for (int i = 0; i < 6; i++) 
        libera_lista(e->tabela_pessoas[i]);
    for (int i = 0; i < 2; i++) 
        libera_lista(e->tabela_criancas[i]);
    for (int i = 0; i < 4; i++) 
        libera_lista(e->tabela_renda[i]);
    free(e);
}
