#include "contador.h"

#include <iostream>
using namespace std;

Contador::Contador() {
    this->contador = 0;
}

void Contador::zerar() {
    this->contador = 0;
}

void Contador::incrementar() {
    this->contador++;
}

int Contador::getContador() {
    return this->contador;
}

Contador::~Contador() {
    cout << "Destruindo contador" << endl;
}
