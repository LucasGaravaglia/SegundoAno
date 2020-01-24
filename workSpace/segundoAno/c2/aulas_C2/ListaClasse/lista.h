#ifndef LISTA_H
#define LISTA_H

#include <iostream>
class Lista{
private:
    int n;
    Lista *prox;
public:
    Lista(int n);
    Lista *InsereInicio(int n);
    Lista *InsereFim(int n);
    Lista *InsereOrdenar(int n);
    void mostrar();
    ~Lista();
};

#endif // LISTA_H
