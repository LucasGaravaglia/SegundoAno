  #include "circulo.h"

#include <iostream>
using namespace std;

Circulo::Circulo( double x, double y, double raio ) : Ponto ( x, y ) {
    this->raio = raio;
}



void Circulo::aumentar() {
    raio++;
}

void Circulo::diminuir() {
    raio--;
}

void Circulo::show() {
    cout << "("
         << getx()
         << ","
         << gety()
         << ","
         << raio
         << ")"
         << endl;

}

Circulo::~Circulo() {
    cout<< "Destructor::Ponto" << endl;
}
