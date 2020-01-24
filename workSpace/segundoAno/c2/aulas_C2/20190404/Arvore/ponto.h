#ifndef PONTO_H
#define PONTO_H

#include <iostream>
using namespace std;

class Ponto {
private:
    double x;
    double y;
public:
    Ponto ();
    Ponto( double x, double y );
    Ponto( const Ponto &other );

    void setx ( double x );
    void sety ( double y );
    double getx ( );
    double gety ( );

    virtual void show ();

    void moveto ( );
    void moveto ( double x, double y );
    void moveto ( const Ponto &other );

    bool equals ( const Ponto &other );

    double distance ( const Ponto &other );

    Ponto *clone();

    // Sobrecarga de operadores
    void operator=(const Ponto&other);
    void operator+=(const Ponto&other);
    Ponto operator+(const Ponto&other);

    friend ostream &operator<< (ostream &output, const Ponto &ponto);
    friend istream &operator>> (istream &input, Ponto &ponto);

    ~Ponto();
};

#endif // PONTO_H
