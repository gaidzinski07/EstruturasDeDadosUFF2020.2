#include "TABB.h"

int teste (TABB *a){
  return testeAux(a, 0);
}

int testeAux(TABB *a, int h){
  //se for impar
  if(a==NULL){
    return 0;
  }
  if(h % 2 !=  0){
    if(checarNumeroFilhos(a) != 1){
      return 0;
    }
    if(a->esq != NULL){
      h+=1;
      return testeAux(a->esq, h);
    }else{
      h+=1;
      return testeAux(a->dir, h);
    }
  }
  //se for par
  else{
    if(checarNumeroFilhos(a) == 0){
      return 1;
    }else if(checarNumeroFilhos(a) == 1){
      return 0;
    }
    return testeAux(a->esq, h+1) && testeAux(a->dir, h+1);
  }
}

int checarNumeroFilhos(TABB *no){
  int n = 0;
  if(no->esq != NULL){
    n++;
  }
  if(no->dir != NULL){
    n++;
  }
  return n;
}

int main(void){
  int n;
  TABB *resp = NULL;
  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    resp = TABB_insere(n, resp);
  }
  TABB_imprime(resp);
  n = teste(resp);
  printf("%d\n", n);
  TABB_libera(resp);
  return 0;
}