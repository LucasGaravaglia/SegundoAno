#include "hasshing.h"


int hash(int k){
    return k%TAM;
}

void inicializaTabelaHash(TabelaHash T){
    for(int i=0;i<TAM;i++)
        T[i].ocupado = 0;
}

void inserir(TabelaHash T, TipoChave k, TipoRegistro r){
    int posicao;
    posicao=hash(k);
    if(T[posicao].ocupado == 0){
        T[posicao].r = r;
        T[posicao].k = k;
        T[posicao].ocupado = 1;
    }else{
        printf("Posicao Ocupada.\n");
    }
}

void inserirLinear(TabelaHash T, TipoChave k, TipoRegistro r){
    int posicao;
    posicao=hash(k);
    if(T[posicao].ocupado == 0){
        T[posicao].r = r;
        T[posicao].k = k;
        T[posicao].ocupado = 1;
    }else{
        int i=0;
        while(T[posicao].ocupado == 1){
            posicao = hash(k+i);
            i++;
        }
        T[posicao].r = r;
        T[posicao].k = k;
        T[posicao].ocupado = 1;
    }
}

void inserirQuadratica(TabelaHash T, TipoChave k, TipoRegistro r){
    int posicao;
    posicao=hash(k);
    if(T[posicao].ocupado == 0){
        T[posicao].r = r;
        T[posicao].k = k;
        T[posicao].ocupado = 1;
    }else{
        int i=0;
        while(T[posicao].ocupado == 1){
            posicao = hash(hash(k)+i+(i*i));
            i++;
        }
        T[posicao].r = r;
        T[posicao].k = k;
        T[posicao].ocupado = 1;
    }
}

void inserirDupla(TabelaHash T, TipoChave k, TipoRegistro r){
    int posicao;
    posicao=hash(k);
    if(T[posicao].ocupado == 0){
        T[posicao].r = r;
        T[posicao].k = k;
        T[posicao].ocupado = 1;
    }else{
        int i=0;
        while(T[posicao].ocupado == 1){
            posicao = hash(hash(k)+i*hash(k));
            i++;
        }
        T[posicao].r = r;
        T[posicao].k = k;
        T[posicao].ocupado = 1;
    }
}


//retorna a posiçao do registro de chave k na tabela hash T
// ou -1 caso a chave nao esteja presente.
int buscar(TabelaHash T, TipoChave k){
    int posicao = hash(k);
    if(T[posicao].ocupado)
        return T[posicao].k;
    else 
        return -1;
}

void remover(TabelaHash T, TipoChave k){
    if(T[hash(k)].ocupado){
        T[hash(k)].ocupado = 0;
        printf("Elemento removido.\n");
    }else printf("Elemento nao encontrado.\n");
}

void showtabela(TabelaHash T){
    for(int i=0;i<TAM;i++)
        if(T[i].ocupado == 1)
            printf("----%d\n%s\n\n\n",T[i].r.matricula,T[i].r.nome);
}

void nChaves(int chave, int numeroDeChaves){
    int i;
    for(i=0;i<numeroDeChaves;i++){
        printf("Chave[%d] = %d\n",chave,numeroDeChaves);
        printf("Hash(%d) = %d\n",chave,hash(chave + (TAM*i)));
    }
}

int main(){
    
    return 0;
}