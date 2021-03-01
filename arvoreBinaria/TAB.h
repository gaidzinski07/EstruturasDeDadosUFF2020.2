#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
    int info;
    struct arvbin *esq, *dir;
}TAB;

TAB* TAB_cria(int x, TAB* e, TAB* d);
void TAB_imprime(TAB *t);
void TAB_libera(TAB* t);
TAB* TAB_busca(int e, TAB* t);
TAB* copia (TAB *a);
TAB* espelho (TAB *a);
TAB* maior(TAB *a);
TAB* menor(TAB *a);
int igual (TAB* a1, TAB* a2);