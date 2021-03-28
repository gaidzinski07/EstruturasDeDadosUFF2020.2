#include "TAV.h"

int eBinaria(TAV *a){
  if(a == NULL){
    return 1;
  }
  if(checarNumeroDeFilhos(a) > 2){
    return 0;
  }
  return eBinaria(a->prim_filho) && eBinaria(a->prox_irmao);
}

int checarNumeroDeFilhos(TAV *a){
  if(a == NULL || a->prim_filho == NULL){
    return 0;
  }
  return contarIrmaos(a->prim_filho);
}
int contarIrmaos(TAV *a){
  if(a == NULL)
    return 0;
  return contarIrmaos(a->prox_irmao) + 1;
}

int main(void){
  int no, pai, resp;
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
  resp = eBinaria(a);
  printf("%d\n", resp);
  TAV_libera(a);
  return 0;
}