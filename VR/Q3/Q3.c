#include "TH.h"

//eIgual(char *arq_entrada1, char *arq_entrada2);
  
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
  
  //printf("%d\n", eIgual(char *arq_entrada1, char *arq_entrada2));
  return 0;
}