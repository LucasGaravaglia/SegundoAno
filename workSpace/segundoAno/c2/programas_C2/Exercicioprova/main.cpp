#include <iostream>
#include "carro.h"

using namespace std;

int main(){
    Carro *carro = new Carro();

    try{
        carro->abastecer(3);
        carro->mover(50);
    }catch(const char* s){
        cerr << s;
    }

    cout << "Combustivel : " << carro->getcomb() << endl;
    cout << "Distancia : " << carro->getkm() << endl;

delete carro;

    return 0;
}
