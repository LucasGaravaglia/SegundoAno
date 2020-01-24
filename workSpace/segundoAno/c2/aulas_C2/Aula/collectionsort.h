#ifndef COLLECTIONSORT_H
#define COLLECTIONSORT_H
#include <QVector>
#include "comparable.h"

class CollectionSort
{
public:
    static void selectionSort( QVector<Comparable*> *vector);
};

#endif // COLLECTIONSORT_H
