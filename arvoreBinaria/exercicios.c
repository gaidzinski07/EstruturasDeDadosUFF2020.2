#include "TAB.h"
int main(){
    TAB *arv = TAB_cria(1, TAB_cria(2, NULL, TAB_cria(4, NULL, NULL)), TAB_cria(3, NULL, NULL));
    printf("Arvore base:\n");
    TAB_imprime(arv);
    printf("\n\n\n 1) COPIA:\n");
    TAB_imprime(copia(arv));
    printf("\n\n\n 2) ESPELHO:\n");
    TAB_imprime(espelho(arv));
    printf("\n\n\n 3) Maior nó:\n");
    TAB_imprime(maior(arv));
    printf("\n\n\n 4) Menor nó:\n");
    TAB_imprime(menor(arv));
    printf("\n\n\n 5) São iguais: ");
    TAB *cpy = copia(arv);
    TAB *arv2 = TAB_cria(1, TAB_cria(2, NULL, NULL), TAB_cria(3, NULL, NULL));
    printf("%d\n", igual(arv, arv2));
}