#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct no No;

struct lista {
    No *head; // Cabeça da lista
    int qtd;  // Quantidade de elementos da lista
};

struct no {
    Aluno a;
    No *prox;
};


/**
 * Cria uma lista encadeada vazia.
 * @return: um ponteiro para lista encadeada.
 */
Lista *cria_lista() {
    Lista *l = (Lista *) malloc(sizeof(struct lista));

    if (l != NULL) {
        l->head = NULL;
        l->qtd = 0;
    }

    return l;
}

/**
 * Destroi a lista encadeada e libera o espaço por ela ocupado na memória.
 * @param l: ponteiro para lista encadeada.
 */
void libera_lista(Lista *l) {
    if (l != NULL) {
        No *atual = l->head, *aux;

        // Destruindo cada ponteiro da lista encadeada
        while (atual != NULL) {
            aux = atual;
            atual = atual->prox;
            free(aux);
        }

        // Liberando a lista encadeada
        free(l);
    }
}

/**
 * Insere um novo elemento no inicio da lista encadeada.
 * @param l: um ponteiro para lista.
 * @param a: novo elemento da lista.
 * @return: um codigo de erro.
 */
int insere_inicio(Lista *l, Aluno a) {
    if (l == NULL)
        return LIST_NULL_POINTER_ERROR;

    No *novo_no = (No *) malloc(sizeof(struct no));

    if (novo_no == NULL)
        return LIST_OUT_OF_MEMORY;

    novo_no->a = a;
    novo_no->prox = l->head;
    l->head = novo_no;
    l->qtd ++;

    return LIST_SUCCESS;
}

/**
 * Exibe todos os valores armazenados na lista encadeada.
 * @param l: um ponteiro para lista.
 * @return: codigo de erro da função.
 */
int print_lista(Lista *l) {
    if (!l)
        return LIST_NULL_POINTER_ERROR;

    No *atual = l->head;

    while (atual) {
        printf("---------------------\n");
        printf("Nome: %s\n", (atual->a).nome);
        printf("Matricula: %d\n", (atual->a).matricula);
    }

    return LIST_SUCCESS;
}

/**
 * Remove um elemento do inicio da lista.
 * @param l: uma lista encadeada.
 * @param a: um ponteiro para aluno. Esse ponteiro armazena o valor removido
 * para fins de consulta.
 */
int remove_inicio(Lista *l, Aluno *a) {
    if (!l)
        return LIST_NULL_POINTER_ERROR;
    else if (!l->head)
        return LIST_EMPTY;

    No *atual = l->head;

    strncpy(a->nome, (atual->a).nome, 30);
    a->matricula = (atual->a).matricula;

    l->head = atual->prox;
    free(atual);
    l->qtd --;

    return LIST_SUCCESS;
}

/**
 * Calcula o tamanho da lista.
 * @param l: ponteiro para lista.
 * @return: o tamanho da lista ou um código de erro.
 */
int tamanho_lista(Lista *l) {
    if (l == NULL)
        return LIST_NULL_POINTER_ERROR;

    return l->qtd;
}
