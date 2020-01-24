#include "lista.h"

using namespace std;

Lista::Lista(int n){
    this->n = n;
    this->prox = NULL;
}
Lista* Lista::InsereInicio(int n){
    Lista *aux;
    aux = new Lista(n);
    aux->prox = this;
    return aux;
}/*
Lista Lista::*InsereFim(int n){

}
Lista Lista::*InsereOrdenar(int n);
*/
void Lista::mostrar(){
    cout << n << endl;
    if(this->prox){
        this->prox->mostrar();
    }
}
/*Lista::~Lista();*/
