#include "carro.h"
#include <iostream>


using namespace std;
Carro::Carro(){
    this->km = 0;
    this->comb = 0;
}
void Carro::abastecer(double litros){
    if((this->comb+litros) > 50){
        this->comb = 50;
        throw "Atingiu o limite do tanque!\n";
    }else{
        this->comb  += litros;
    }
}
void Carro::mover(double km){
    if(km/15 <= this->comb){
        this->km += km;
        this->comb -= (km/15);
    } else {
        this->km += (this->comb*15);
        this->comb = 0;
        throw "Combustivel insuficiente!\n";
    }
}
double Carro::getkm(){
    return this->km;
}
double Carro::getcomb(){
    return this->comb;
}
Carro::~Carro(){
    cout << "Destruido." << endl;
}
