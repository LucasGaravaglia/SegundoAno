#ifndef TRANSPORTE_H
#define TRANSPORTE_H
#include "comparable.h"
#include <QString>


class Transporte : public  Comparable{
private:
    QString nome;
    double height;
    int payload;
    int speed;
public:
    virtual void show()=0;
    int Compareto(Comparable *other);
    void setnome(QString nome);
    void setheight(double height);
    void setpayload(int payload);
    void setspeed(int speed);
    QString getnome();
    double getheight();
    int getpayload();
    int getspeed();
    Transporte();
    ~Transporte();
};

#endif // TRANSPORTE_H
