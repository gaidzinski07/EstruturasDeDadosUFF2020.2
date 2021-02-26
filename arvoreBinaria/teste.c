#include "TLSE.h"

int main(void){
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  TLSE_imp_rec(l);
  TLSE_ordena_rec(l);
  TLSE_imp_rec(l);  
  TLSE_lib_rec(l);  
  return 0;
}