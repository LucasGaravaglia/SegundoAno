#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"

class Circulo : public Ponto {
private:
    double raio;
public:
    Circulo( double x, double y, double raio );
    void aumentar();
    void diminuir();
    void show();
    ~Circulo();
};

#endif // CIRCULO_H
