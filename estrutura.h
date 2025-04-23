#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct estrutura Estrutura;

/**
 * Cria uma nova fila 
 * @return ponteiro ou NULL se a alocação de memória falhar
 */
Estrutura* create();

/**
 * Insere a requisição no fim da fila
 * @param e Estrutura da fila
 * @param r Requisição para inserir
 * @return 1 sucesso, 0 falha
 */
int inserir(Estrutura* e, Requisicao* r);

/**
 * Remove e returna a primeira requisição da fila
 * @param e Estrutura da fila
 * @return Ponteiro ou NULL se a fila estiver vazia
 */
Requisicao* remover(Estrutura* e);

/**
 * Retorna o número de requisições na fila 
 * @param e Estrutura da fila
 * @return Número de requisiçoes na fila, retorna -1 em caso de erro ou NULL
 */
int get_size(Estrutura* e);

/**
 * libera memória usada na estrutura da fila e seus elementos
 * @param e Destrói a fila
 */
void destroy_queue(Estrutura* e);

#endif
