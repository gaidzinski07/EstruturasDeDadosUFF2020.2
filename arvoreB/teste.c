#include "TARVB.h"
#include <limits.h>

int maior(TARVB *a){
  if(!a) return INT_MIN;
  if(a->folha) return a->chave[a->nchaves -1];
  return maior(a->filho[a->nchaves]);
}

TARVB *suc_aux(TARVB *a, int x, TARVB *suc){
  if(!a) return NULL;
  int i = 0;
  while((i < a->nchaves) && (a->chave[i] <= x)) i++;
  if((a->folha) && (i == a->nchaves) && (a->chave[i - 1] <= x)) return suc;
  if((a->folha) && (i < a->nchaves)) return a;
  if((i == a->nchaves) && (a->chave[i - 1] <= x)) return suc_aux(a->filho[i], x, suc);
  return suc_aux(a->filho[i], x, a);
}

TARVB *sucede(TARVB *a, int x){
  if((!a) || (x >= maior(a))) return NULL;
  return suc_aux(a, x, a);
}

int main(int argc, char *argv[]){
  TARVB *arvore = TARVB_Inicializa();
  int t;
  printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num = 0, from, to;
  while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%d", &num);
    if(num == -9){
      scanf("%d", &from);
      arvore = TARVB_Retira(arvore, from, t);
      TARVB_Imprime(arvore);
    }
    else if(num == -1){
      printf("\n");
      TARVB_Imprime(arvore);
      //scanf("%d", &num);
      //TARVB_Imprime(sucede(arvore, num));
      TARVB_Libera(arvore);
      return 0;
    }
    else if(!num){
      printf("\n");
      TARVB_Imprime(arvore);
    }
    else arvore = TARVB_Insere(arvore, num, t);
    printf("\n\n");
  }
}
