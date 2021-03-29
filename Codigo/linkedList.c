#include "linkedList.h"

node* pop(node *inicio) {
    node *elemento_removido;
    /* Remove o primeiro elemento da lista */
    if (inicio == NULL)
        return NULL;

    /* Guardadar elemento removido para dar free */
    elemento_removido = inicio;

    /* Atualizar a cabeca da lista */
    inicio = inicio->proximo;

    free(elemento_removido);
    return inicio;
}

node* push(node *inicio, int elemento) {
    /* Adiciona um novo elemento ao inicio da lista */
    node *novo_no;

    /* Alocar memoria */
    novo_no = (node*) malloc(sizeof(node));

    /* Definir novo_no */
    novo_no->elemento = elemento;
    novo_no->proximo = inicio;

    return novo_no;
}

node* destroy(node *inicio) {
    /* Da free de todos os nos da lista */
    node *node_free;

    if (inicio == NULL)
        return NULL;

    while(inicio != NULL) {
        node_free = inicio;
        inicio = inicio->proximo;

        free(node_free);
    }

    return NULL;
}

void print(node *inicio) {
    /* Da display da lista no standard output */
    node *i;

    for (i = inicio; i != NULL; i = i->proximo)
        printf("%d\n", i->elemento);
}