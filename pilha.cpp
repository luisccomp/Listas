#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

struct pilha {
    Lista *l;
};

/**
 * Cria uma nova pilha na memória e retorna um ponteiro para pilha.
 * @return: um ponteiro para pilha.
 */
Pilha *cria_pilha() {
    Pilha *p = (Pilha *) malloc(sizeof(struct pilha));

    if (p != NULL) {
        p->l = cria_lista();

        // Se a instanciação da lista encadeada der errado, então a pilha não
        // deve existir.
        if (p->l == NULL) {
            free(p);
            p = NULL;
        }
    }

    return p;
}

/**
 * Libera o espaço ocupado pela pilha e desaloca os endereços de memória
 * ocupados por ela.
 * @param p: um endereço de memória.
 */
void libera_pilha(Pilha *p) {
    if (p != NULL) {
        libera_lista(p->l);
        free(p);
    }
}

/**
 * Remove um elemento do topo da pilha.
 * @param p: um ponteiro para pilha.
 * @param a: um ponteiro para aluno para armazenar o valor removido.
 * @return: codigo de erro da funcao.
 */
int pop_pilha(Pilha *p, Aluno *a) {
    if (!p)
        return STACK_NULL_POINTER_ERROR;

    return remove_inicio(p->l, a);
}

/**
 * Insere um aluno na pilha.
 * @param p: um ponteiro para pilha.
 * @param a: um elemento para ser inserido na pilha.
 * @return: o código de erro da função.
 */
int push_pilha(Pilha *p, Aluno a) {
    if (!p)
        return STACK_NULL_POINTER_ERROR;

    return insere_inicio(p->l, a);
}

/**
 * Calcula o tamanho da pilha.
 * @param p: o ponteiro para pilha.
 * @return: o tamanho da pilha ou um código de erro.
 */
int tamanho_pilha(Pilha *p) {
    if (!p)
        return STACK_NULL_POINTER_ERROR;

    return tamanho_lista(p->l);
}
