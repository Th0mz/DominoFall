#include "linkedList.h"

/* Funcoes sobre lista jogos */
void initList(LinkedList *lista)
{
    /* Inicializa a lista como sendo uma lista vazia */
    lista->inicio = NULL;
}

void push(LinkedList *lista, int elemento) {
    /* Adiciona um novo elemento ao inicio da lista */
    node *novo_node;

    /* Alocar memoria */
    novo_node = (node*) malloc(sizeof(node));

    /* Definir novo_node */
    novo_node->elemento = elemento;

    novo_node->proximo = lista->inicio;
    lista->inicio = novo_node;

}

void destroy(LinkedList *lista) {
    /* Liberta memoria de uma lista de jogos */
    node *node, *proximo_node;

    node = lista->inicio;

    while(node != NULL) {
        proximo_node = node->proximo;
        free(node);
        node = proximo_node;
    }
}

void print(LinkedList *lista) {
    /* Da display da lista no standard output */
    node *i;

    for (i = lista->inicio; i != NULL; i = i->proximo)
        printf("%d\n", i->elemento);
}