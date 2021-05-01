#include <limits.h>
#include "TARVB.h"
#include "TLSE.h"


TLSE* div_k_aux(TARVB* a, int k, TLSE* n){
    if(!a){
        return n;
    }
    int i = 0;
    for(i=0; i < a->nchaves; i++){
        if(k % a->chave[i] == 0 && a->chave[i] != k){
            n = TLSE_insere(n, a->chave[i]);
        }
        n = div_k_aux(a->filho[i], k, n);
    }
    n = div_k_aux(a->filho[a->nchaves], k, n);
    return n;
}

int cmpfunc (int * a, int * b) {
   return ( *a - *b );
}

int* div_k (TARVB* a, int k, int *n){
    TLSE* lista = NULL;
    lista = div_k_aux(a, k, lista);
    int tam = 0;
    TLSE* aux = lista;
    while(aux){
        tam++;
        aux = aux->prox;
    }
    int* result = (int*) malloc(sizeof(int) * tam);
    int i = 0;
    aux = lista;
    for(i=0; i<tam; i++){
        result[i] = aux->info;
        aux = aux->prox;
    }
    *n = tam;
    qsort(result, tam, sizeof(int), cmpfunc);
    return result;
}

int main(int argc, char *argv[]){
  TARVB *arvore = TARVB_Inicializa();
  int t;
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num;
  do{
    scanf("%d", &num);
    if(num <= 0) break;
    arvore = TARVB_Insere(arvore, num, t);
  }while(1);
  
  if(arvore){
    int n = 0, k, i;
    scanf("%d", &k);
    int *resp = div_k (arvore, k, &n);
    if(resp){
        for(i = 0; i < n; i++) printf("%d ", resp[i]);
        printf("\n"); 
        free(resp);
    }
  }
  
  TARVB_Libera(arvore);
  return 0;
}