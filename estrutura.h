#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct estrutura Estrutura;

/**
 * Creates a new empty queue structure
 * @return Pointer to new queue or NULL if allocation failed
 */
Estrutura* create();

/**
 * Inserts a request at the end of the queue
 * @param e The queue structure
 * @param r The request to insert
 * @return 1 on success, 0 on failure
 */
int inserir(Estrutura* e, Requisicao* r);

/**
 * Removes and returns the first request from the queue
 * @param e The queue structure
 * @return Pointer to removed request or NULL if queue is empty
 */
Requisicao* remover(Estrutura* e);

/**
 * Returns the current number of requests in the queue
 * @param e The queue structure
 * @return Number of requests in queue or -1 if e is NULL
 */
int get_size(Estrutura* e);

/**
 * Frees all memory used by the queue structure and its elements
 * @param e The queue structure to destroy
 */
void destroy_queue(Estrutura* e);

#endif
