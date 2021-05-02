#include <limits.h>
#include "TARVBM.c"

int* pred_suc(TARVBM *a, int n){
    
}

int main(int argc, char *argv[]){
  TARVBM *arvore = TARVBM_Inicializa();
  int t;
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num;
  do{
    scanf("%d", &num);
    if(num <= 0) break;
    arvore = TARVBM_Insere(arvore, num, t);
  }while(1);

  /*
  if(arvore){
    scanf("%d", &num);
    int *resp = pred_suc(arvore, num);
    printf("Predecessor: %d\tSucessor: %d\n", resp[0], resp[1]);
    free(resp);
  }
  */
  TARVBM_Libera(arvore);
  return 0;
}