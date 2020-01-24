#include "vetor.h"
#include <iostream>

using namespace std;

Vetor::Vetor(){
    v = new QVector<int>();
}
void Vetor::add(int n){
    v->append(n);
}
void Vetor::show(){
    cout << "Elementos do vetor" << endl;
    for(int i=0;i<v;i++){
        cout << v <<endl;
    }
}
Vetor::~Vetor(){
    cout << "Destruindo elemento << endl;"

}
