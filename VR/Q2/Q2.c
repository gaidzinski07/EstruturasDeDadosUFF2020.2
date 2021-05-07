#include <limits.h>
#include "TARVBM.c"

int pred(TARVBM *a, int k, int current){
  printf("\n");
  if (!a){
    return current;
  }
  int i = 0;
  int temp = i;
  //achar a maior chave menor que k em a
  
  for(i = 0; i < a->nchaves; i++){
    printf("%d\t%d", a->chave[i], temp);
    if ((k > a->chave[i] && a->chave[i] > current)){
      current = a->chave[i];
      temp = i;
    }
    printf("\n");
  }
  printf("temp: %d\t", temp);
  temp = a->nchaves - temp - 1;
  printf("%d\n", temp);
  if (a->folha){
    return current;
  }
  return pred(a->filho[temp], k, current);
}

int suc(TARVBM *a, int k, int current){
  return INT_MAX;
}

int* pred_suc(TARVBM *a, int n){
    int* resp = malloc(sizeof(int) * 2);
    resp[0] = pred(a, n, INT_MIN);
    resp[1] = suc(a, n, INT_MAX);
    return resp;
}

int main(int argc, char *argv[]){
  TARVBM *arvore = TARVBM_inicializa();
  int t;
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num;
  do{
    scanf("%d", &num);
    if(num <= 0) break;
    arvore = TARVBM_insere(arvore, num, t);
  }while(1);

  
  if(arvore){
    scanf("%d", &num);
    int *resp = pred_suc(arvore, num);
    TARVBM_imprime(arvore);
    printf("\nPredecessor: %d\tSucessor: %d\n", resp[0], resp[1]);
    free(resp);
  }

  TARVBM_libera(arvore);
  return 0;
}