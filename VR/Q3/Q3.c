#include "TH.h"

int TAM = 2;

void criaHashing(char *arq, char* hashing, char* dadosHashing){
  FILE *fp = fopen(dadosHashing, "wb");
  fclose(fp);
  TH_inicializa(hashing, TAM);
  fp = fopen(arq, "rb");
  fseek(fp, 0, SEEK_SET);
  int current = 0;
  while(!feof(fp)){
    fread(&current, sizeof(int), 1, fp);
    TH_insere(hashing, dadosHashing, TAM, current);
  }
  fclose(fp);
}

int ehSubconjunto(char *hashing, char *dadosHashing, char *cmpFile){
  FILE *fp = fopen(cmpFile, "rb");
  fseek(fp, 0, SEEK_SET);
  int current = 0;
  while(!feof(fp)){
    fread(&current, sizeof(int), 1, fp);
    if(!TH_busca(hashing, dadosHashing, TAM, current)){
      fclose(fp);
      return 0;
    }
  }
  fclose(fp);
  return 1;
}

int eIgual(char *arq_entrada1, char *arq_entrada2){
  criaHashing(arq_entrada1, "hashing_1", "dados_hashing_1");
  criaHashing(arq_entrada2, "hashing_2", "dados_hashing_2");
  return ehSubconjunto("hashing_1", "dados_hashing_1", arq_entrada2) && ehSubconjunto("hashing_2", "dados_hashing_2", arq_entrada1);
}
  
int main(void){
  int num;
  char nome_dados1[31];
  printf("Digite nome do arquivo de dados... ");
  scanf("%s", nome_dados1);
  FILE *fp = fopen(nome_dados1, "wb");
  if(!fp) exit(1);  
  do{
    printf("Digite o numero... ");
    scanf("%d", &num);
    if(num < 0) break;
    fwrite(&num, sizeof(int), 1, fp);
  }while(1);
  fclose(fp);

  char nome_dados2[31];
  printf("Digite nome do arquivo de dados... ");
  scanf("%s", nome_dados2);
  fp = fopen(nome_dados2, "wb");
  if(!fp) exit(1);
  do{
    printf("Digite o numero... ");
    scanf("%d", &num);
    if(num < 0) break;
    fwrite(&num, sizeof(int), 1, fp);
  }while(1);
  fclose(fp);
  
  printf("%d\n", eIgual(nome_dados1, nome_dados2));
  return 0;
}