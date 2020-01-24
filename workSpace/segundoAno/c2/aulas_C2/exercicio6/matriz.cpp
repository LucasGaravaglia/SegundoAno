#include "matriz.h"

Matriz::Matriz(int linha, int coluna){
    this->linha = linha;
    this->coluna = coluna;
    this->MatrizNulla();
}
int Matriz::GetMatriz(int i, int j){
    return mat[i][j];
}
void Matriz::SetMatriz(int i, int j,int valor){
    mat[i][j] = valor;
}
bool Matriz::equals(Matriz &other){
    if(this->linha != other.linha || this->coluna != other.coluna){
        return false;
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            if(this->mat[i][j] != other.mat[i][j]){
                return false;
            }
        }
    }
    return true;
}

Matriz Matriz::transposta(){
    Matriz *newmatriz = new Matriz(coluna,linha);
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            newmatriz->SetMatriz(j,i,mat[i][j]);
        }
    }
    return newmatriz;
}
Matriz Matriz::oposta(){
    Matriz *MatOposta = new Matriz(linha,coluna);
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            MatOposta->SetMatriz(i,j,-this->mat[i][j]);
        }
    }
    return MatOposta;
}
void Matriz::MatrizNulla(){
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            mat[i][j] = 0;
        }
    }
}
bool Matriz::MatIdent(){
    if(linha != coluna){
        return false;
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            if((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0 )){
                return false;
            }
        }
    }
    return true;
}
bool Matriz::MatDiagonal(){
    if(linha != coluna){
        return false;
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            if((i != j && mat[i][j] != 0 )){
                return false;
            }
        }
    }
    return true;
}
bool Matriz::MatSing(){
    int temp;
    if(!MatDiagonal())
        return false;
    temp = mat[0][0];
    for(int i=0;i<linha;i++)
            if(mat[i][i] != temp)
                return false;
    return true;
}
bool Matriz::MatSimet(){
    if(linha!=coluna)
        return false;
    Matriz *newtrans = this->transposta();

    if(this->equals(*newtrans)){
        delete(newtrans);
        return true;
    }
    delete(newtrans);
    return false;

}
bool Matriz::MatAntSimet(){
    if(linha!=coluna)
        return false;
    Matriz *trans = this->transposta();
    Matriz *oposta = this->oposta();
    bool key = oposta->equals(trans);

    delete(trans);
    delete(oposta);
    return key;
}

Matriz *Matriz::multiplicacao(const Matriz &other){
    if(this->coluna != other.linha)
        return NULL;
    Matriz *m3 = new Matriz (this->linha,other.coluna);
    for(int i=0;i<this->linha;i++){
        for(int j=0;j<other.coluna;j++){
            int temp = 0;
            for(int k = 0;k<other.linha;k++){
                    temp += this->mat[i][k] * other.mat[k][j];
            }
            m3->SetMatriz(i,j,temp);
        }
    }
    return m3;
}


Matriz::~Matriz(){

}
