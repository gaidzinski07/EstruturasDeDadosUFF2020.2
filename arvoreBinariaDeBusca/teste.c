#include "TABB.h"

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
    TABB_libera(resp);
  }
  return 0;
}