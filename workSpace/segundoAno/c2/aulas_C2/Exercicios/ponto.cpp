#include "ponto.h"

#include <math.h>

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

Ponto::Ponto( const Ponto &other ) {
    this->x = other.x;
    this->y = other.y;
}

void Ponto::moveto ( ) {
    this->x = 0;
    this->y = 0;
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

void Ponto::operator=(const Ponto&other) {
    cout << "usando sobrecarga"<< endl;
    this->x = other.x;
    this->y = other.y;
}

bool Ponto::equals ( const Ponto &other ) {
    return (this->x==other.x) &&
           (this->y==other.y);
}

double Ponto::distance ( const Ponto &other ) {
    return sqrt(
                pow(other.x-this->x,2)
                +
                pow(other.y-this->y,2)
                );
}

Ponto *Ponto::clone() {
    return new Ponto ( *this );
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
