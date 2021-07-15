#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <sort/quicksort.h>

class QuickSort : public BaseSort {
public:
    QuickSort();

    QList<QList<int>> sort(QList<int> array) override;
};

#endif // QUICKSORT_H
