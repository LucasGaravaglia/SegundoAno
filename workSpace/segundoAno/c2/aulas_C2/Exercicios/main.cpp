#include <iostream>

using namespace std;

#include "contador.h"

#include "ponto.h"

int main()
{
    Ponto *p1 = new Ponto(20,21);

    cout << "P1" << *p1 << endl;

    cout << "P1" << *p1 << endl;

    Ponto *p2 = new Ponto ();

    cout << "P2" << *p2 << endl;
    cout << "P1.equals(P2) "
         <<  p1->equals(*p2)
         << endl;
    cout << "P1.dist(P2) "
         << p1->distance( *p2 )
         << endl;



    delete p1;
    delete p2;

    /*Contador *c = new Contador();

   cout << "Contador: "
        << c->getContador()
        << endl;

   c->incrementar();

   cout << "Contador: "
        << c->getContador()
        << endl;


   delete c;
*/
    return 0;
}
