#include "TAB.h"
#include <stdio.h>
#include <limits.h>

void TAB_libera(TAB* t){
  if(t){
    TAB_libera(t->esq);
    TAB_libera(t->dir);
    free(t);
  }
}

TAB* TAB_busca(int e, TAB* t){
  if((!t) || (t->info == e)) return t;
  TAB *resp = TAB_busca(e, t->esq);
  if(resp) return resp;
  return TAB_busca(e, t->dir);
}

void imprime_aux(TAB* a, int andar){
  if(a){
    int j;
    imprime_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("   ");
    printf("%d\n", a->info);
    imprime_aux(a->dir, andar + 1);
  }
}

void TAB_imprime(TAB* a){
  imprime_aux(a, 1);
}

TAB* TAB_cria(int x, TAB* e, TAB* d){
  TAB* a = (TAB*) malloc(sizeof(TAB));
  a->info = x;
  a->esq = e;
  a->dir = d;
  return a;
}

TAB* copia(TAB *a){
  if(!a){
    return a;
  }
  // Código mais sucinto:
  // TAB *cpy = TAB_cria(a->info, copia(a->esq), copia(a->dir));

  // Código mais legivel:
  TAB *cpy = TAB_cria(a->info, NULL, NULL);
  cpy->esq = copia(a->esq);
  cpy->dir = copia(a->dir);
  return cpy;
}

TAB* espelho(TAB *a){
  if(!a){
    return a;
  }
  TAB* mirror = TAB_cria(a->info, NULL, NULL);
  mirror->esq = espelho(a->dir);
  mirror->dir = espelho(a->esq);
  return mirror;
}

TAB *maiorNo(TAB* a, TAB* b){
  if(a->info > b->info){
    return a;
  }
  return b;
}
TAB *menorNo(TAB* a, TAB* b){
  if(a->info < b->info){
    return a;
  }
  return b;
}

TAB* maior(TAB *a){
  if(!a){
    return NULL;
  }
  TAB *maior_esq, *maior_dir, *max = a;
  if(a->esq){
    maior_esq = maior(a->esq);
    max = maiorNo(maior_esq, max);
  }
  if(a->dir){
    maior_dir = maior(a->dir);
    max = maiorNo(maior_dir, max);
  }
  return max;
}

TAB* menor(TAB* a){
  if(!a){
    return NULL;
  }

  TAB *menor_esq, *menor_dir, *min = a;
  if(a->esq){
    menor_esq = menor(a->esq);
    min = menorNo(menor_esq, min);
  }
  if(a->dir){
    menor_dir = menor(a->dir);
    min = menorNo(menor_dir, min);
  }
  return min;
}

int igual (TAB* a1, TAB* a2){
  if(!a1 && !a2){
    return 1;
  }
  if(a1 && a2){
    return (a1->info == a2->info && igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir));
  }
  return 0;
}