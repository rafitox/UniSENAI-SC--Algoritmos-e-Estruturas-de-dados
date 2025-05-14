#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "cliente.h"
#include "lista.h"

#define TAM_HASH 101

typedef struct Base {
    Lista* por_nome[TAM_HASH];
    Lista* por_bairro[TAM_HASH];
    Lista* por_moradores[6];
    Lista* por_criancas[2];
    Lista* por_salario[5];
} Estrutura;

Estrutura* cria_estrutura();
void insere_cliente(Estrutura* sistema, int tipo, Cliente* rc);
Lista* recupera_cliente(Estrutura* sistema, int tipo, int dado, char* chave);
void destruir_base(Estrutura* sistema);

#endif
