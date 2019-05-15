#include "aluno.h"

#define STACK_SUCCESS             0
#define STACK_NULL_POINTER_ERROR -1
#define STACK_OUT_OF_MEMORY      -2
#define STACK_EMPTY              -3

typedef struct pilha Pilha;

/**
 * Cria uma nova pilha na memória e retorna um ponteiro para pilha.
 * @return: um ponteiro para pilha.
 */
Pilha *cria_pilha();

/**
 * Libera o espaço ocupado pela pilha e desaloca os endereços de memória
 * ocupados por ela.
 * @param p: um endereço de memória.
 */
void libera_pilha(Pilha *p);

/**
 * Exibe o conteúdo da pilha.
 * @param p: ponteiro para pilha.
 * @return: codigo de erro da funcao.
 */
int print_pilha(Pilha *p);

/**
 * Remove um elemento do topo da pilha.
 * @param p: um ponteiro para pilha.
 * @param a: um ponteiro para aluno para armazenar o valor removido.
 * @return: codigo de erro da funcao.
 */
int pop_pilha(Pilha *p, Aluno *a);

/**
 * Insere um aluno na pilha.
 * @param p: um ponteiro para pilha.
 * @param a: um elemento para ser inserido na pilha.
 * @return: o código de erro da função.
 */
int push_pilha(Pilha *p, Aluno a);

/**
 * Calcula o tamanho da pilha.
 * @param p: o ponteiro para pilha.
 * @return: o tamanho da pilha ou um código de erro.
 */
int tamanho_pilha(Pilha *p);
