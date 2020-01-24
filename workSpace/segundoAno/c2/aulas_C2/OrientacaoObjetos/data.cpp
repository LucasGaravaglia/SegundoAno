#include "data.h"
#include "string.h"

#include <iostream>
#include <string>
using namespace std;


Data::Data() {
    dia = 0;
    mes = 0;
    ano = 0;
}

Data::Data ( int dia, int mes, int ano ) {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

void Data::setDia ( int dia ) {
    this->dia = dia;
}

void Data::setMes ( int mes ) {
    this->mes = mes;
}

void Data::setAno ( int ano ) {
    this->ano = ano;
}

int Data::getDia () {
    return dia;
}

int Data::getMes () {
    return mes;
}

int Data::getAno () {
    return ano;
}

bool Data::isAnoBissexto() {
    return ((ano % 4 == 0) &&
            (ano %100 != 0)) ||
            (ano % 400==0);
}

bool Data::isDataValida () {
    switch (mes) {
    // meses com 31 dias
    case 1:;
    case 3:;
    case 5:;
    case 7:;
    case 8:;
    case 10:;
    case 12: return (dia>0) && (dia<=31);
    case 4:;
    case 6:;
    case 9:;
    case 11: return (dia>0) && (dia<=30);
    case 2 : {
        if (isAnoBissexto()) {
            return (dia>0) && (dia<=29);
        } else {
            return (dia>0) && (dia<=28);
        }
    }
    default : return false;
    }
}

char * Data::toString() {

    return "";
}

void Data::setar() {
    cin >> dia;
    cin >> mes;
    cin >> ano;
}

void Data::mostrar() {
    cout << dia << "/"
         << mes << "/"
         << ano;
}


const string Data::dias_percorridos (
        const Data &other ) {

    string s="";
    char n[10];

    int anos=0, meses=0, dias=0;
    if (ano<=other.ano) {
        anos = other.ano-ano;
        if (other.mes<mes) {
            anos--;
            meses = 12 - mes + other.mes;
        } else {
            meses = other.mes-mes;
        }
        if (other.dia<dia) {
            meses--;
            dias = 30 - dia + other.dia;
        } else {
            dias = other.dia - dia;
        }

        if (anos>=0 && meses>=0 && dias>=0) {
            // Anos
            s += std::to_string(anos);
            s += " anos ";

            // Meses
            s +=  std::to_string(meses);
            s += " meses ";

            // Dias
            s += std::to_string(dias);
            s += " dias ";

            return s;
        }
    }
    return "Data inicial menor que a final";

}


/*

const char *Data::dias_percorridos (
         const Data &other ) {
    char s[100]; s[0] = '\0';
    char n[10];

    int dias1 = this->dia +
            this->mes*30 +
            this->ano*365;
    int dias2 = other.dia +
            other.mes*30 +
            other.ano*365;


    if (dias2>dias1) {
        // Anos
        int diff = dias2 - dias1;
        itoa( diff / 365, n,10);
        strcat ( s, n);
        strcat ( s, " anos ");

        // Meses
        diff %= 365;
        itoa( diff / 30, n,10);
        strcat ( s, n);
        strcat ( s, " meses ");

        // Dias
        diff %= 30;
        itoa( diff, n,10);
        strcat ( s, n);
        strcat ( s, " dias ");
        cout << s;
        return s;
    } else
        return "Inicial menor que a final";

    return s;
}*/


Data::~Data() {


}
