#ifndef RETA_H
#define RETA_H

#include "ponto.h"

// Reta y = ax + b
class Reta {
private:
    double a;  // Coeficiente angular
    double b;  // Coeficiente linear
public:
    Reta( double a, double b );
    Reta( Ponto &p1, Ponto &p2 );
    double getA();
    double getB();

    bool pertence ( Ponto &p );
    Ponto *intercepta (const Reta &other );

    ~Reta();
};

#endif // RETA_H
