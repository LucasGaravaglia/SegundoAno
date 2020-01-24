#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa{
private:
    string nome;
    Pessoa *pai;
    Pessoa *mae;
public:
    Pessoa(string nome, Pessoa *pai=NULL, Pessoa *mae=NULL); //Quando atribui valor a variavel na função ela fica opcional ser colcoada.
    bool equals(Pessoa *other);
    bool irmaos(Pessoa *other);
    bool ancestral(Pessoa *other);
    ~Pessoa();
};

#endif // PESSOA_H