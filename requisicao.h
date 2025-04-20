
#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct requisicao Requisicao;

// Creates a new request with the given name, inscription number, and procedure
Requisicao* cria_requisicao(char* nome, int inscricao, char* procedimento);

// Returns the name of the request
char* get_nome(Requisicao* r);

// Returns the inscription number of the request
int get_inscricao(Requisicao* r);

// Returns the procedure of the request
char* get_procedimento(Requisicao* r);

// Frees memory allocated for a request
void libera(Requisicao* r);

#endif