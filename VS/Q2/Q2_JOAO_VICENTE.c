#include <limits.h>
#include "TARVB.h"
#include "TLSE.h"

TLSE* codif_aux(TARVB* a, int k){
  if(!a) return NULL;
  int i = 0;
  while(i < a->nchaves && k > a->chave[i]){ 
    i++;
  }
  if(i < a->nchaves && k == a->chave[i]){
     return TLSE_insere(NULL, i);
  }
  if(a->folha){
     return NULL;
  }
  TLSE* l = codif_aux(a->filho[i], k);
  if(l){
    return TLSE_insere(l, i);
  }
  return NULL;
}

char* codif (TARVB* a, int k){
  TLSE* lista = codif_aux(a, k);
  if(lista){
    TLSE* aux = lista;
    int tam = 0;
    while(aux){
        tam++;
        aux = aux->prox;
    }
    char* result = (char*) malloc(sizeof(char) * tam);
    int i = 0;
    aux = lista;
    for(i = 0 ; i < tam; i++){
      result[i] = aux->info + '0';
      aux = aux->prox;
    }
    TLSE_libera(lista);
    return result;
  }
  int aux = k;
  int tam = 0;
  while(aux != 0){
      tam++;
      aux /= 10;
  }

  char* string = malloc(sizeof(char) * tam);

  aux = k;
  int i;
  for(i = tam-1; i >= 0 ; i--){
      string[i] = aux%10 + '0';
      aux /= 10;
  }
  return string;
}


int main(int argc, char *argv[]){
  TARVB *arvore = TARVB_Inicializa();
  int t;
  do{
    scanf("%d", &t);
  }while((t < 2) || (t > 4));

  int num;
  do{
    scanf("%d", &num);
    if(num <= 0) break;
    arvore = TARVB_Insere(arvore, num, t);
  }while(1);
  TARVB_Imprime(arvore);
  
  if(arvore){
    char repete;
    do{
      scanf("%d", &num);
      
      char *resp = codif (arvore, num);
      printf("%s\n", resp);
      free(resp);
      
      printf("Quer continuar? ");
      scanf(" %c", &repete);
    }while((repete != 'N') && (repete != 'n'));
  }
  TARVB_Libera(arvore);
  return 0;
}