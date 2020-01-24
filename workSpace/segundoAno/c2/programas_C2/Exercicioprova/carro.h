#ifndef CARRO_H
#define CARRO_H


class Carro{

private:
    double km;
    double comb;
public:
    Carro();
    void abastecer(double comb);
    void mover(double km);
    double getkm();
    double getcomb();
    ~Carro();
};

#endif // CARRO_H
