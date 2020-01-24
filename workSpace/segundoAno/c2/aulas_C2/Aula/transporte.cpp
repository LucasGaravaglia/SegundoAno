#include "transporte.h"

Transporte::Transporte(){

}
int Transporte::Compareto(Comparable *other){
    Transporte *t = (Transporte*)other;
    if(this->speed < t->speed) return -1;
    if(this->speed > t->speed) return 1;
    return 0;
}
void Transporte::setnome(QString nome){
    this->nome = nome;
}
void Transporte::setheight(double height){
    this->height = height;
}
void Transporte::setpayload(int payload){
    this->payload = payload;
}
void Transporte::setspeed(int speed){
    this->speed = speed;
}
QString Transporte::getnome(){
    return this->nome;
}
double Transporte::getheight(){
    return this->height;
}
int Transporte::getpayload(){
    return this->payload;
}
int Transporte::getspeed(){
    return this->speed;
}
