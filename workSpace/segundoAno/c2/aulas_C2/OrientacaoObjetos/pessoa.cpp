#include "pessoa.h"

#include <iostream>
using namespace std;

Pessoa::Pessoa() {
    nome[0] = '\0';
    endereco[0] = '\0';
    data_nascimento = new Data();
}

void Pessoa::setar() {
   char newline;
   cout << "\n Digite o nome: ";
   cin.get( nome, 30, '\n' );
   cin.get(newline);

   cout << "\n Digite o endereco: ";
   cin.get( endereco, 40, '\n' );
   cin.get(newline);

   cout << "\n Digite data nascimento: ";
   data_nascimento->setar();

}

void Pessoa::mostrar() {
    cout << "\n Nome....: " << nome << endl;

    cout << "\n Endereco: " << endereco << endl;

    cout << "\n Data nascimento: ";
    data_nascimento->mostrar();
}

Data *Pessoa::getDataNacimento() {
    return this->data_nascimento;
}

Pessoa::~Pessoa () {
    cout << "Destructor::pessoa" << endl;
    delete data_nascimento;
}

