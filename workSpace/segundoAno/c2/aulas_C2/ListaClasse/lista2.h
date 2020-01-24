#ifndef LISTA2_H
#define LISTA2_H


class Lista2{
private:
    int n;
    Lista2 *prox;
    Lista2(int n,int prox);
public:
    static void InsereInicio(Lista2 **h,int n);
    static void InsereFim(Lista2 **h,int n);
    static void InsereOrdenado(Lista2 **h,int n);
    void mostrar();
    ~Lista2();
};

#endif // LISTA2_H
