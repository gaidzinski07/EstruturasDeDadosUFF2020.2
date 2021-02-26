#include "TLSE.h"

TLSE* TLSE_inicializa(void){
  return NULL;
}

TLSE* TLSE_insere(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->info = elem;
  novo->prox = l;
  return novo;
}

void TLSE_imprime(TLSE *l){
  while(l){
    printf("%d ", l->info);
    l = l->prox;
  }
  printf("\n");
}

void TLSE_imp_rec(TLSE *l){
  if(l){
    printf("%d ", l->info);
    TLSE_imp_rec(l->prox);
  }
  else printf("\n");
}

void TLSE_imp_rec_rev(TLSE *l){
  if(l){
    TLSE_imp_rec_rev(l->prox);
    printf("%d ", l->info);    
  }
}

void TLSE_libera(TLSE *l){
  TLSE *p = l;
  while(p){
    TLSE *temp = p;
    p = p->prox;
    free(temp);
  }
}

void TLSE_lib_rec(TLSE *l){
  if(l){
    TLSE_lib_rec(l->prox);
    free(l);
  }
}

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *resp = l;
  while((resp) && (resp->info != elem)) resp = resp->prox;
  return resp;
}

TLSE* TLSE_busca_rec(TLSE *l, int elem){
  if((!l) || (l->info == elem)) return l;
  return TLSE_busca_rec(l->prox, elem);
}

TLSE* TLSE_retira(TLSE *l, int elem){
  TLSE *ant = NULL, *p = l;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* TLSE_ret_rec(TLSE *l, int elem){
  if(!l) return l;
  if(l->info == elem){
    TLSE *p = l;
    l = l->prox;
    free(p);
  }
  else l->prox = TLSE_ret_rec(l->prox, elem);
  return l;
}

TLSE* TLSE_ins_ord(TLSE *l, int elem){
  TLSE *ant = NULL, *p = l;
  while((p) && (p->info < elem)){
    ant = p;
    p = p->prox;
  }
  TLSE *novo = TLSE_insere(p, elem);
  if(!ant) l = novo;
  else ant->prox = novo;
  return l;
}

TLSE* TLSE_ins_ord_rec(TLSE *l, int elem){
  if((!l) || (l->info >= elem)) return TLSE_insere(l, elem);
  l->prox = TLSE_ins_ord_rec(l->prox, elem);
  return l;
}

void TLSE_ordena(TLSE *l){
  TLSE *p;
  for(p = l; p; p = p->prox){
    TLSE *q, *menor = p;
    for(q = p->prox; q; q = q->prox)
      if(q->info < menor->info) menor = q;
    
    if(menor != p){
      int temp = menor->info;
      menor->info = p->info;
      p->info = temp;
    }
  }
}

void TLSE_ordena_rec(TLSE *l){
  TLSE *q, *menor = l;
  for(q = l->prox; q; q = q->prox)
    if(menor->info > q->info) menor = q;
  
  if(menor != l){
    int temp = menor->info;
    menor->info = l->info;
    l->info = temp;
  }
  
  TLSE_ordena_rec(l->prox);
}