#include "pessoa.h"


#include <iostream>
using namespace std;

Pessoa::Pessoa ( string nome,
                 Pessoa *pai, Pessoa *mae ) {
    this->nome = nome;
    this->pai  = pai;
    this->mae  = mae;
}

bool Pessoa::equals (Pessoa *other ) {
    if (other==NULL) {
        return false;
    }
    // Se não informada a mãe
    if ((this->mae==NULL)|| (other->mae==NULL)) {
        return this->nome.compare(other->nome)==0;
    }
    // Se possui mãe
    return (this->nome.compare(other->nome)==0) &&
        (this->mae->nome.compare(other->mae->nome)==0);
}

bool Pessoa::irmaos ( Pessoa *other ) {
    return (!this->equals(other)) &&
           ((this->mae!=NULL &&
            this->mae->equals(other->mae)) ||
            (this->pai!=NULL &&
             this->pai->equals(other->pai)));
}

bool Pessoa::ancestral ( Pessoa *other ) {
    if (this->equals(other)) {
        return true;
    }
    bool b_ret=false;
    if (this->pai) { // if (this->pai != NULL)
        b_ret = this->pai->ancestral(other);
    }
    if (!b_ret && this->mae) {
        b_ret = this->mae->ancestral(other);
    }
    return b_ret;
}

Pessoa::~Pessoa() {
    cout << "Destruinto pessoa" << endl;
}
