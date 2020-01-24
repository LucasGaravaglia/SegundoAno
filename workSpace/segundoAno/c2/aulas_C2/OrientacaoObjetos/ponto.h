#ifndef PONTO_H
#define PONTO_H

#include <iostream>
using  namespace std;

class Ponto {
private:
    double x;
    double y;
public:
    Ponto ();
    Ponto( double x, double y );
    void setx ( double x );
    void sety ( double y );
    double getx ( );
    double gety ( );

         void show ();

    void moveto ( double x, double y );
    void moveto ( const Ponto &other );

    // Sobrecarga de operadores
    void operator+=(const Ponto&other);
    Ponto operator+(const Ponto&other);

    friend ostream &operator<< (ostream &output, const Ponto &ponto);
    friend istream &operator>> (istream &input, Ponto &ponto);

    ~Ponto();
};

#endif // PONTO_H
