#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

static int gerar_hash(const char* texto) {
    int valor = 0;
    while (*texto)
        valor = (valor * 31 + *texto++) % TAM_HASH;
    return valor;
}

static int classifica_salario(double renda) {
    if (renda <= 2000.00) return 1;
    if (renda <= 3000.00) return 2;
    if (renda <= 5000.00) return 3;
    return 4;
}

Estrutura* cria_estrutura() {
    Estrutura* sistema = malloc(sizeof(Estrutura));
    for (int i = 0; i < TAM_HASH; i++) {
        sistema->por_nome[i] = cria_lista();
        sistema->por_bairro[i] = cria_lista();
    }
    for (int i = 0; i <= 5; i++) sistema->por_moradores[i] = cria_lista();
    for (int i = 0; i <= 1; i++) sistema->por_criancas[i] = cria_lista();
    for (int i = 1; i <= 4; i++) sistema->por_salario[i] = cria_lista();
    return sistema;
}

void insere_cliente(Estrutura* sistema, int tipo, Cliente* rc) {
    int indice;
    switch (tipo) {
        case 1:
            indice = gerar_hash(get_nome(rc));
            insere_lista(sistema->por_nome[indice], rc);
            break;
        case 2:
            indice = gerar_hash(get_bairro(rc));
            insere_lista(sistema->por_bairro[indice], rc);
            break;
        case 3:
            insere_lista(sistema->por_moradores[get_pessoas(rc)], rc);
            break;
        case 4:
            insere_lista(sistema->por_criancas[get_criancas(rc)], rc);
            break;
        case 5:
            insere_lista(sistema->por_salario[classifica_salario(get_renda(rc))], rc);
            break;
    }
}

Lista* recupera_cliente(Estrutura* sistema, int tipo, int dado, char* chave) {
    int indice;
    switch (tipo) {
        case 1:
            if (!chave) return cria_lista();
            indice = gerar_hash(chave);
            return sistema->por_nome[indice];
        case 2:
            if (!chave) return cria_lista();
            indice = gerar_hash(chave);
            return sistema->por_bairro[indice];
        case 3:
            return sistema->por_moradores[dado];
        case 4:
            return sistema->por_criancas[dado];
        case 5:
            return sistema->por_salario[dado];
    }
    return cria_lista();
}

void destruir_base(Estrutura* sistema) {
    for (int i = 0; i < TAM_HASH; i++) {
        libera_lista(sistema->por_nome[i]);
        libera_lista(sistema->por_bairro[i]);
    }
    for (int i = 0; i <= 5; i++) libera_lista(sistema->por_moradores[i]);
    for (int i = 0; i <= 1; i++) libera_lista(sistema->por_criancas[i]);
    for (int i = 1; i <= 4; i++) libera_lista(sistema->por_salario[i]);
    free(sistema);
}
