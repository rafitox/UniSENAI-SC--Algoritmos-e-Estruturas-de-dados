#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct RegistroDosClientes {
    char identificador[41];
    char localizacao[41];
    int moradores;
    int tem_criancas;
    double salario;
} Cliente;

Cliente* cria_cliente(char* identificador, char* localizacao, int moradores, int tem_criancas, double salario);
const char* get_nome(Cliente* cliente);
const char* get_bairro(Cliente* cliente);
int get_pessoas(Cliente* cliente);
int get_criancas(Cliente* cliente);
double get_renda(Cliente* cliente);
void apagar_cliente(Cliente* cliente);

#endif
