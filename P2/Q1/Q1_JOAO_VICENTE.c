#include "TH.h"

void misc(char *nome_dados, int tam, char *nome_saida){
  TH_inicializa("arquivo_hashing", tam);
  FILE *f = fopen(nome_saida, "wb");
  fclose(f);
  FILE *fp = fopen(nome_dados, "rb");
  fseek(fp, 0, SEEK_SET);
  int current = 0;
  while(!feof(fp)){
    fread(&current, sizeof(int), 1, fp);
    if(!TH_busca("arquivo_hashing", nome_saida, tam, current)){
      TH_insere("arquivo_hashing", nome_saida, tam, current);
    }
  }
}
  
int main(void){
  int tam;
  printf("Digite tam... ");
  scanf("%d", &tam);

  if(tam <= 1) return 0;

  char nome_dados[31];
  printf("Digite nome do arquivo de dados inicial... ");
  scanf("%s", nome_dados);
  FILE *fp = fopen(nome_dados, "wb");
  if(!fp) exit(1);

  int num;
  do{
    printf("Digite o numero... ");
    scanf("%d", &num);
    if(num < 0) break;
    fwrite(&num, sizeof(int), 1, fp);
  }while(1);
  fclose(fp);
  //RETIRE O COMENTÁRIO DAS LINHAS 28 E 44 PARA TESTAR SEU PROGRAMA...
  
  char nome_saida[31];
  printf("Digite nome do arquivo de dados de saida... ");  
  scanf("%s", nome_saida);
  misc(nome_dados, tam, nome_saida);
  fp = fopen(nome_saida, "rb");
  if(!fp) exit(1);
  
  int r;
  TNUM aux;
  do{
    r = fread(&aux, sizeof(TNUM), 1, fp);
    if(r != 1) break;
    if(aux.cont) printf("%d\n", aux.num);
  }while(1);
  fclose(fp);
  
  return 0;
}
