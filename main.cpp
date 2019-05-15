#include <stdio.h>
#include "pilha.h"

int main(int argc, char **argv) {
    Aluno a[] = {{"Marcos", 1}, {"Pedro", 2}, {"Gabriela", 3}, {"Alice", 4}, {"Maria", 5}};
    Aluno aluno;
    Pilha *p;

    p = cria_pilha();

    for (int i = 0; i < 5; i ++)
        push_pilha(p, a[i]);

    if (pop_pilha(p, &aluno) == STACK_SUCCESS) {
        printf(":.:.: Aluno removido :.:.:\n");
        printf("Nome: %s\n", aluno.nome);
        printf("Matricula: %d\n", aluno.matricula);
    }
    else {
        printf("Erro ao remover aluno....");
    }

    printf("Tamanho da pilha: %d\n", tamanho_pilha(p));

    return 0;
}
