#include <string.h>
#include "TAB.h"
#include "TLSE.h"

TLSE* ancestrais_aux(TAB *a, int elem){
    if(!a) return NULL;

    TLSE* d = ancestrais_aux(a->dir, elem);
    TLSE* e = ancestrais_aux(a->esq, elem);
    
    if(d){
        return TLSE_insere(d, a->info);
    }
    if(e){
        return TLSE_insere(e, a->info);
    }
    if(a->info == elem){
        TLSE* lista = TLSE_insere(NULL, a->info);
        return lista;
    }
    return NULL;
}

int* ancestrais(TAB *a, int elem, int *n){
    if(!a) return NULL;
    TLSE* lista = ancestrais_aux(a, elem);
    TLSE* aux = lista;
    int tam = 0;
    while(aux){
        tam++;
        aux = aux->prox;
    }
    int* result = (int*) malloc(sizeof(int) * tam);
    int i = 0;
    aux = lista;
    for(i = tam - 2; i >= 0; i--){
        result[i] = aux->info;
        aux = aux->prox;
    }
    *n = (tam==0)? tam : tam-1;
    TLSE_libera(lista);
    return result;
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL);
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    TAB *resp = TAB_busca(pai, a);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imprime(a);
  printf("\n");
  
  int n, elem;
  scanf("%d", &elem);
  int *vet = ancestrais(a, elem, &n);
  printf("%d\n", n);
  if(vet){
    int i;
    for(i = 0; i < n; i++) printf("%d ", vet[i]);
    printf("\n");
    free(vet);  
  }
  TAB_libera(a);
  return 0;
}