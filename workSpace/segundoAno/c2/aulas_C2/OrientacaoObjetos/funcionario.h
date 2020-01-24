#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"
#include "data.h"

class Funcionario : public Pessoa {
private:
    int faltas;
    Data *data_admissao; // QDate

    float salario_base;
public:
    Funcionario();    
    void setar();
    void mostrar();
    const string getIdadeContratacao();
    ~Funcionario();
};

#endif // FUNCIONARIO_H
