#include "lista2.h"
#include <iostream>

using namespace std;

Lista2::Lista2(int n,Lista2 prox){
    this->n = n;
    this->prox = prox;
}

void Lista2::InsereInicio(Lista2 **h, int n){
    *h = new Lista2(n,*h);
}
NULL
nullptr
