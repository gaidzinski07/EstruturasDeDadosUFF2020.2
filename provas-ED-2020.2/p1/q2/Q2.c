#include "TABB.h"

//int teste (TABB *a);

int main(void){
  int n;
  TABB *resp = NULL;
  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    resp = TABB_insere(n, resp);
  }
  TABB_imprime(resp);
  printf("%d\n", FOPEN_MAX);
  //n = teste(resp);
  //printf("%d\n", n);
  TABB_libera(resp);
  return 0;
}