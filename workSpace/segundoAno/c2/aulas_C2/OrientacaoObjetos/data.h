#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;


class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    // Sobrecarga de construtores
    Data();
    Data ( int dia, int mes, int ano );
    // Setters
    void setDia ( int dia );
    void setMes ( int mes );
    void setAno ( int ano );

    // Getters
    int getDia ();
    int getMes ();
    int getAno ();

    bool isAnoBissexto();
    bool isDataValida ();
    char * toString();

    void setar();
    void mostrar();

    const string dias_percorridos(
            const Data &other );

    ~Data();
};

#endif // DATA_H
