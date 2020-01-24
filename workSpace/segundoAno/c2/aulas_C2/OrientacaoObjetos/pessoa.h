#ifndef PESSOA_H
#define PESSOA_H

#include "data.h"

class Pessoa {
protected:
    char nome[31];
    char endereco[40];

    Data *data_nascimento;
public:
    Pessoa();
    void setar();
    void mostrar();

    Data *getDataNacimento();
    ~Pessoa();
};


#endif // PESSOA_H
