#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "lista.h"

#define TAM_TABELA 101

typedef struct Estrutura {
    Lista* tabela_nome[TAM_TABELA];
    Lista* tabela_bairro[TAM_TABELA];
    Lista* tabela_pessoas[6];
    Lista* tabela_criancas[2];
    Lista* tabela_renda[4];
} Estrutura;

Estrutura* cria_estrutura();
void insere_cliente(Estrutura* estrutura, int criterio, Cliente* cliente);  // Added criterio parameter
Lista* recupera_cliente(Estrutura* estrutura, int criterio, int complemento, char* busca);
void libera_estrutura(Estrutura* estrutura);

#endif // ESTRUTURA_H
