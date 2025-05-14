#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* cria_cliente(const char* nome, const char* bairro, int pessoas, bool criancas_pequenas, double renda) {
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    if (novo == NULL) return NULL;
    strncpy(novo->nome, nome, TAM_STRING);
    strncpy(novo->bairro, bairro, TAM_STRING);
    novo->pessoas = pessoas;
    novo->criancas_pequenas = criancas_pequenas;
    novo->renda = renda;
    return novo;
}

void imprime_cliente(const Cliente* cliente) {
    if (cliente == NULL) return;
    printf("Nome: %s\n", cliente->nome);
    printf("Bairro: %s\n", cliente->bairro);
    printf("Pessoas: %d\n", cliente->pessoas);
    printf("Crianças <5 anos: %s\n", cliente->criancas_pequenas ? "Sim" : "Não");
    printf("Renda: R$ %.2f\n", cliente->renda);
}

void libera_cliente(Cliente* cliente) {
    free(cliente);
}

const char* get_nome(const Cliente* cliente) {
    return cliente->nome;
}

const char* get_bairro(const Cliente* cliente) {
    return cliente->bairro;
}

int get_pessoas(const Cliente* cliente) {
    return cliente->pessoas;
}

bool get_criancas(const Cliente* cliente) {
    return cliente->criancas_pequenas;
}

double get_renda(const Cliente* cliente) {
    return cliente->renda;
}
