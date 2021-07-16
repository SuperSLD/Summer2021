#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <sort/basesort.h>


class QuickSort : public BaseSort {
public:
    QuickSort();

    QList<QList<int>> sort(QList<int> array) override;

    void qsortRecursive(QList<QList<int>> *steps, int *fullMass, int *numbers, int left, int right);
};

#endif // QUICKSORT_H
