#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz{

private:
    int mat[][];
    int linha;
    int coluna;
public:
    Matriz(int linha, int coluna);
    int GetMatriz(int i, int j);
    void SetMatriz(int i, int j,int valor);
    bool equals(Matriz &other);
    Matriz transposta();
    Matriz oposta();
    void MatrizNulla();
    bool MatIdent();
    bool MatDiagonal();
    bool MatSing();
    bool MatSimet();
    bool MatAntSimet();
    Matriz* multiplicacao(const Matriz &other);


    ~Matriz();
};

#endif // MATRIZ_H
