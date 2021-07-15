#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <sort/basesort.h>

class SelectionSort : public BaseSort{
public:
    SelectionSort();

     QList<QList<int>> sort(QList<int> array) override;
};

#endif // SELECTIONSORT_H
