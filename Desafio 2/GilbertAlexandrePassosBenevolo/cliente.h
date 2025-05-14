
#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h>

#define TAM_STRING 40

typedef struct Cliente {
    char nome[TAM_STRING];
    char bairro[TAM_STRING];
    int pessoas;
    bool criancas_pequenas;
    double renda;
} Cliente;

Cliente* cria_cliente(const char* nome, const char* bairro, int pessoas, bool criancas_pequenas, double renda);
void imprime_cliente(const Cliente* cliente);
void libera_cliente(Cliente* cliente);

#endif // CLIENTE_H
