
#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct requisicao Requisicao;

// Cria nova requisição com o nome, inscricao e procedimento
Requisicao* cria_requisicao(char* nome, int inscricao, char* procedimento);

// Retorna o nome
char* get_nome(Requisicao* r);

// Retorna o número de inscrição da requisição
int get_inscricao(Requisicao* r);

// Retorna o procedimento da requisição
char* get_procedimento(Requisicao* r);

// libera a memória alocada na requisição
void libera(Requisicao* r);

#endif
