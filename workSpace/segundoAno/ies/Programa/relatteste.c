#include "relatteste.h"

#include <stdlib.h>
#include <stdio.h>

void relat(char *fn,int voo,int pessoa, int aeronave,int total){
    FILE *f;
    char *lixo;
    f = fopen(fn,"a");
    if(!f) printf("Erro ao abrir arquivo\n");
    else printf("Aberto com sucesso!\n");


    fprintf(f,"Relatorio de Testes:\n\n");
    fprintf(f,"Data: %s\n",__DATE__);
    fprintf(f,"Horas: %s\n",__TIME__);
    fprintf(f,"%d dos %d voos foram registrados\n",voo,total);
    fprintf(f,"%d das %d aeronaves foram registrados\n",aeronave,total);
    fprintf(f,"%d dos %d clients foram registrados\n",pessoa,total);

    fclose(f);
}
