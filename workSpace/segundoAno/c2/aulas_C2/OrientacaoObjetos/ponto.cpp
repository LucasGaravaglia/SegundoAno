#include "ponto.h"

#include <iostream>
using namespace std;

Ponto::Ponto(  ) {
    this->x = 0;
    this->y = 0;
}

Ponto::Ponto( double x, double y ) {
    this->x = x;
    this->y = y;
}

void Ponto::moveto ( double x, double y ) {
    this->x = x;
    this->y = y;
}

void Ponto::moveto (const Ponto &other ) {
    this->x = other.x;
    this->y = other.y;
}

void Ponto::setx ( double x ) {
    this->x = x;
}

void Ponto::sety ( double y ) {
    this->y = y;
}

double Ponto::getx ( ) {
    return this->x;
}

double Ponto::gety ( ) {
    return this->y;
}

void Ponto::show () {
    cout << "(" << x << "," <<
            y << ")" << endl;
}


void Ponto::operator+=(const Ponto&other) {
    this->x += other.x;
    this->y += other.y;
}

Ponto Ponto::operator+(const Ponto&other) {
    Ponto p;
    p.setx ( this->x + other.x );
    p.sety ( this->y + other.y );
    return p;
}

Ponto::~Ponto() {
    cout<< "Destructor::Ponto" << endl;
}


ostream &operator<<( ostream &output,
                     const Ponto &ponto ) {
    output << "("
           << ponto.x
           << ","
           << ponto.y
           << ")";
    return output;
}

istream &operator>> (istream &input,
                     Ponto &ponto) {
    input >> ponto.x;
    input >> ponto.y;

    return input;
}
