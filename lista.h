#include "aluno.h"

#define LIST_SUCCESS             0
#define LIST_NULL_POINTER_ERROR -1
#define LIST_OUT_OF_MEMORY      -2
#define LIST_EMPTY              -3

typedef struct lista Lista;


/**
 * Cria uma lista encadeada vazia.
 * @return: um ponteiro para lista encadeada.
 */
Lista *cria_lista();

/**
 * Insere um novo elemento no inicio da lista encadeada.
 * @param l: um ponteiro para lista.
 * @param a: novo elemento da lista.
 * @return: um codigo de erro.
 */
int insere_inicio(Lista *l, Aluno a);

/**
 * Destroi a lista encadeada e libera o espaço por ela ocupado na memória.
 * @param l: ponteiro para lista encadeada.
 */
void libera_lista(Lista *l);

/**
 * Remove um elemento do inicio da lista.
 * @param l: uma lista encadeada.
 * @param a: um ponteiro para aluno. Esse ponteiro armazena o valor removido
 * para fins de consulta.
 */
int remove_inicio(Lista *l, Aluno *a);

/**
 * Retorna a quantidade de elementos armazenados na lista.
 * @param l: ponteiro para lista.
 * @return: o tamanho da lista ou um código de erro.
 */
int tamanho_lista(Lista *l);
