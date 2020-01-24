#ifndef CONTADOR_H
#define CONTADOR_H


class Contador {
private:
    int contador;
public:
    Contador();
    void zerar();
    void incrementar();
    int getContador();
    ~Contador();
};

#endif // CONTADOR_H
