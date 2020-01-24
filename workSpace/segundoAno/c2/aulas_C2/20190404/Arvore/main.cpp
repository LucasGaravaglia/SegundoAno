#include <iostream>

using namespace std;

#include "contador.h"

#include "ponto.h"
#include "pessoa.h"

int main(){/*
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

    Contador *c = new Contador();

   cout << "Contador: "
        << c->getContador()
        << endl;

   c->incrementar();

   cout << "Contador: "
        << c->getContador()
        << endl;


   delete c;
*/

    Pessoa *pessoa1, *pancestral,*pessoa2;
    Pessoa *p1, *p2;
    Pessoa *eu, *irmao, *meioirmao;

    p1 =    new Pessoa("Andre",
            new Pessoa("Luiz"),
            new Pessoa ("Marta"));
    p2 =    new Pessoa("Helena",
            new Pessoa("Jorge"),
            new Pessoa ("Julia"));

    pessoa1 = new Pessoa("Monica",p2,p1);
    pancestral = new Pessoa("Eduardo");


    p1 =    new Pessoa("Habib",
            new Pessoa("Alex"),
            new Pessoa ("Sofia"));

    p2 =    new Pessoa("Ana",
            pancestral,
            new Pessoa ("Lucia"));

    pessoa2 = new Pessoa ("Pedro",p2,p1);

    eu = new Pessoa ("Lucas",pessoa2,pessoa1);
    irmao = new Pessoa("Maria",pessoa2,pessoa1);
    meioirmao = new Pessoa ("Alison",pessoa2);

    cout << "Irmao: " << eu->irmaos(irmao) << endl;
    cout << "Irmao: " << eu->irmaos(meioirmao) << endl;
    cout << "Imaor: " << eu->irmaos(pessoa2) << endl;
    cout << "ancestral: " << eu->ancestral(irmao) << endl;




    return 0;
}
