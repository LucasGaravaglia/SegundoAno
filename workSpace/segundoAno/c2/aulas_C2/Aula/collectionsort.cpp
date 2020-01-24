#include "collectionsort.h"


void CollectionSort::selectionSort( QVector<Comparable*> *vector){
    int i,j;
    int k;
    Comparable *aux;

    for(i=0;i<vector->size();i++){
        k = i;
        for(j = i+1;j<vector->size();j++)
            if(vector->at(k)->Compareto(vector->at(j)) > 0)
                k = j;
        aux = vector->at(i);
        (*vector) [i] = vector->at(k);
        (*vector) [k] = aux;
    }
}
