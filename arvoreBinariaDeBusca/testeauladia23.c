#include "TABB.h"

int *mN(TABB *a, int N);
TABB *maior(TABB *a);
void colore (TABB* a);

int main(void){
  while(1){
    int n;
    scanf("%d", &n);
    if(n <= 0) break;
    TABB *resp = NULL;
    int aux, i;
    for(i = 0; i < n; i++){
      scanf("%d", &aux);
      resp = TABB_insere(aux, resp);
    }
    TABB_imprime(resp);
    /*
    int N;
    scanf("%d", &N);
    int *vet = mN(resp, N);
    for(i = 0; i < vet[0]; i++) printf("%d ", vet[i + 1]);
    printf("\n");
    free(vet);
    */
    
    /*
    TABB *x = maior(resp); 
    printf("Maior = %d\n", x->info);
    */
    printf("\n");
    colore(resp);
    TABB_imprime(resp);
    TABB_libera(resp);
  }
  return 0;
}

void col_aux(TABB *a, int cor){
  if(!a) return;
  a->cor = cor;
  col_aux(a->esq, !cor);
  col_aux(a->dir, !cor);    
}

void colore(TABB *a){
  if(!a) return;
  col_aux(a, 0);
}

TABB* maior(TABB *a){
 if((!a) || (!a->dir)) return a;
 return maior(a->dir);
}

int conta_menores(TABB *a, int N){
  if(!a) return 0;
  if(a->info >= N) return conta_menores(a->esq, N);
  return conta_menores(a->esq, N) + conta_menores(a->dir, N) + 1;
}

void mN_aux(TABB *a, int N, int *vet, int *pos){
  if(!a) return;
  if(a->info >= N) mN_aux(a->esq, N, vet, pos);
  else{
    mN_aux(a->esq, N, vet, pos);
    vet[(*pos)] = a->info;
    (*pos)++;
    mN_aux(a->dir, N, vet, pos);
  } 
}

int *mN(TABB *a, int N){
  int n = conta_menores(a, N), pos = 1;
  int *vet = (int *) malloc(sizeof(int) * (n + 1));
  vet[0] = n;
  mN_aux(a, N, vet, &pos);
  return vet; 
}