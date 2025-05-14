#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* cria_cliente(char* identificador, char* localizacao, int moradores, int tem_criancas, double salario) {
    Cliente* novo = malloc(sizeof(Cliente));
    strncpy(novo->identificador, identificador, 40);
    novo->identificador[40] = '\0';
    strncpy(novo->localizacao, localizacao, 40);
    novo->localizacao[40] = '\0';
    novo->moradores = moradores > 5 ? 5 : moradores;
    novo->tem_criancas = tem_criancas;
    novo->salario = salario;
    return novo;
}

const char* get_nome(Cliente* cliente) { return cliente->identificador; }
const char* get_bairro(Cliente* cliente) { return cliente->localizacao; }
int get_pessoas(Cliente* cliente) { return cliente->moradores; }
int get_criancas(Cliente* cliente) { return cliente->tem_criancas; }
double get_renda(Cliente* cliente) { return cliente->salario; }

void apagar_cliente(Cliente* cliente) {
    free(cliente);
}
