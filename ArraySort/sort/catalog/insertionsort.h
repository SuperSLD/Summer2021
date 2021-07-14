#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <sort/basesort.h>

class InsertionSort : public BaseSort
{
public:
    InsertionSort();

     QList<QList<int>> sort(QList<int> array) override;
};

#endif // INSERTIONSORT_H
