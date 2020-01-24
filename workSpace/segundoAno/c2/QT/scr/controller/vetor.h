#ifndef VETOR_H
#define VETOR_H

#include <QVector>

class Vetor{
private:
    QVector<int> *v;
public:
    Vetor();
    void add(int n);
    void show();
    ~Vetor();
};

#endif // VETOR_H
