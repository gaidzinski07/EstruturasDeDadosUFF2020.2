#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Dica: uso dessa estrutura pode ajudar na construcao do seu algoritmo.
typedef struct part{
  int chave;
  char *nome;
  FILE *fp;
} TPart;


void algBasInt(int argc, char **argv){
  int x = 0, y = 0;
  for(x = 0; x < argc - 1; x++){
    printf("%s\n", argv[x]);
  }
}

int main(int argc, char **argv){
  if((argc <= 4) || (argc > FOPEN_MAX + 1)){
    printf("Uso incorreto do algoritmo: <executavel> <nome dos n arquivos a serem intercalados> <nome do arquivo de saida>\n");
    exit(1); 
  }
  algBasInt(argc, argv);
  return 0;
}