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

void dif_sim(char *arq_entrada1, char *arq_entrada2, char *saida){
    criaHashing(arq_entrada1, "hashing_1", "dados_hashing_1");
    criaHashing(arq_entrada2, "hashing_2", "dados_hashing_2");

    FILE *fcmp = fopen(arq_entrada2, "rb");
    FILE *fsaida = fopen(saida, "wb");
    fseek(fcmp, 0, SEEK_SET);
    fseek(fsaida, 0, SEEK_SET);
    int current = 0;
    int last;

    while(!feof(fcmp)){
      fread(&current, sizeof(int), 1, fcmp);
      if(last != current){
        if(!TH_busca("hashing_1", "dados_hashing_1", TAM, current)){
            fwrite(&current, sizeof(int), 1, fsaida);
        }
      }
      last = current;
    }

    fclose(fcmp);
    fcmp = fopen(arq_entrada1, "rb");
    fseek(fcmp, 0, SEEK_SET);
    while(!feof(fcmp)){
      fread(&current, sizeof(int), 1, fcmp);
      if(last != current){
        if(!TH_busca("hashing_2", "dados_hashing_2", TAM, current)){
            fwrite(&current, sizeof(int), 1, fsaida);
        }
      }
      last = current;
    }
    fclose(fcmp);
    fclose(fsaida);
}
  
int main(void){
  int ant, num;
  char nome_dados1[31];
  printf("Digite nome do arquivo de dados... ");
  scanf("%s", nome_dados1);
  FILE *fp = fopen(nome_dados1, "wb");
  if(!fp) exit(1);  
  printf("Digite o numero... ");
  scanf("%d", &ant);
  fwrite(&ant, sizeof(int), 1, fp);
  do{
    printf("Digite o numero... ");
    scanf("%d", &num);
    if(num < 0) break;
    if(num <= ant) continue;
    fwrite(&num, sizeof(int), 1, fp);
    ant = num;
  }while(1);
  fclose(fp);

  char nome_dados2[31];
  printf("Digite nome do arquivo de dados... ");
  scanf("%s", nome_dados2);
  fp = fopen(nome_dados2, "wb");
  if(!fp) exit(1);
  printf("Digite o numero... ");
  scanf("%d", &ant);
  fwrite(&ant, sizeof(int), 1, fp);
  do{
    printf("Digite o numero... ");
    scanf("%d", &num);
    if(num < 0) break;
    if(num <= ant) continue;
    fwrite(&num, sizeof(int), 1, fp);
    ant = num;
  }while(1);
  fclose(fp);
  
  char nome_saida[31];
  printf("Digite nome do arquivo de dados de saida... ");  
  scanf("%s", nome_saida);
  dif_sim(nome_dados1, nome_dados2, nome_saida);  
  
  fp = fopen(nome_saida, "rb");
  if(!fp) exit(1);  
  int r;
  do{
    r = fread(&num, sizeof(int), 1, fp);
    if(r != 1) break;
    printf("%d\n", num);
  }while(1);
  fclose(fp);
  
  return 0;
}