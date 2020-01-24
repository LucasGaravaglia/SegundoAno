#include "funcionario.h"

#include <iostream>
using namespace std;

Funcionario::Funcionario() {
    faltas = 0;
    salario_base = 0;
    data_admissao = new Data();
}

const string Funcionario::getIdadeContratacao() {
  return data_nascimento->dias_percorridos(
                *this->data_admissao );
    /*   return getDataNacimento()->
            dias_percorridos(
                *this->data_admissao );
                * */
}

void Funcionario::setar() {

    cout << "INFORME OS DADOS DO FUNCIONARIO";
    Pessoa::setar();
    cout << "\n Data admissao: ";
    data_admissao->setar();

    cout << "\n Salário base: ";
    cin >> salario_base;

}

void Funcionario::mostrar() {
    cout << "DADOS DO FUNCIONARIO";
    Pessoa::mostrar();
    cout << "\n Data admissao: ";
    data_admissao->mostrar();

    cout << "\n Salário base: "
         << salario_base << endl;
}

Funcionario::~Funcionario() {
    cout << "Destructor::Funcionario" << endl;
    delete data_admissao;
}
