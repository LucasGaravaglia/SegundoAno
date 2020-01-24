#ifndef AIRTRANSPORT_H
#define AIRTRANSPORT_H
#include "transporte.h"


class AirTransport : public Transporte{
private:
    int range;
    double wingspan;
public:
    AirTransport();
    void show();
    void setrange(int range);
    void setwingspan(double wingspan);
    int getrange();
    double getwingspan();
};

#endif // AISTRANSPORT_H
