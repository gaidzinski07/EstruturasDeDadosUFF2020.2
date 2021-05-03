#include "TAV.h"
#include "TAB.h"
#include <limits.h>

int contarFilhos(TAV* a){
  if(!a){
    return 0;
  }
  TAV *b = a->prim_filho;
  int cont = 0;
  do{
    if(!b)
      break;
    else{
      ++cont;
      b = b->prox_irmao;
    }
  }while(b);
  return cont;
}

int max(int a, int b){
  if(a > b)
    return a;
  return b;
}

int maxN(TAV* a, int maxValue){
  if(!a){
    return 0;
  }
  TAV* x;
  for(x = a->prim_filho; x; x = x->prox_irmao){
    maxValue = max(maxN(x, maxValue), contarFilhos(a));
  }
  return maxValue;
}

TAB *copiaArvore(TAV *a){
  if(!a){
    return NULL;
  }
  TAV* x = a->prim_filho;
  TAV* y = x? x->prox_irmao : NULL;
  return TAB_cria(a->info, copiaArvore(x), copiaArvore(y));
}

TAB* av2ab(TAV *a, int *n){
  if(!a){
    return NULL;
  }
  *n = maxN(a, INT_MIN);
  if(*n > 2)
    return NULL;
  return copiaArvore(a);
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAV *a = TAV_cria(no);
  char repete;
  do{
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir) e o filho a ser inserido na arvore... ");
    scanf("%d%d", &pai, &no);
    TAV_insere(a, pai, no);
  }while(1);
  TAV_imprime(a);
  printf("\n");

  int n;
  TAB *resp = av2ab(a, &n);
  printf("%d\n", n);
  if(n <= 2){
    TAB_imprime(resp);
    TAB_libera(resp);
  }
  TAV_libera(a);
  return 0;
}