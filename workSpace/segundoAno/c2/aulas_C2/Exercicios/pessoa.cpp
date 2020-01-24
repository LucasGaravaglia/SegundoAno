#include "pessoa.h"



Pessoa::Pessoa(string nome, Pessoa *pai, Pessoa *mae){
    this->nome = nome;
    this->pai = pai;
    this->mae = mae;
}
bool Pessoa::equals(Pessoa *other){
    if(other == NULL)
        return false;
    if((this->mae == NULL) || (other->mae == NULL))
        return this->nome.compare(other->nome) == 0;
    return ((this->nome.compare(other->nome) == 0) &&
            (this->mae->nome.compare(other->mae) == 0));
}

bool Pessoa::irmaos(Pessoa *other){
    return (!this->equals(other)) &&
            (this->mae!=NULL &&
             this->mae->equals(other->mae) ||
            (this->pai!=NULL &&
             this->pai->equals(other->pai)));

}
bool Pessoa::ancestral(Pessoa *other){
    if(this->equals(other))
        return true;
    bool b_ret = false;
        if(this->pai)
            b_ret= this->pai->ancestral(other);
        if(!b_ret && this->mae){
            b_ret= this->mae->ancestral(other);
        }
}

Pessoa::~Pessoa(){
    cout << "Destrui" << endl;
}

