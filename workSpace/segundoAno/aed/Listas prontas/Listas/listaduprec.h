#ifndef LISTADUPREC_H
#define LISTADUPREC_H

typedef struct no {
    int info;
    struct no *ant;
    struct no *prox;
} Lista;

Lista* inseredupRec(Lista* l, int info);
Lista* RemoveUnicoDupRec(Lista *l,int info);
Lista* UltimoElementoListaRec(Lista *l);
Lista* InverteDupRec(Lista* l);
Lista* ConcatListDupRec(Lista *l1, Lista *l2);
Lista* MergeDupRec(Lista *l1, Lista *l2);


#endif // LISTADUPREC_H
