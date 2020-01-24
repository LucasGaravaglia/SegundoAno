#include <iostream>

using namespace std;

#include "pessoa.h"

#include "ponto.h"

#include "funcionario.h"



int main() {

    Ponto p1 (10,11);
    Ponto p2 (12,13);
    Ponto p3;

    cin >> p3;
    cout << "P1: " << p1 << endl;
    cout << "P2: " << p2 << endl;
    cout << "P3: " << p3 << endl;

    p1 += p2;
    cout << "P1+=P2: " << p1 << endl;

    p3 = p1 + p2;
    cout << "P3=P1+P2: " << p3 << endl;

    return 0;
}
