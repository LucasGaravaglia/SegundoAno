#include "reta.h"

#include <iostream>

using namespace std;

Reta::Reta( double a, double b  ) {
    this->a = a;
    this->b = b;
}

Reta::Reta( Ponto &p1, Ponto &p2 ) {
    this->a = (p2.gety()-p1.gety()) /
              (p2.getx()-p1.getx());

    this->b = p1.gety() - this->a * p1.getx();
}

double Reta::getA() {
    return this->a;
}

double Reta::getB() {
    return this->b;
}

bool Reta::pertence ( Ponto &p ) {
    return p.gety()==(this->a*p.getx()+this->b);

    /*
    double c = p->gety() -
               this->coeficienteAngular*p->getx();
       return c==this->coeficienteLinear;
       */
}

Ponto *Reta::intercepta ( const Reta &other ) {
    Ponto *p=NULL;
    if (this->a!=other.a) {
        double x = (this->a - other.a)/
                   (this->b - other.b);

        double y = x * other.a + this->b;

        p = new Ponto( x, y );
    }
    return p;
}

Reta::~Reta() {
    cout << "Destruindo reta" << endl;
}
