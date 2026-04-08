#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;

    Lista->Primeiro->Prox = NULL;
    Lista->Primeiro->Ant = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    TipoApontador novo;

    novo = (TipoApontador) malloc(sizeof(TipoCelula));

    novo->Item = x;
    novo->Prox = NULL;
    novo->Ant = Lista->Ultimo;

    Lista->Ultimo->Prox = novo;
    Lista->Ultimo = novo;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    if (Vazia(*Lista) || p == NULL || p == Lista->Primeiro) {
        printf("Erro\n");
        return;
    }

    *Item = p->Item;

    p->Ant->Prox = p->Prox;

    if (p->Prox != NULL) {
        p->Prox->Ant = p->Ant;
    }

    if (p == Lista->Ultimo) {
        Lista->Ultimo = p->Ant;
    }

    free(p);
}

void Imprime(TipoLista Lista) {
    TipoApontador p = Lista.Primeiro->Prox;

    while (p != NULL) {
        printf("%d\n", p->Item.Chave);
        p = p->Prox;
    }
}

void Inverte(TipoLista *Lista) {
    TipoApontador p = Lista->Primeiro->Prox;
    TipoApontador temp;

    Lista->Ultimo = p;

    while (p != NULL) {
        temp = p->Prox;
        p->Prox = p->Ant;
        p->Ant = temp;
        p = temp;
    }

    if (Lista->Ultimo != NULL) {
        Lista->Primeiro->Prox = Lista->Ultimo;
        Lista->Ultimo->Ant = Lista->Primeiro;
    }
}
