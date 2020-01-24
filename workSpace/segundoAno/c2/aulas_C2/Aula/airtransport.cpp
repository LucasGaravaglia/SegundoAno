#include "airtransport.h"

AirTransport::AirTransport(){

}
void AirTransport::show(){

}
void AirTransport::setrange(int range){
    this->range = range;
}
void AirTransport::setwingspan(double wingspan){
    this->wingspan = wingspan;
}
int AirTransport::getrange(){
    return this->range;
}
double AirTransport::getwingspan(){
    return this->wingspan;
}
