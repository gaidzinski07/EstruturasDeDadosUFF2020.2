#include <stdio.h>
#include <stdlib.h>

//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

typedef struct arvbin{
   int info;
   struct arvbin *esq, *dir;
}TAB;

TAB* cria(int r, TAB *sae, TAB *sad){
  TAB *novo;
  novo = (TAB *)malloc(sizeof(TAB));
  novo->info = r;
  novo->esq = sae;
  novo->dir = sad;
  return novo;
}

void libera(TAB *a){
  if(a){
    libera(a->esq);
    libera(a->dir);
    free(a);
  }
}

void imp_pre(TAB *a){
  if(a){
    printf("%d ", a->info);
    imp_pre(a->esq);
    imp_pre(a->dir);
  }
}

void imp_sim(TAB *a){
  if(a){
    imp_sim(a->esq);
    printf("%d ", a->info);
    imp_sim(a->dir);
  }
}

// n = 7 => n - n/2 - 1 = 7 - 3 - 1 = 3
// n = 4 => n - n/2 - 1 = 4 - 2 - 1 = 1
TAB *v2ab(int *v, int n){
  if(n <= 0) return NULL;
  return cria(v[n/2], v2ab(v, n/2), v2ab(&v[n/2 +1], n - n/2 - 1));  
}

//              =  1, x > y
//cmp_int(x, y) = -1, x < y
//              =  0, x = y 
int cmp_int(const void *vx, const void *vy){
   int *ix = (int *)vx, *iy = (int *)vy;
   if((*ix) < (*iy)) return -1;
   if((*ix) > (*iy)) return 1;
   return 0;
}

TAB* copiaAux(TAB* no){
    return NULL;
}

TAB* copia(TAB *a){
  TAB *cpy = NULL;
  if(a){
    printf("%d", a->info);
    cpy->esq = copia(a->esq);
  }
  printf("NULO");
  return NULL;
}

int main(void){
  while(1){
    int n;
    scanf("%d", &n);
    if(n <= 0) return 0;
    int vet[n], i;
    for(i = 0; i < n; i++) scanf("%d", &vet[i]);
    qsort(vet, n, sizeof(int), cmp_int);
    TAB *a = v2ab(vet, n);
    imp_pre(a);
    printf("\n");
    imp_sim(a);
    printf("\n");
    copia(a);
    libera(a);
  }
}